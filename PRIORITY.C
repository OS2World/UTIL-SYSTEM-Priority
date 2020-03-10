#define INCL_DOS

#include <os2.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <process.h>


/* quickie program to adjust priority of a program being spawned */


int main (int argc,char *argv[]) {

  int priclass,pridelta;
  struct {
    int pid;
    int thread;
    int parentpid;
  } pid;

  if(argc < 4) {
    printf("\nUsage:  Priority.exe <priclass> <pridelta> program args...\n\n"
           " <priclass>:  1-4\n"
           "    1 = idle    2 = normal    3 = high    4 = fixed high (lower than 3)\n"
           " <pridelta>:  0-31\n"
           "    the higher the number, the higher the priority\n");
    exit(1);
  }

  priclass = atoi(argv[1]);
  pridelta = atoi(argv[2]);

  if(priclass < 1 || priclass > 4) {
    printf("\nInvalid priority class (first arg) %d\n",priclass);
    exit(1);
  }

  DosGetPID (&pid);
  if (!DosSetPrty (2, priclass, pridelta, pid.thread)) {
    printf("\nPriority set to %d,%d\n", priclass, pridelta);
  }
  else {
    printf("\n\07Couldn't affect priority\n");
  }

  return spawnvp(P_WAIT,argv[3],&argv[3]);
}
