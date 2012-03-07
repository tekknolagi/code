#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
  int i, s = 0, v = atoi(argv[argc-1]);
  for (i = 0; i < argc-2; i++) {
    s += atoi(argv[i+1]) * pow(v, argc-3-i);
  }
    printf("%d\n", s);
}
