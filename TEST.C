#define INCL_DOS

#include <os2.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <process.h>


/* quickie program to test current priority */


int main (int argc,char *argv[]) {

  struct {
    char pridelta;
    char priclass;
  } pri;
  int x = 1;

  if (!DosGetPrty (0, &pri, 0)) {
    printf("\nTEST:  Priority is %d,%d\n",pri.priclass,pri.pridelta);
  }
  else {
    printf("\nTEST: Couldn't check priority\n");
  }

  if(argc > 1) {
    printf("\nTEST:  My args: ");
    while(argv[x]) {
      printf("%s ",argv[x]);
      x++;
    }
    printf("\n");
  }

  return 0;
}
