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