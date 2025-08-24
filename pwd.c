#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    } else {
        perror("getcwd error");
        return 1;
    }
    return 0;
}
