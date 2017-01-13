#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/* pointer notes
type *ptr - A pointer of type named ptr
*ptr - The value of whatever ptr is pointed at
*(ptr + i) - The value of (whatever ptr is pointed at plus i)
&thing - The address of thing in memory
type *ptr = &thing; - A pointer of type named ptr set to address of thing
ptr++ - Increment where ptr points to in memory

ptr->element - Use ptr to struct/union to get element. The '->' derefences the
pointer first, and then grabs element, so obviously 'ptr' here has to be a pointer
to a struct/union, otherwise you just use struct.element syntax. We use -> on pointers
to structs, or '.' syntax if it isn't a pointer.

Basically 'ptr->name' is the same as doing:
(*ptr).name = ""; 
*/

// C packs these together into one chunk of RAM.
struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

// malloc, memory allocator gets a chunk of RAM of size passed to it
// this definition is like an object constructor function would be in other
// languages. It returns a pointer to a Person struct.
struct Person *Person_create (char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL); // make sure malloc() went ok!

	// copy arguments to their places are return the pointer to the struct
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

// No garbage collection, we must do it ourselves.
void Person_destroy (struct Person *who)
{
	assert(who != NULL);
	free(who->name);
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);	
}

int main(int argc, char *argv[])
{
	// make two people structures
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);

	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

	// print them out and where they are in memory
	printf("Joe is at memory location %p:\n", joe);
	Person_print(joe);

	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);

	// make everyone age 20 years and print them again
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	// destroy them both so we clean up
	Person_destroy(joe);
	Person_destroy(frank);

	return 0;
}