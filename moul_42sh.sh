#!/bin/sh

DEBUG=0
PIPE=pipe
OUT=out
SHELL="./42sh"
MKFIFO=`which mkfifo`
TAIL=`which tail`

debug()
{
  if [ $DEBUG -eq 1 ]
  then
    echo $* 1>&2
  fi
}

launch_shell()
{
  $MKFIFO $PIPE
  cp $TAIL mytail 2>&1 >/dev/null
  (./mytail -f $PIPE 2>/dev/null | $SHELL 2>&1 > $OUT &) >/dev/null 2>/dev/null
}

kill_shell()
{
  if [ `pidof $SHELL | wc -l` -ne 0 ]
  then
    killall -9 $SHELL 2>&1 > /dev/null
  fi
  if [ `pidof mytail | wc -l` -ne 0 ]
  then
    killall mytail 2>&1 > /dev/null
  fi
  rm -f $PIPE $OUT 2>&1 > /dev/null
}

clean()
{
  rm -f $PIPE $OUT mytail 2>&1 > /dev/null
}

test01()
{
  kill_shell 2>&1 > /dev/null
  launch_shell 2>&1 > /dev/null
  touch "tmp.$$"

  # Envoi des commandes
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "ls" > $PIPE
  fi


  # attente de l'execution des commandes
  sleep 0.5

  # Récuparation du résultat
  cat $OUT | grep "tmp.$$" 2>&1 >/dev/null
  if [ $? -eq 0 ]
  then
    echo -n "OK "
  else
    echo -n "KO "
  fi

  rm -f tmp.$$ 2>&1 > /dev/null
}

test02()
{
  kill_shell 2>&1 > /dev/null
  launch_shell 2>&1 > /dev/null
  touch "tmp.$$"

  # Envoi des commandes
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "ls -la" > $PIPE
  fi


  # attente de l'execution des commandes
  sleep 0.5

  # Récuparation du résultat
  cat $OUT | grep "tmp.$$" 2>&1 >/dev/null
  if [ $? -eq 0 ]
  then
    echo -n "OK "
  else
    echo -n "KO "
  fi

  rm -f tmp.$$ 2>&1 > /dev/null
}

test03()
{
  kill_shell 2>&1 > /dev/null
  launch_shell 2>&1 > /dev/null
  touch "tmp.$$"

  # Envoi des commandes
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "/bin/ls -la" > $PIPE 
  fi

  # attente de l'execution des commandes
  sleep 0.5

  # Récuparation du résultat
  cat $OUT | grep "tmp.$$" 2>&1 >/dev/null
  if [ $? -eq 0 ]
  then
    echo -n "OK "
  else
    echo -n "KO "
  fi

  rm -f tmp.$$ 2>&1 > /dev/null
}

test04()
{
  kill_shell 2>&1 > /dev/null
  launch_shell 2>&1 > /dev/null
  touch "tmpx.$$"

  # Envoi des commandes
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "/ls" > $PIPE
  fi


  # attente de l'execution des commandes
  sleep 0.5

  # Récuparation du résultat
  cat $OUT | grep "tmpx.$$" 2>&1 >/dev/null
  if [ $? -eq 0 ]
  then
    echo -n "KO "
  else
    echo -n "OK "
  fi

  rm -f tmpx.$$ 2>&1 > /dev/null
}

test05()
{
  kill_shell 2>&1 > /dev/null
  OLDPATH="$PATH"
  PATH=""
  launch_shell 2>&1 > /dev/null
  PATH="$OLDPATH"
  touch "tmp.$$"

  # Envoi des commandes
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "/bin/ls" > $PIPE
  fi

  # attente de l'execution des commandes
  sleep 0.5

  # Récuparation du résultat
  cat $OUT | grep "tmp.$$" 2>&1 >/dev/null
  if [ $? -eq 0 ]
  then
    echo -n "OK "
  else
    echo -n "KO "
  fi

  rm -f tmp.$$ 2>&1 > /dev/null
}

