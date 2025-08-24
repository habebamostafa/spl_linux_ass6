#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 1024
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr,"Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }
    int src = open(argv[1], O_RDONLY);
    if (src < 0) {
        perror("open source");
        return 1;
    }
    int dest = open(argv[2],O_WRONLY|O_CREAT| O_TRUNC, 0644);
    if (dest < 0) {
        perror("open destination");
        close(src);
        return 1;
    }
    char buffer[BUF_SIZE];
    ssize_t bytes;
    while ((bytes = read(src,buffer, BUF_SIZE)) > 0) {
        if (write(dest,buffer, bytes) != bytes) {
            perror("write error");
            close(src);
            close(dest);
            return 1;
        }
    }
    if (bytes < 0) perror("read error");
    close(src);
    close(dest);
    return 0;
}
