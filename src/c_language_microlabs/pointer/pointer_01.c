#include <stdio.h>

int main() {
  int value = 3;
  int* ptr_value = &value;

  // value: 3
  printf("value: %d\n", value);

  // address of 'value' variable
  printf("ptr_value: %p\n", ptr_value);

  // address of 'ptr_value' variable
  printf("&ptr_value: %p\n", &ptr_value);

  // deference pointer -> access value stored at the 
  // memory address held by the pointer
  printf("*ptr_value: %d\n", *ptr_value);
}