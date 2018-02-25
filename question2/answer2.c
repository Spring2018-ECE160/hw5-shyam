#include <stdio.h>
#define SIZE 100


static char po[SIZE];
static char *op = po;

int main(){
	char word[] = "Baby";
	char word2[] = "Driver";
	strcat(word, word2);
	printf("After combining: %s", po);
}

void strcat(char *s, char *t)
{
	int counter = 0; 
	while(*s != '\0')
	{
		*op = *s;
		op++;
		s++;
	}

	while(*t != '\0')
	{
		*op = *t;
		op++;
		t++;
	}
}
	
