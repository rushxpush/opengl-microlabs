#include <stdio.h>

struct Buffer {
  int size;
};

struct Context {
  struct Buffer buffer[10];
  int current;
};

int main() {
  struct Context ctx;

  ctx.current = 3;

  struct Buffer* buff = &ctx.buffer[ctx.current];

  buff->size = 7;
  // or like this:
  // (*buffer).size = 7;

  printf("ctx.buffer[ctx.current]: %d\n", ctx.buffer[ctx.current].size);
  // printf("buffer->size: %d\n", buff->size);

  return 0;
}