test06()
{
  kill_shell 2>&1 > /dev/null
  OLDPATH=$PATH
  PATH="/bin"
  launch_shell 2>&1 > /dev/null
  PATH=$OLDPATH
  touch "tmp.$$"

  # Envoi des commandes
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "/bin/ls" > $PIPE
  fi

  # attente de l'execution des commandes
  sleep 0.5

  # Récuparation du résultat
  cat $OUT | grep "tmp.$$" 2>&1 >/dev/null
  if [ $? -eq 0 ]
  then
    echo -n "OK "
  else
    echo -n "KO "
  fi

  rm -f tmp.$$ 2>&1 > /dev/null
}

test07()
{
  kill_shell 2>&1 > /dev/null
  OLDPATH=$PATH
  PATH=":/bin"
  launch_shell 2>&1 > /dev/null
  PATH=$OLDPATH
  touch "tmp.$$"

  # Envoi des commandes
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "/bin/ls" > $PIPE
  fi

  # attente de l'execution des commandes
  sleep 0.5

  # Récuparation du résultat
  cat $OUT | grep "tmp.$$" 2>&1 >/dev/null
  if [ $? -eq 0 ]
  then
    echo -n "OK "
  else
    echo -n "KO "
  fi

  rm -f tmp.$$ 2>&1 > /dev/null
}

test08()
{
  kill_shell 2>&1 > /dev/null
  OLDPATH=$PATH
  PATH="/bin:"
  launch_shell 2>&1 > /dev/null
  PATH=$OLDPATH
  touch "tmp.$$"

  # Envoi des commandes
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "/bin/ls" > $PIPE
  fi

  # attente de l'execution des commandes
  sleep 0.5

  # Récuparation du résultat
  cat $OUT | grep "tmp.$$" 2>&1 >/dev/null
  if [ $? -eq 0 ]
  then
    echo -n "OK "
  else
    echo -n "KO "
  fi

  rm -f tmp.$$ 2>&1 > /dev/null
}

test09()
{
  kill_shell 2>&1 > /dev/null
  OLDPATH=$PATH
  PATH="/bin:"
  launch_shell 2>&1 > /dev/null
  PATH=$OLDPATH
  touch "tmp.$$"
  cp /bin/ls myls

  # Envoi des commandes
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "myls" > $PIPE
  fi

  # attente de l'execution des commandes
  sleep 0.5

  # Récuparation du résultat
  cat $OUT | grep "tmp.$$" 2>&1 >/dev/null
  if [ $? -eq 0 ]
  then
    echo -n "KO "
  else
    echo -n "OK "
  fi

  rm -f mysl 2>&1 > /dev/null
  rm -f tmp.$$ 2>&1 > /dev/null
}

test10()
{
  kill_shell 2>&1 > /dev/null
  OLDPATH=$PATH
  PATH="/bin:"
  launch_shell 2>&1 > /dev/null
  PATH=$OLDPATH
  touch "tmp.$$"
  cp /bin/ls myls

  # Envoi des commandes
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "./myls" > $PIPE
  fi

  # attente de l'execution des commandes
  sleep 0.5

  # Récuparation du résultat
  cat $OUT | grep "tmp.$$" 2>&1 >/dev/null
  if [ $? -eq 0 ]
  then
    echo -n "OK "
  else
    echo -n "KO "
  fi

  rm -f tmp.$$ 2>&1 > /dev/null
}

test11()
{
  kill_shell 2>&1 > /dev/null
  launch_shell 2>&1 > /dev/null
  touch "tmp.$$"
  cp /bin/ls myls

  # Envoi des commandes
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "setenv toto" > $PIPE
  fi
  sleep 0.2
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "setenv tata coucou" > $PIPE
  fi
  sleep 0.2
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "env" > $PIPE
  fi
  sleep 0.2
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "setenv titi abcd" > $PIPE
  fi
  sleep 0.2
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "unsetenv tata" > $PIPE
  fi
  sleep 0.2
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "env" > $PIPE
  fi


  # attente de l'execution des commandes
  sleep 0.5

  # Récuparation du résultat
  a=`cat $OUT | grep "tata" | grep "coucou" | wc -l`
  b=`cat $OUT | grep "titi" | grep "abcd" | wc -l`
  c=`cat $OUT | grep "toto" | wc -l`

  echo "a=$a==1 ; b=$b==1 ; c=$c==2"
  if [ $a -eq 1 -a $b -eq 1 -a $c -eq 2 ]
  then
    echo -n "OK "
  else
    echo -n "KO "
  fi

  rm -f tmp.$$ myls 2>&1 > /dev/null
}

