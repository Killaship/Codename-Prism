// todo: everything
// https://theartofmachinery.com/2018/11/07/writing_a_nix_shell.html

#include <unistd.h>
#include <stdio.h>

void main() {
  const char *prompt = ">";
  char str[512];
  while(1) {
    printf(prompt);
    scanf("%s", str);
    char* arr[] = {str, NULL};
    execv(str, arr);
  }
}
