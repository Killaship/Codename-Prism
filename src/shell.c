// todo: implement executable finding and arguments
// https://theartofmachinery.com/2018/11/07/writing_a_nix_shell.html
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

void displayprompt() {
  char usr[4] = ">";
  char cwd[4097];
  if(geteuid() == 0)  {strcpy(usr, " # ");}
  else {strcpy(usr, " $ ");}
  
  char *prompt = usr;
  getcwd(cwd, sizeof(cwd));
  printf("%s%s", cwd, prompt);
}

int runcmd(char *cmd) {
  int pid = fork();
  if(pid < 0) { // error for some reason
    printf("Can't create a new process!\n");
    exit(1);
  }
  if(pid == 0) { // child process
   char* arr[] = {cmd, NULL};
    execv(cmd, arr);
    
    
    
    printf("Command execution failed!\n");// you should only get here if execv() failed
    exit(1);
  }
  

  return 0;
}
/*
use getenv("PATH") combined with strtok (delim ":").
then loop through the different paths looking for the binary. (note: how would you tell the difference  between a command and a straight path? (maybe try and find any "/"'s in the string, indicating a normal path?)


*/


int main() {
  char str[512];
  while(1) {
    displayprompt();
    scanf("%s", str);
    runcmd(str);
    wait(NULL);
    
  }
  
}


