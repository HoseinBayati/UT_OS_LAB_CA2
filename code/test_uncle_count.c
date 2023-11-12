#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
  int pid1, pid2, pid3;

  // Fork three processes
  pid1 = fork();
  if (pid1 < 0) {
    printf(1, "Fork failed\n");
  } else if (pid1 == 0) {
    // Child process 1
    sleep(1000);
    exit();
  } else {
    pid2 = fork();
    if (pid2 < 0) {
      printf(1, "Fork failed\n");
    } else if (pid2 == 0) {
      // Child process 2
      sleep(2000);
      exit();
    } else {
      pid3 = fork();
      if (pid3 < 0) {
        printf(1, "Fork failed\n");
      } else if (pid3 == 0) {
        // Child process 3
        sleep(3000);
        exit();
      } else {
        // Parent process
        sleep(4000);

        // Choose one of the child processes and call get_uncle_count
        int chosen_pid = pid1;

        int uncle_count = get_uncle_count(chosen_pid);
        printf(1, "Number of uncles for process with PID %d: %d\n", chosen_pid, uncle_count);

        // Wait for all child processes to exit
        wait();
        wait();
        wait();
      }
    }
  }

  exit();
}
