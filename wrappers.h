#include<fcntl.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int Open(const char *pathname, int flags);
int Close(int fd);
ssize_t Read(int fd, void *buf, size_t count);
int Setuid(uid_t uid);
pid_t Fork();
int Execv(const char *pathname, char *const argv[]);
int Mkstemp(char *template);
ssize_t Write(int fd, const void *buf, size_t count);
int Unlink(const char *pathname);
pid_t Wait(int *wstatus);
int Fflush(FILE *stream);