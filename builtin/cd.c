/*
** cd.c for cd in /home/rouss_p/rendu/42
** 
** Made by pierre rousselle
** Login   <rouss_p@epitech.net>
** 
** Started on  Fri Apr 24 11:19:58 2015 pierre rousselle
** Last update Sat May 23 16:27:59 2015 Adrien Blanquer
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin.h"
#include "lib.h"

int	my_cd_error(char *str)
{
  fprintf(stderr, "%s\n", str);
  return (FAILURE);
}

char	*get_new_pwd(char *pwd, char *path)
{
  char	*buffer;
  char	*bufpath;
  int	i;

  bufpath = path;
  if (path[0] == '/')
    return (my_cstrconcat("PWD=", path));
  while ((buffer = strtok(bufpath, "/")) != NULL)
    {
      if (my_strcmp(buffer, "..") == 0)
        {
          i = my_strlen(pwd) - 1;
          if (pwd[i] == '/' && i > 0)
            --i;
          while (pwd[i] != '/' && i > 0)
	    pwd[i--] = '\0';
        }
      else if (my_strcmp(buffer, ".") != 0)
        if ((pwd = my_cstrconcat(pwd,
				 (pwd[my_strlen(pwd) - 1] == '/' ? buffer :
				       my_cstrconcat("/", buffer)))) == NULL)
          return (NULL);
      bufpath = NULL;
    }
  return (my_cstrconcat("PWD=", pwd));
}

int	set_pwd_old_pwd(char **env, char *path)
{
  int	offsetpwd;
  int	offsetold;
  char	*pwd;
  char	*oldpwd;

  if ((pwd = get_env_value(env, "PWD", &offsetpwd)) == NULL
      || get_env_value(env, "OLDPWD", &offsetold) == NULL
      || (oldpwd = malloc(8 + my_strlen(pwd))) == NULL
      || my_strcpy(oldpwd, "OLDPWD=") == NULL
      || (oldpwd = my_cstrconcat(oldpwd, pwd)) == NULL)
    return (FAILURE);
  env[offsetold] = oldpwd;
  if ((pwd = get_new_pwd(pwd, path)) == NULL)
    return (FAILURE);
  env[offsetpwd] = my_strdup(pwd);
  return (SUCCESS);
}

int	my_cd(char **expr, t_data *data)
{
  char	*homevalue;
  char	*path;
  int	ret;

  if (!expr[1] || expr[1][0] == '~')
    {
      if ((homevalue = get_env_value(data->env, "HOME", NULL)) == NULL)
	return (my_cd_error("cd: No home directory."));
      if (!expr[1])
	path = homevalue;
      else if (expr[1][0] == '~')
	if ((path = my_cstrconcat(homevalue, expr[1] + 1)) == NULL)
	  return (FAILURE);
    }
  else if (expr[1][0] == '-'
	   && (path = get_env_value(data->env, "OLDPWD", NULL)) == NULL)
    return (my_cd_error("Env var $OLDPWD is not set."));
  else if (expr[1][0] != '-')
    path = expr[1];
  if ((ret = chdir(path)) != 0)
    return (my_cd_error("No such file or directory."));
  set_pwd_old_pwd(data->env, path);
  return (SUCCESS);
}
