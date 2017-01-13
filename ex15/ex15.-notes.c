#include <stdio.h>

int main(int argc, char *argv[])
{
	int ages[] = { 23, 43, 12, 89, 2 };

	/* 
	array of char pointers. [ ptr, ptr, ptr, ptr, ptr ]. Not
	one contiguous block of memory, the actual chars could be stored
	anywhere in memory.

	The names array size would actually be the size of 5 char pointers!
	Careful with this!
	*/
	char *names[] = { "Alan", "Frank", "Mary", "John", "Lisa" };

	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	for (i = 0; i < count; i++) {
		printf("%s had %d years alive.\n", names[i], ages[i]);
	}

	printf("---\n");

	// cur_age is another way to refer to 'ages' block of RAM. It needs to be
	// int type so we can increment the correct amount to access the next storage
	// space in ages.
	int *cur_age = ages;

	// pointer to pointers (char pointers). Must be two-level pointer because that's
	// what names is. *cur_name would just pointer to start address of names array, 
	// the first char pointer value.
	char **cur_name = names;

	/* 
	When using a pointer here, the '*' means 'dereference' it. this throws off 
	a lot of new coders. it's unfortunate the '*' operator is so overloaded in C 
	like this and means different things in different contexts.

	Doing the loop this way is not advised, do it the next way we show.
	*/
	for (i = 0; i < count; i++) {
		printf("%s is %d years old.\n", 
			*(cur_name + i), *(cur_age + i));
	}

	printf("---\n");

	/*
	Pretending it is just an array, which it really just is!
	*/
	for (i = 0; i < count; i++) {
		printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
	}

	printf("---\n");

	/* 
	A really stupid way to do it by doing pointer arithmetic, it is 
	blazing fast however most compilers will optimize version 3 above 
	to do the same thing as here (in theory, unless they mess it up)
	*/
	for (cur_name = names, cur_age = ages; 
		(cur_age - ages) < count; cur_name++, cur_age++) {
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}

	return 0;
}