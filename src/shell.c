#include <stdio.h> // when/if ported to freestanding OS, replace with appropriate includes.

#define EXIT_SUCCESS 0;
#define EXIT_FAIL 1;
int error = 0;
int running;

void shell_loop(void) {
  
  while(running) {
    // do stuff
  }
  
}

int main(void) {
  // load any possible config files (added in future)

  running = 1;
  shell_loop();

  // perform any shutdown/cleanup (also added in future)
  if(!error) {
    return EXIT_SUCCESS;
  }
  else {
    return EXIT_FAIL;
  }
}
