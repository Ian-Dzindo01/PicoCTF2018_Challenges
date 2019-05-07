#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define FLAGSIZE_MAX 64

char flag[FLAGSIZE_MAX];

void sigsegv_handler(int sig) {
  fprintf(stderr, "%s\n", flag);
  fflush(stderr);
  exit(1);
}

void vuln(char *input){                         /* this is a potential vulnerability*/
  char buf[16];
  strcpy(buf, input);
}

int main(int argc, char **argv){
  
  FILE *f = fopen("flag.txt","r");
  if (f == NULL) {
    printf("Flag File is Missing. Problem is Misconfigured, please contact an Admin if you are running this on the shell server.\n");
    exit(0);
  }

  fgets(flag,FLAGSIZE_MAX,f);                       /* reads a string from the file*/
  signal(SIGSEGV, sigsegv_handler);                 /* set up a signal to handle a segfault*/
  
  gid_t gid = getegid();                           /*get the effective group id*/
  setresgid(gid, gid, gid);
  
  if (argc > 1) {
    vuln(argv[1]);                                 /* supply a very large string to break the vuln function*/
    printf("Thanks! Received: %s", argv[1]);
  }
  else
    printf("This program takes 1 argument.\n");
  return 0;
}
