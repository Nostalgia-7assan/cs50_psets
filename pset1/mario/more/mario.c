#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n, i, j;
    do
    {
        n = get_int("Enter the height\n") ;
    }
    while (n < 0 || n > 23);
    for (i = 0 ; i < n ; i++)
    {
        for (j = 0 ; j < n - i - 1 ; j++)
        {
            printf(" ");
        }
        for (j = 0 ; j <= i ; j++)
        {
            printf("#");
        }

        printf("  ");
        for (j = 0 ; j <= i ; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}