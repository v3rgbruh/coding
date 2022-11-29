#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

void doStuff(void);

int main(const int argc, const char* argv[]){
  struct itimerval it_val;
  float interval = atof(argv[1]);
  
  if (signal(SIGALRM, (void (*)(int)) doStuff) == SIG_ERR){
    perror("Unable to catch SIGALRM");
    exit(1);
  }
  it_val.it_value.tv_sec = interval;
  it_val.it_value.tv_usec = (int)(interval * 1000000) % 1000000;
  it_val.it_interval = it_val.it_value;

  if (setitimer(ITIMER_REAL, &it_val, NULL) == -1) {
    perror("error calling settimer()");
    exit(1);
  }

  while(1)
    pause();

  return 0;
}

void doStuff(void){
  printf("run\n");
}
