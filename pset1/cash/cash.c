#include <stdio.h>
#include <math.h>
int main(void)
{
    
    float n ;
    int count = 0 ;
    do
    {
        printf ("Change owed: ");
        scanf ("%f" , &n );
    } while (n < 0) ;
    n *= 100 ;
    n = round(n) ;
    printf("%f" , n);
    while (n >= 25)
    {
        n -= 25 ;
        count++ ;
    }
    while ( n >= 10 )
    {
        n -= 10 ;
        count ++ ;
    }
    while ( n >= 5 )
    {
        n -= 5 ;
        count ++ ;
    }
    while ( n >= 1 )
    {
        n -= 1 ;
        count ++ ;
    }
    printf ("%d\n" , count );
}