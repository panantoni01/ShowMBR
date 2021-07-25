#include<fcntl.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int Open(const char *pathname, int flags);
int Close(int fd);
ssize_t Read(int fd, void *buf, size_t count);
int Setuid(uid_t uid);
