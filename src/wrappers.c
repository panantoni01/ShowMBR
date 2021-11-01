#define _POSIX_C_SOURCE 200809L

#include"wrappers.h"

int Open(const char *pathname, int flags) {
    int ret = open(pathname, flags);
    if (ret < 0) {
        fprintf(stderr, "open error: %s\n", strerror(errno));
        exit(1);
    }
    return ret;
}

int Close(int fd) {
    int ret = close(fd);
    if (ret != 0) {
        fprintf(stderr, "close error: %s\n", strerror(errno));
        exit(1);
    }
    return ret;
}

ssize_t Read(int fd, void *buf, size_t count) {
    ssize_t ret = read(fd, buf, count);
    if (ret < 0) {
        fprintf(stderr, "read error: %s\n", strerror(errno));
        exit(1);
    }
    if ((size_t)ret != count) {
        fprintf(stderr, "cannot read MBR - the file is too short\n");
        exit(1);
    }
    return ret;
}

int Setuid(uid_t uid) {
    int ret = setuid(uid);
    if (ret != 0) {
        fprintf(stderr, "setuid error: %s\n", strerror(errno));
        exit(1);
    }
    return ret;
}

pid_t Fork() {
    int ret = fork();
    if (ret < 0) {
        fprintf(stderr, "fork error: %s\n", strerror(errno));
        exit(1);
    }
    return ret;
}

int Execv(const char *pathname, char *const argv[]) {
    /* The exec() functions return only if an error has occurred. */
    execv(pathname, argv);
    fprintf(stderr, "execv error: %s\n", strerror(errno));
    exit(1);
}

int Mkstemp(char *template) {
    int ret = mkstemp(template);
    if (ret < 0) {
        fprintf(stderr, "mkstemp error: %s\n", strerror(errno));
        exit(1);
    }
    return ret;
}

ssize_t Write(int fd, const void *buf, size_t count) {
    int ret = write(fd, buf, count);
    if (ret < 0) {
        fprintf(stderr, "write error: %s\n", strerror(errno));
        exit(1);
    }
    return ret;
}

int Unlink(const char *pathname) {
    int ret = unlink(pathname);
    if (ret < 0) {
        fprintf(stderr, "unlink error: %s\n", strerror(errno));
        exit(1);
    }
    return ret;
}

pid_t Wait(int *wstatus) {
    int ret = wait(wstatus);
    if (ret < 0) {
        fprintf(stderr, "wait error: %s\n", strerror(errno));
        exit(1);
    }
    return ret;
}

int Fflush(FILE *stream) {
    int ret = fflush(stream);
    if (ret < 0) {
        fprintf(stderr, "fflush error: %s\n", strerror(errno));
        exit(1);
    }
    return ret;
} 