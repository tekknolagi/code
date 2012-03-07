#include <stdio.h>
#include <math.h>

/*
Calculates the integral of a polynomial function at a given value.
Usage: ./polynomial 1 2 3 4 5
Gives: integrate (f(x) = x^3 + 2x^2 + 3x + 4) at x = 5
*/

int main(int argc, char **argv) {
  int i, v = atoi(argv[argc-1]);
  float s;
  for (i = 0; i < argc-3; i++) {
    s += atoi(argv[i+1]) * (pow(v,argc-2-i)/(argc-2-i));
  }
    printf("%.2f + C\n", s);
}
