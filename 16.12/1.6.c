#include <stdio.h>

int main(void)
{
  int result;
  result = (getchar() != EOF);
  printf("%d\n", result);
  return 0;
}

