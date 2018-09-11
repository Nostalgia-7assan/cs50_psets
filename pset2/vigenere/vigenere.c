#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

int main(int argc ,char* argv[])
{
 if ( argc != 2 )
 {
     printf ("Error: Check the arguments\n");
     return 1 ;
 }
 char key[100] ;
 int i  ;
 
 for (i = 0 ; i < strlen(argv[1]) ; i++)
 {
     key[i] = argv[1][i] ;
 }

 for (i = 0 ; i < strlen(key) ; i++)
 {
     if (!(isalpha(key[i])))
     {
      printf ("Error: Check the arguments\n");
      return 1 ;   
     }
 }

 char plain[500] ;
 char cipher[500]  = "";
 int j = 0;
 printf("plaintext:  ");  
 scanf("%[^\n]s" , plain);
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