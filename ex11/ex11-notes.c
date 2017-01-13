#include <stdio.h>

int main(int argc, char *argv[])
{
  // modern c will add the other 0s to make 4 0s inthe array.
  // The total size of numbers array would be 16 bytes:
  // on 32 bit system, int = 4 bytes * 4 elements = 16 bytes
  int numbers[4] = { 0 };
  /* you can do below but not a good way to do strings unless you know for
     example that you need a char buffer of 20 bytes (for like a user
     field like 'lastname' or something)

     C will not 'fill out' the array in this case, it will put
     a nul terminator, \0, after the first char
  */
  char name[4] = { 'a' };

  // first, print them out raw
  printf("numbers: %d %d %d %d\n",
	 numbers[0], numbers[1], numbers[2], numbers[3]);

  // will only report 'a' because C auto nul-terminated it
  // when we set it above.
  printf("name each: %c %c %c %c\n",
	 name[0], name[1], name[2], name[3]);

  // printf knows how to read char array as a 'string'
  // (until \0 is found), so we can just use %s to do that
  printf("name: %s\n", name);

  /* next we will individually explicitly init each position */
  
  // setup the numbers
  numbers[0] = 1;
  numbers[1] = 2;
  numbers[2] = 3;
  numbers[3] = 4;

  // setup the name -- note last position must be the \0 terminator!
  // if you don't have this C won't know where the 'string' ends and
  // keep reading!!! MAJOR source of bugs with C-style strings
  name[0] = 'Z';
  name[1] = 'e';
  name[2] = 'd';
  name[3] = '\0';

  // then print them out initialized
  printf("numbers: %d %d %d %d\n",
	 numbers[0], numbers[1], numbers[2], numbers[3]);

  // NUL terminator won't actually visibly print out
  printf("name each: %c %c %c %c\n",
	 name[0], name[1], name[2], name[3]);

  // print the name like a string
  printf("name: %s\n", name);

  // another way to use name
  // This is the way you should init strings, unless you need a char
  // buffer of a fixed sized that you will store into later, then
  // you would use the 'array' syntax shortcut like this:
  // char another[20] = {};
  char *another = "Zed";

  printf("another: %s\n", another);

  // This shows that you can index into a 'string' because it is
  // just an array of chars!
  printf("another each: %c %c %c %c\n",
	 another[0], another[1], another[2], another[3]);
  
  return 0;
}
