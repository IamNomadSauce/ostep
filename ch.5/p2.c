#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  printf("Hello, world (pid:%d)\n", (int) getpid());
  int rc = fork();
  if (rc < 0) {
    // Fork failed
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    // Child new process
    printf("hello, I am child (pid: %d)\n", (int) getpid());
  } else {
    // Parent goes down this path (main)
    int rc_wait = wait(NULL);
    printf("Hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
  }
  return 0;
}
