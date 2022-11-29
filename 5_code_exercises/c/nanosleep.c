#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

int alarma();

int main(const int argc, const char* argv[]){
  struct timespec ts;
  float delay = atof(argv[1]);
  ts.tv_sec = delay;
  ts.tv_nsec = ((int)delay % 1000000) * 1000000;
  nanosleep(&ts, NULL);
  alarma();
  while(1){};
}

int alarma(){
  printf("run\n");
  return SIGALRM;
}
