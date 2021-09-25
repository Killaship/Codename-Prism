// todo: everything
// https://theartofmachinery.com/2018/11/07/writing_a_nix_shell.html

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void main() {
  const char *prompt = ">";
  char str[512];
  while(1) {
    printf(prompt);
    scanf("%s", str);
    runcmd(str);
  }
}

void runcmd(char cmd) {
  int pid = fork();
  if(pid < 0) { // error for some reason
    printf("Can't create a new process!");
    exit(1);
  }
  if(pid == 0) { // child process
    char* arr[] = {str, NULL};
    execv(str, arr);
    
    printf("Command execution failed!"); // you should only get here if execv() failed
    exit(1);
  }
  int status;
  wait(&status); // just wait until child is done
  // This is the exit code of the child
  // (Conventially zero means okay, non-zero means error)
  return WEXITSTATUS(status);
}
