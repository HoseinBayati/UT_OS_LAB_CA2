#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "stat.h"
#include "fcntl.h"

int sys_copy_file()
{
  char *src, *dst;
  struct inode *fd_src, *fd_dst;
  char buf[512];
  int n, off;

  if (argstr(0, &src) < 0 || argstr(1, &dst) < 0)
    return -1;

  if ((fd_src = namei(src)) == 0)
    return -1;

  ilock(fd_src);

  if ((fd_dst = namei(dst)) == 0)
    fd_dst = ialloc(ROOTDEV, T_FILE);

  ilock(fd_dst);

  off = 0;

  while ((n = readi(fd_src, buf, off, sizeof(buf))) > 0)
  {
    if (writei(fd_dst, buf, off, n) != n)
    {
      iunlockput(fd_src);
      iunlockput(fd_dst);
      return -1;
    }
    off += n;
  }

  iunlockput(fd_src);
  iunlockput(fd_dst);

  return 0;
}

int sys_find_digital_root(void)
{
  struct proc *curproc = myproc();
  int a;

  // Use registers to retrieve arguments from the trap frame
  a = curproc->tf->ebx;

  if (a < 0)
  {
    return -1;
  }

  int digital_root;
  while (a >= 10)
  {
    digital_root = 0;
    while (a > 0)
    {
      digital_root += a % 10;
      a /= 10;
    }

    a = digital_root;
  }

  return a;
}

int sys_fork(void)
{
  return fork();
}

int sys_exit(void)
{
  exit();
  return 0; // not reached
}

int sys_wait(void)
{
  return wait();
}

int sys_kill(void)
{
  int pid;

  if (argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int sys_getpid(void)
{
  return myproc()->pid;
}

int sys_sbrk(void)
{
  int addr;
  int n;

  if (argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if (growproc(n) < 0)
    return -1;
  return addr;
}

int sys_sleep(void)
{
  int n;
  uint ticks0;

  if (argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while (ticks - ticks0 < n)
  {
    if (myproc()->killed)
    {
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
