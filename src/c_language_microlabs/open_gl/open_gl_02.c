#include <stdio.h>

struct Buffer 
{
  int size;
  int is_set;
  float vertices[1000];
};

struct Context 
{
  struct Buffer gl_array_buffer[10];
  struct Buffer gl_element_array_buffer[10];
  int current_array_buffer;
  int current_element_array_buffer;
} ctx;

enum mode 
{
  GL_ARRAY_BUFFER,
};

enum usage 
{
  GL_STREAM_DRAW,
  GL_STATIC_DRAW,
  GL_DYNAMIC_DRAW
};

void glBindBuffer(unsigned int* vbo);

void glBufferData(enum mode mode, int size, float vertices[], enum usage usage);

int main() 
{
  float vertices[] = {
    -1.0f,  1.0f, 0.0f,
     1.0f,  1.0f, 0.0f,
     1.0f, -1.0f, 0.0f
  };

  unsigned int vbo;

  glBindBuffer(&vbo);

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  
  return 0;
}

void glBindBuffer(unsigned int* vbo) 
{
  int id = -1;

  for (int i = 0; i < sizeof(ctx.gl_array_buffer) / sizeof(struct Buffer); i++) 
  {
    if (ctx.gl_array_buffer[i].is_set == 0) 
    {
      id = i;
      ctx.gl_array_buffer[i].is_set = 1;
      break;
    }
  }

  if (id == -1)
  {
    printf("No free buffer!\n");
    return;
  }

  ctx.current_array_buffer = id;
  ctx.gl_array_buffer[ctx.current_array_buffer].size = 1000; // I added this because I don't know if I should initialize the size dynamically or statically

  *vbo = ctx.current_array_buffer;
}

void glBufferData(enum mode mode, int size, float vertices[], enum usage usage) 
{
  struct Buffer* ptr = &ctx.gl_array_buffer[ctx.current_array_buffer];

  if (size < ptr->size)
  {
    for (int i = 0; i < size / sizeof(float); i++)
    {
      ptr->vertices[i] = vertices[i];
      ptr->size--;
    }
  }
  else 
  {
    printf("vertices is too big!");
  }

  // START A  DEBUG
  for (int i = 0; i < size / sizeof(float); i++)
  {
    printf("ptr->vertices[%d]: %f\n", i, ptr->vertices[i]);
  }
  // END DEBUG
}