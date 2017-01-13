#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 1;
  int j = 25;

  while ((i < 26) && (j > 0)){
      printf("%d\t\t%d\n", i,j);
      i++;
      j--;
  }
  return 0;
}
