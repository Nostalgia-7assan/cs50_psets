#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    long long number = get_long_long("Enter a number: ");
    int digits = log10(number) + 1 ;
    char * status ;
    int two = number / (long long)pow(10 , digits - 2  ) ;
    int one = number / (long long)pow(10 , digits - 1  ) ;
    if(digits == 15 && (two == 34 || two == 37) )
        status = "AMEX" ;
    else if(digits == 16 &&(two == 51 || two == 52 || two == 53 || two == 54 || two == 55))
       status = "MASTERCARD" ;
    else if((digits == 13 || digits == 16 ) && one == 4)
       status = "VISA" ;
    else
       status = "INVALID" ;
    int i ;
    long long sum = 0 ;
    long long number2 = number ;
    number2 /= 10 ;
    for( i = 0 ; i <=digits / 2  ; i++)
    {
        if (number2 % 10 > 4)
        {
            int m = (number2 % 10) *2;
            sum += (m) % 10 ;
            m /= 10 ;
            sum += (m) % 10 ;
        }
        else
        {
            sum +=  (number2 % 10 ) *2 ;
        }

        number2 /= 100 ;
    }
    for( i = 0 ; i <= digits / 2   ; i++)
    {
        sum += number % 10 ;
        number /= 100 ;
    }

    if(sum % 10 == 0)
    {
        printf("%s\n" , status) ;
    }
    else
    {
        printf("INVALID\n") ;
    }
}