#include <stdio.h>

#define RED   "\033[36m"
#define BOLD  "\033[1m"
#define RESET "\033[0m"


int main(const int argc, const char* argv[]){
  puts(BOLD RED "You died\n" RESET);

  return 0;
}
