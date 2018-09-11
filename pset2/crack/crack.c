#define _XOPEN_SOURCE
#define _GNU_SOURCE
#include <unistd.h>
#include <crypt.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool compare(char * a , char * b)
{
    if (strlen(a) != strlen(b))
    {
        return false ;
    }
    int i ;
    for ( i = 0 ; i <strlen(a) ; i++ )
    {
        if(a[i] != b[i])
        {
            return false ;
        }
    }
    return true ;
}

bool confrim(char a , char b , char c , char  d , char e , char* salt , char* argv)
{
    char plain[] = {a,b,c,d,e} ;
    char *hash = crypt (plain, salt);
    bool result = compare(hash , argv) ;
    if (result)
    {
        printf("%s is right\n",plain) ;
        return true ;
    }
    else
    {
        printf("%s is Wrong\t" , plain) ;
        return false ;
    }
}

int main (int argc, char *argv[])
{
    // check for the hash provieded
    if (argc != 2)
    {
        printf ("Error: Check the arguments\n");
        printf ("Usage: ./crack hash\n");
        return 1;
    }

    char salt[3]={argv[1][0],argv[1][1]} ;
    char chars[] = {'\0' ,'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O' ,
                    'P' , 'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' , 'Z' , 'a' , 'b' , 'c' , 'd' ,
                    'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' , 'p' , 'q' , 'r' , 's' , 
                    't' , 'u' , 'v' , 'w' , 'x' , 'y' , 'z'  };
    int i ,j , k , l , m ;
    int charslen = sizeof(chars) / sizeof(chars[1]);
    //generate one char words
    for (i = 0 ; i < charslen ; i++)
    {
        bool a = confrim (chars[i] , '\0' , '\0' , '\0' , '\0' , salt ,argv[1]) ;
        if(a)
        {
            return 0 ;
        }   
    } 
    //generate two char words
    /* the following loops starting from 1 to esacp null character */
    for (i = 1 ; i < charslen ; i++)
    {
    for( j = 1 ; j < charslen ; j++)
    {
        bool a = confrim (chars[i] , chars[j] , '\0' , '\0' , '\0' , salt ,argv[1]) ;
        if(a)
        {
            return 0 ;
        } 
    }
    }
    //generate three char words
    for (i = 1 ; i < charslen ; i++)
    {
    for( j = 1 ; j < charslen ; j++)
    {
    for( k = 1 ; k < charslen ; k++)
    {
        bool a = confrim (chars[i] , chars[j] , chars[k]  , '\0' , '\0' , salt ,argv[1]) ;
        if(a)
        {
            return 0 ;
        }
    }
    }
    }
    //generate four char words
    for (i = 1 ; i < charslen ; i++)
    {
    for( j = 1 ; j < charslen ; j++)
    {
    for( k = 1 ; k < charslen ; k++)
    {
    for( l = 1 ; l < charslen ; l++)
    {
        bool a = confrim (chars[i] , chars[j] , chars[k] , chars[l] , '\0' , salt ,argv[1]) ;
        if(a)
        {
            return 0 ;
        }
    }
    }
    }
    }

    //generate five char words
    for (i = 1 ; i < charslen ; i++)
    {
    for( j = 1 ; j < charslen ; j++)
    {
    for( k = 1 ; k < charslen ; k++)
    {
    for( l = 1 ; l < charslen ; l++)
    {
    for( m = 1 ; m < charslen ; m++)
    {
        bool a = confrim (chars[i] , chars[j] , chars[k] , chars[l] , chars[m] , salt ,argv[1]) ;
        if(a)
        {
            return 0 ;
        }
    }
    }
    }
    }
    } 
}
