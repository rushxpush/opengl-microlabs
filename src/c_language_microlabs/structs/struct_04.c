#include <stdio.h>

struct Buffer {
  int size;
};

int main() {
  struct Buffer buffers[3];

  struct Buffer* ptr;

  int id = 1;

  ptr = &buffers[id];

  ptr->size = 254;
  // or you could do this like this:
  // (*ptr).size = 3;

  printf("buffers[%d].size: %d\n", id, buffers[id].size);

  return 0;
}