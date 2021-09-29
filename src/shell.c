// todo: everything
// https://theartofmachinery.com/2018/11/07/writing_a_nix_shell.html
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

void displayprompt() {
  char usr[3] = "$";
  char cwd[4097];
  if(geteuid() == 0)  {strcpy(usr, " #");}
  else {strcpy(usr, " $");}
  
  char *prompt = usr;
  getcwd(cwd, sizeof(cwd));
  printf("%s%s", cwd, prompt);
}

int runcmd(char *cmd) {
  int pid = fork();
  if(pid < 0) { // error for some reason
    printf("Can't create a new process!");
    exit(1);
  }
  if(pid == 0) { // child process
   char* arr[] = {cmd, NULL};
    execv(cmd, arr);
    
    
    
    printf("Command execution failed!"); // you should only get here if execv() failed
    exit(1);
  }
  

  return 0;
}

int main() {
  char str[512];
  while(1) {
    displayprompt();
    scanf("%s", str);
    runcmd(str);
    wait(NULL);
    
  }
  
}


