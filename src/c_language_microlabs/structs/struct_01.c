#include <stdio.h>

struct Buffer {
  int size;
};

int main() {
  struct Buffer b1;
  b1.size = 2;

  printf("size: %d\n", b1.size);

  return 0;
}