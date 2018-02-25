#include <stdio.h>
//Works Cited: Function mystrlen was created with the help of Minh
int main()
{
	char a[] = "Potato";
	char b[] = "ato";
	printf("Word 1: %s Word 2: %s\n", a, b);
	printf("Match check: %d", strend(a,b));
	return 0;
}

int strend(char *s, char *t)
{
	int length = mystrlen(t);

	

	while(*s != '\0')
	{
		++s;
	}
	--s;
	while(*t != '\0')
	{
		++t;
	}
	--t;
	
	while(length > 0)
	{
		if(*t == *s)
		{
			--s;
			--t;
			--length;
		}
		else
			return 0;
	}
	if (length == 0)
		return 1;
	return 0;
}

int mystrlen(char *g)
{
    char *p;
    p=g;

    while(*p!='\0')
        ++p;

    return p-g;
}

