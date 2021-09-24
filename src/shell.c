// todo: everything
// https://theartofmachinery.com/2018/11/07/writing_a_nix_shell.html

#include <unistd.h>
#include <stdio.h>

void main() {
  char cmd = "/bin/ls";
  args = [cmd, 0];
  execv(cmd, args);
}