test12()
{
  kill_shell 2>&1 > /dev/null
  launch_shell 2>&1 > /dev/null
  touch "tmp.$$"
  cp /bin/ls myls

  echo -e "\ntest cd :"
  # Envoi des commandes
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
      echo "mkdir plopplop"
      echo "mkdir plopplop" > $PIPE
      echo -e "$PIPE"
  fi
  sleep 0.2
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "cd plopplop"
    echo "cd plopplop" > $PIPE
    echo $PIPE
  fi
  sleep 0.2
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "pwd"
    echo "pwd" > $PIPE
    echo $PIPE
  fi
  sleep 0.2
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
      echo "cd -"
      echo "cd -" > $PIPE
      echo $PIPE
  fi
  sleep 0.2
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
      echo "pwd"
      echo "pwd" > $PIPE
      echo $PIPE
  fi
  sleep 0.2
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
      echo "cd /"
      echo "cd /" > $PIPE
      echo $PIPE
  fi
  sleep 0.2
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
      echo "ls"
      echo "ls" > $PIPE
      echo $PIPE
  fi

  echo '$OUT is filed with:'
  cat $OUT
  echo
  echo -e '\ncat $OUT | grep plopplop | wc -l\n'
  cat $OUT | grep "plopplop" | wc -l
  echo
  echo -e '\ncat $OUT | grep usr | wc -l\n'
  cat $OUT | grep "usr" | wc -l
  echo

  # attente de l'execution des commandes
  sleep 0.5

  # Récuparation du résultat
  a=`cat $OUT | grep "plopplop" | wc -l`
  b=`cat $OUT | grep "usr" | wc -l`

  if [ $a -eq 1 -a $b -eq 1 ]
  then
    echo -n "OK "
  else
    echo -n "KO "
  fi

  rm -Rf plopplop 2>&1 > /dev/null
  rm -f tmp.$$ 2>&1 > /dev/null
}

test13()
{
  kill_shell 2>&1 > /dev/null
  launch_shell 2>&1 > /dev/null
  touch "tmp.$$"
  cp /bin/ls myls

  # Envoi des commandes
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "exit 42" > $PIPE
  fi
  # attente de l'execution des commandes
  sleep 0.5

  # Récuparation du résultat
  a=`ps aux | grep mysh | grep -v grep | grep -v moul_ | wc -l`

  if [ $a -eq 0 ]
  then
    echo -n "OK "
  else
    echo -n "KO "
  fi

  rm -f tmp.$$ 2>&1 > /dev/null
}

test14()
{
  kill_shell 2>&1 > /dev/null
  launch_shell 2>&1 > /dev/null
  touch "tmp.$$"
  cp /bin/ls myls

  # Envoi des commandes
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "echo toto" > $PIPE
  fi
  sleep 0.2
  if [ `pidof $SHELL | wc -l` -eq 1 ]
  then
    echo "echo $USER" > $PIPE
  fi
  sleep 0.2

  # attente de l'execution des commandes
  sleep 0.5

  # Récuparation du résultat
  a=`cat $OUT | grep "toto" | wc -l`
  b=`cat $OUT | grep "$USER" | wc -l`

  if [ $a -eq 1 -a $b -eq 1 ]
  then
    echo -n "OK "
  else
    echo -n "KO "
  fi

  rm -f tmp.$$ 2>&1 > /dev/null
}

all_test()
{

echo -n "Simple exec : "
test01 # ls
test02 # ls -la
test03 # /bin/ls -la
test04 # /ls
echo ""

echo -n "Change the PATH : "
test05 # PATH="" - mysh - /bin/ls
test06 # PATH="/bin" - mysh - /bin/ls
test07 # PATH=":/bin" - mysh - /bin/ls
test08 # PATH="/bin:" - mysh - /bin/ls
test09 # PATH="/bin" - mysh - mysh
test10 # PATH="/bin" - mysh - ./mysh
echo ""

echo -n "Builtins : "
test11 # setenv et unsetenv
#test12 # cd
test13 # exit
test14 # echo
echo ""

}

all_test

kill_shell
clean
