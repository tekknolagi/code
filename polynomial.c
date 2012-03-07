#include <stdio.h>
#include <math.h>

/*
Calculates the value of a polynomial function at a particular value.
Usage: ./polynomial 1 2 3 4 5
Gives: f(x) = x^3 + 2x^2 + 3x + 4 at x = 5
*/

int main(int argc, char **argv) {
  int i, s = 0, v = atoi(argv[argc-1]);
  for (i = 0; i < argc-2; i++) {
    s += atoi(argv[i+1]) * pow(v, argc-3-i);
  }
    printf("%d\n", s);
}
