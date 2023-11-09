#include <stdio.h>
#include <stdlib.h>


void test(int n)
{
    volatile static int i = 8;
    volatile static unsigned char c = 0;

    c <<= 1;
    if (n == SIGUSR2)
        c |= 1;
    i--;
    if(i == 0)
    {
        if (c)
            printf("%c", c);
        i = 8;
        c = 0;
    }
    
}

int main(void)
{
    unsigned char c[] = "hello.there";
    int i = 0;
    int j;
    while (c[i])
    {
        j = 8;
        while (j > 0)
        {
            test((c[i] & 128) ? SIGUSR2 : SIGUSR1);
            c[i] = c[i] << 1;
            j--;
        }
        i++;
    }
}