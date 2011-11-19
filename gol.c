#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 10
#define WIDTH 10

int *gb[HEIGHT];
int *gb2[HEIGHT];

void copy(int *gb[HEIGHT], int *gb2[HEIGHT]) {
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      gb2[i][j] = gb[i][j];
    }
  }
}

void init() {
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    gb [i] = malloc(sizeof(int)*WIDTH);
    gb2[i] = malloc(sizeof(int)*WIDTH);
  }
  for (i = j = 0; i < HEIGHT; i++) {
    for (; j < WIDTH; j++) {
      gb [i][j] = 0;
    }
  }
  gb[3][3] = gb[3][4] = gb[4][4] = gb[5][4] = gb[5][3] = gb[5][2] = gb[4][2] = gb[3][2] = 1;
  copy(&gb, &gb2);
}

void printg() {
  int i, j;
  printf("    ");
  for (i = 0; i < WIDTH; i++) {
    printf("%3d " , i);
  }
  printf("\n\n");
  for (i = 0; i < HEIGHT; i++) {
    printf("%3d  ", i);
    for (j = 0; j < WIDTH; j++) {
      printf(" %c  ", gb[i][j]?'+':'-');
    }
    printf("\n");
  }
}

void printg2() {
  int i, j;
  printf("    ");
  for (i = 0; i < WIDTH; i++) {
    printf("%2d  ", i);
  }
  printf("\n\n");
  for (i = 0; i < HEIGHT; i++) {
    printf("%3d  ", i);
    for (j = 0; j < WIDTH; j++) {
      printf(" %c  ", gb2[i][j]?'+':'-');
    }
    printf("\n");
  }
}

void ckill(int i, int j) {
  gb2[i][j] = 0;
}

void clive(int i, int j) {
  gb2[i][j] = 1;
}

void newgen() {
  int i, j = i = 0, n;
  for (; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      n = 0;
      if (gb[i][j+1] && j < WIDTH-1) n++;
      if (i < HEIGHT-1 && gb[i+1][j]) n++;
      if (i < HEIGHT-1 && j < WIDTH-1 && gb[i+1][j+1]) n++;
      if (j > 0 && i > 0 && gb[i-1][j-1]) n++;
      if (j > 0 && gb[i][j-1]) n++;
      if (i > 0 && gb[i-1][j]) n++;
      if (j > 0 && i < HEIGHT-1 && gb[i+1][j-1]) n++;
      if (i > 0 && j < WIDTH-1 && gb[i-1][j+1]) n++;

      if (n < 2) ckill(i, j);
      else if ((n == 2 || n == 3) && gb[i][j] == 1) clive(i, j);
      else if (n > 3) ckill(i, j);
      else if (n == 3 && gb[i][j] == 0) clive(i, j);
    }
  }
}

int main() {
  int i;
  init();
  printg();
  printf("\n\n");
  newgen();
  printg2();
  for (i = 0; i < HEIGHT; i++) {
    free(gb[i]);
  }
  return 0;
}
