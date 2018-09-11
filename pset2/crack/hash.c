#define _XOPEN_SOURCE
#define _GNU_SOURCE
#include <unistd.h>
#include <crypt.h>
#include <stdio.h>

int main (int argc , char * argv[])
{
   if (argc != 3)
    {
        printf ("Error: Check the arguments\n");
        printf ("Usage: ./hash plain salt\n");
        
        return 1;
    }
  char *hash = crypt (argv[1], argv[2]);
  printf("%s\n",hash);
}
