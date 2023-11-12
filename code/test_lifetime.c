#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
  int pid = fork();

  if (pid < 0) {
    printf(1, "Fork failed\n");
  } else if (pid == 0) {
    printf(1, "Child process created, pid: %d\n", getpid());

    sleep(10000);

    int lifetime_ticks = get_process_lifetime(getpid());
    int lifetime_seconds = lifetime_ticks / 1000;  
    printf(1, "Child process lifetime: %d ticks (%d seconds)\n", lifetime_ticks, lifetime_seconds);

    exit();
  } else {
    printf(1, "Parent process, child pid: %d\n", pid);

    sleep(5000);

    int lifetime_ticks = get_process_lifetime(getpid());
    int lifetime_seconds = lifetime_ticks / 1000;  
    printf(1, "Parent process lifetime: %d ticks (%d seconds)\n", lifetime_ticks, lifetime_seconds);
  }
  
  wait();

  exit();
}
