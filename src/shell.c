// todo: everything
// https://theartofmachinery.com/2018/11/07/writing_a_nix_shell.html
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void displayprompt() {
  const char *prompt = "> ";
  printf(getcwd(), prompt);
}

int runcmd(const char *cmd) {
  int pid = fork();
  if(pid < 0) { // error for some reason
    printf("Can't create a new process!");
    exit(1);
  }
  if(pid == 0) { // child process
    const char *arr[] = {cmd, NULL};
    execv(cmd, arr);
    printf("\n");
    
    printf("Command execution failed!"); // you should only get here if execv() failed
    exit(1);
  }
  

  return 0;
}

void main() {
  char str[512];
  while(1) {
    
    scanf("%s", str);
    runcmd(str);
    displayprompt();
  }
}


