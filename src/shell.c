// todo: everything
// https://theartofmachinery.com/2018/11/07/writing_a_nix_shell.html

#include <unistd.h>
#include <stdio.h>

void main() {
  char* arr[] = {"ls", NULL};
  execv("/bin/ls", arr);
}
