#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
  int pid1, pid2, pid3;

  pid1 = fork();
  if (pid1 < 0) {
    printf(1, "Fork failed\n");
  } else if (pid1 == 0) {
    sleep(1000);
    exit();
  } else {
    pid2 = fork();
    if (pid2 < 0) {
      printf(1, "Fork failed\n");
    } else if (pid2 == 0) {
      sleep(2000);
      exit();
    } else {
      pid3 = fork();
      if (pid3 < 0) {
        printf(1, "Fork failed\n");
      } else if (pid3 == 0) {
        sleep(3000);
        exit();
      } else {
        sleep(4000);

        int chosen_pid = pid1;

        int uncle_count = get_uncle_count(chosen_pid);
        printf(1, "Number of uncles for process with PID %d: %d\n", chosen_pid, uncle_count);

        wait();
        wait();
        wait();
      }
    }
  }

  exit();
}
