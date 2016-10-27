#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int x;

int main(int argc, char *argv[]) {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello from (pid:%d)\n", (int) getpid());
    } else {
        waitpid(rc);
        printf("goodbye from (pid:%d)\n", (int) getpid());
    }
}
