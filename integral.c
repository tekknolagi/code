#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
  int i, v = atoi(argv[argc-1]);
  float s;
  for (i = 0; i < argc-3; i++) {
    s += atoi(argv[i+1]) * (pow(v,argc-2-i)/(argc-2-i));
  }
    printf("%.2f + C\n", s);
}
