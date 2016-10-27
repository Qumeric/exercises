#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[]) {
    int file = open("2.txt", O_CREAT|O_RDWR, 0666);
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        char buf;
        if (read(file, &buf, 1)) {
            printf("and I read letter %c from file\n", buf);
        } else {
            printf("and I cannot read from file\n");
        }
    } else {
        int wc = wait(NULL);
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
        char buf;
        if (read(file, &buf, 1)) {
            printf("and I read letter %c from file\n", buf);
        } else {
            printf("and I cannot read from file\n");
        }
    }
}
