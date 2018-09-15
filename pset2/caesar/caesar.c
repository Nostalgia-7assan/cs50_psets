#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

int main(int argc , char* argv[])
{
 if ( argc != 2)
 {
     printf ("Error: Check the arguments\n");
     return 1 ;
 }
 int key = atoi(argv[1]);
 string plain  ;
 plain = get_string("plaintext:  ") ;
 string cipher = plain ;
 int i ;
 for (i = 0 ; i < strlen(plain) ; i++)
 {
     if (isalpha(plain[i]))
     {
         char alpha = plain[i] ;
         if (isupper(alpha))
         {
             alpha = alpha - 65 ;
             alpha = ((alpha + key) % 26 ) ;
             alpha = alpha + 65 ;
             cipher[i] = alpha ;
         }
         else
         {
             alpha = alpha - 97 ;
             alpha = ((alpha + key) % 26 ) ;
             alpha = alpha + 97 ;
             cipher[i] = alpha ;
         }

     }
     else
     {
         cipher[i] = plain[i] ;
     }

 }
 printf("ciphertext: %s\n" , cipher);
 return 0 ;
}