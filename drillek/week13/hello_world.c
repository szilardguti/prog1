#include <stdio.h>
#include <string.h>

void printer(char* p, int x)
{
	printf("p is \"%s\" and x is %i\n", p, x);
}

int main()
{
	printf("Hello World!\n");

	char elso[6] = "Hello";
	char masodik[7] = "World!";

	printf("%s %s\n", elso, masodik);

	printer("foo", 7);
	printer("hurka", 420);
	printer("-teszt-", 57);

	return 0;
}