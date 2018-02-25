#include <stdio.h>
#include <ctype.h>
// Work Cited: Help from David and Minh with conversions
// K&R Pg. 97
int getch();
void ungetch(int);

#define BUFSIZE 100

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buf

int getch(void) // get a (possibly pushed back) charater
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back on input
{
    if (bufp >= BUFSIZE)
        printf("ungetch:too many characters\n");
    else
        buf[bufp++] = c;
}

// getint: get next integer from input into *pn
int getfloat(float *pn)
{
    int c, sign, fraction, digits;


    while (isspace(c = getch())); // skip white space
        

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); // it's not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();
    if (!isdigit(c) && c !='.')
    {
	    if (c == EOF){
		    return EOF;
	    }
	    else
	    {
		    ungetch(c);
		    return 0;
	    }
    }
    *pn = 0;
    fraction = 0;
    digits = 0;
    for(; isdigit(c) || c == '.'; c = getch())
    {
	    if(c = '.')
	    {
		    fraction = 1;
	    }
	    else
	    {
		    if(!fraction)
		    {
			    *pn = 10 * *pn + (c - '0');
		    }
		    else
		    {
			    *pn = *pn + ((c - '0') / pow(10, fraction));
			    fraction++;
		    }
		    digits++;
	    }
    }
    *pn *= sign;

    if (c = EOF)
        return EOF;
    else
    {
	    ungetch(c);
	    return (digits) ? c: 0;
    }


    return c;
}

int main()
{
    int c, pn;
    c = getint(&pn);
    printf("c=%d pn=%d", c, pn);
    return 0;
}
