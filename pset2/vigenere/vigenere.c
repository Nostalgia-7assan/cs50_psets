#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <cs50.h>

int main(int argc ,char* argv[])
{
 if ( argc != 2 )
 {
     printf ("Error: Check the arguments\n");
     return 1 ;
 }
 string key = argv[1] ;
 int i  ;
 for (i = 0 ; i < strlen(key) ; i++)
 {
     if (!(isalpha(key[i])))
     {
      printf ("Error: Check the arguments\n");
      return 1 ;
     }
 }

 string plain = get_string("plaintext:  ");
 char* cipher = plain;
 int j = 0;
 for (i = 0 ; i < strlen(plain) ; i++)
 {
     if (isalpha(plain[i]))
     {
         char alpha = plain[i] ;
         char keyindex = 0;
         if(isupper(key[j]))
         {
             keyindex = key[j] - 65 ;
         }
         else
         {
             keyindex = key[j] - 97;
         }

         if (isupper(alpha))
         {
             alpha = alpha - 65 ;
             alpha = ((alpha + keyindex) % 26 ) ;
             alpha = alpha + 65 ;
             cipher[i] = alpha ;
         }
         else
         {
             alpha = alpha - 97 ;
             alpha = ((alpha + keyindex) % 26 ) ;
             alpha = alpha + 97 ;
             cipher[i] = alpha ;
         }
         j++ ;
         if(j == strlen(key))
         {
             j = 0 ;
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