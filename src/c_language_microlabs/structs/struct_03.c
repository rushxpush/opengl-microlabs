#include <stdio.h>

struct Buffer {
  int size;
};

int main() {
  struct Buffer buffers[3];

  buffers[0].size = 3;
  buffers[1].size = 5;
  buffers[2].size = 7;

  for(int i = 0; i < 3; i++)
  {
    printf("buffers[%d]: %d\n", i, buffers[i].size);
  }

  return 0;
}