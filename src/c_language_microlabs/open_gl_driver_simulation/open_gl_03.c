#include <stdio.h>

struct Buffer 
{
  int size;
  int is_set;
  float vertices[1000];
};

struct VertexArrayBuffer
{
  int size;
  int is_set;
};

struct Context 
{
  struct Buffer gl_array_buffer[10];
  struct Buffer gl_element_array_buffer[10];
  struct VertexArrayBuffer gl_vertex_array_buffer[10];
  int current_array_buffer;
  int current_vertex_array_buffer;
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

void glGenBuffers(int size, unsigned int* vbo);

void glBindBuffer(unsigned int* vbo);

void glBufferData(enum mode mode, int size, float vertices[], enum usage usage);

void glGenVertexArrays(int size, unsigned int* vao);

void glBindVertexArray(unsigned vao);

int main() 
{
  float vertices[] = {
    -1.0f,  1.0f, 0.0f,
     1.0f,  1.0f, 0.0f,
     1.0f, -1.0f, 0.0f
  };

  unsigned int vbo;
  unsigned int vao;

  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  glGenBuffers(1, &vbo);

  glBindBuffer(&vbo);

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  
  return 0;
}

void glGenBuffers(int size, unsigned int* vbo) {
  // TODO - generate more than one buffer

  int id = -1;

  for (int i = 0; i < sizeof(ctx.gl_array_buffer) / sizeof(struct Buffer); i++) 
  {
    if (ctx.gl_array_buffer[i].is_set == 0) 
    {
      id = i;
      ctx.gl_array_buffer[i].is_set = 1;
      *vbo = id;
      break;
    }
  }

  if (id == -1)
  {
    printf("No free buffer!\n");
    return;
  }
}

void glBindBuffer(unsigned int* vbo) 
{
  ctx.current_array_buffer = *vbo;
  ctx.gl_array_buffer[ctx.current_array_buffer].size = 1000; 
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

void glGenVertexArrays(int size, unsigned int* vao)
{
// TODO - generate more than one vertex buffer
  int id = -1;
  for (int i = 0; i < sizeof(ctx.gl_vertex_array_buffer); i++)
  {
    if (ctx.gl_vertex_array_buffer[i].is_set == 0)
    {
      id = i;
      ctx.gl_vertex_array_buffer[i].is_set = 1;
      *vao = id;
      break;
    }
  }

  if (id == -1)
  {
    printf("No free space left!\n");
    return;
  }
}

void glBindVertexArray(unsigned vao) {
  ctx.current_vertex_array_buffer = vao;
  ctx.gl_vertex_array_buffer[ctx.current_vertex_array_buffer].size = 1000;
}
