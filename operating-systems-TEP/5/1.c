#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int x;

int main(int argc, char *argv[]) {
    x = 100;
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        printf("and x is %d\n", x);
        x = 10;
        printf("After setting it to 10 x is %d\n", x);
    } else {
        int wc = wait(NULL);
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
        printf("and x is %d\n", x);
    }
}
