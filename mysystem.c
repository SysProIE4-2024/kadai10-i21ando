/*
 *  mysystem.c : system 関数のクローン
 */

#include <stdio.h>
#include <stdlib.h>    // exit, system のため
#include <unistd.h>    // fork, execXX のため
#include <sys/wait.h>  // wait のため
#include "mysystem.h"  // インタフェース
char *execpath = "/bin/sh";
// system関数のクローン
int mysystem(char *command) {
  int status = 0;

  // ここにプログラムを書く
  if(command == NULL) {
    return 1;
  }
  int pid;
  if((pid=fork()) < 0) {
    return -1;
  }
  if(pid != 0) {
    while(wait(&status) != pid);
  } else {
    execl(execpath, "sh", "-c", command, NULL);
    perror(execpath);
    exit(127);
  }
   return status;
}

/* 実行例

ここに実行例を書く
% ls -l       
total 616
-rw-r--r--  1 andotakuma  staff     143  7  4 09:44 Makefile
-rw-r--r--  1 andotakuma  staff    2795  7  4 09:44 README.md
-rw-r--r--  1 andotakuma  staff  238232  7  4 09:44 README.pdf
-rwxr-xr-x  1 andotakuma  staff   50406  7  4 10:16 mysysmain
-rw-r--r--  1 andotakuma  staff     925  7  4 09:44 mysysmain.c
-rw-r--r--  1 andotakuma  staff    1755  7  4 10:20 mysystem.c
-rw-r--r--  1 andotakuma  staff      90  7  4 09:44 mysystem.h

% ./mysysmain 
使い方 : ./mysysmain コマンド文字列

% ./mysysmain "ls -l"
mysystem:
total 616
-rw-r--r--  1 andotakuma  staff     143  7  4 09:44 Makefile
-rw-r--r--  1 andotakuma  staff    2795  7  4 09:44 README.md
-rw-r--r--  1 andotakuma  staff  238232  7  4 09:44 README.pdf
-rwxr-xr-x  1 andotakuma  staff   50406  7  4 10:16 mysysmain
-rw-r--r--  1 andotakuma  staff     925  7  4 09:44 mysysmain.c
-rw-r--r--  1 andotakuma  staff     721  7  4 10:16 mysystem.c
-rw-r--r--  1 andotakuma  staff      90  7  4 09:44 mysystem.h
retval = 00000000
system:
total 616
-rw-r--r--  1 andotakuma  staff     143  7  4 09:44 Makefile
-rw-r--r--  1 andotakuma  staff    2795  7  4 09:44 README.md
-rw-r--r--  1 andotakuma  staff  238232  7  4 09:44 README.pdf
-rwxr-xr-x  1 andotakuma  staff   50406  7  4 10:16 mysysmain
-rw-r--r--  1 andotakuma  staff     925  7  4 09:44 mysysmain.c
-rw-r--r--  1 andotakuma  staff     721  7  4 10:16 mysystem.c
-rw-r--r--  1 andotakuma  staff      90  7  4 09:44 mysystem.h
retval = 00000000

*/
