#include <stdio.h>

struct Buffer {
  int size;
};

int main() {
  struct Buffer b1;
  b1.size = 3;
  printf("b1.size: %d\n", b1.size);

  struct Buffer* b1_ptr = &b1;

  b1_ptr->size = 5;
  printf("b1.size: %d\n", b1.size);
  printf("b1_ptr->size: %d\n", b1_ptr->size);

  (*b1_ptr).size = 7;
  printf("*b1_ptr.size: %d\n", (*b1_ptr).size);

  return 0;
}