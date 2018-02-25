#include <stdio.h>
#define SIZE 1000

static char r[SIZE];

int strlen(char *g)
{
    char *p;
    p=g;

    while(*p!='\0')
        ++p;

    return p-g;
}

void strncopy(char *s, char *p, int i)
{
	while((*p != '\0')&&(i>0))
	{
		*s = *p;
		s++;
		p++;
		i--;
	}
}


int main()
{
	char u[] = "Dolphin";
	strncopy(r, u, 4);
	printf("%s\n", r);
	return 0;
}

