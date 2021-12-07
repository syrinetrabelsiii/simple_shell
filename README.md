HSH - Simple Shell 
A simple UNIX command interpreter written as part of the low-level programming and algorithm track at Holberton School.

Description 💬
[pip]hsh is a simple UNIX command language interpreter that reads commands from either a file or standard input and executes them.

Requeriments 👁️‍🗨️
Allowed editors: vi, vim, emacs.
Programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
All files should end with a new line
Code should use the Betty style. it will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style\ .pl) and betty-doc.pl
No more than 5 functions per file
All your header files should be include guarded
Use system calls only when you need to
Authorized functions and system calls:
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
fork (man 2 fork)
free (man 3 free)
stat (__xstat)(man 2 stat)
lstat (__lxstat)(man 2 lstat)
fstat (__fxstat)(man 2 fstat```)
getcwd (man 3 getcwd)
getline (man 3 getline)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
_exit (man 2 _exit)
isatty (man 3 isatty)
fflush (man 3 fflush)
Invocation 🙈 🙉 🙊
Usage:
To invoke, compile all .c files in the repository and run the resulting executable:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
./hsh
To exit the program,type: ($) exit

This hsh supports most shell commands, such as cat, pwd, ls -la and more.

Examples 👌
Ex 1:
> pwd
/root/simple_shell
Ex 2:
> ls -l
total 72
-rw-r--r-- 1 root root  1872 Aug 25 07:04 adv_func.c
-rw-r--r-- 1 root root  1108 Aug 25 06:29 base_func.c
-rw-r--r-- 1 root root   518 Aug 25 06:39 exec.c
-rw-r--r-- 1 root root   723 Aug 25 06:40 _getline.c
-rwxr-xr-x 1 root root 22656 Aug 25 07:23 hsh
-rw-r--r-- 1 root root   820 Aug 25 07:17 main.c
-rw-r--r-- 1 root root  1136 Aug 25 06:41 more_fun2.c
-rw-r--r-- 1 root root   968 Aug 25 06:44 more_func.c
-rw-r--r-- 1 root root  1048 Aug 25 06:47 path.c
-rw-r--r-- 1 root root  2457 Aug 25 06:17 README.md
-rw-r--r-- 1 root root   176 Aug 25 06:47 signal.c
-rw-r--r-- 1 root root   936 Aug 25 07:16 simple_shell.h
-rw-r--r-- 1 root root   722 Aug 25 06:47 split.c
