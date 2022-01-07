// Memset 
// void *memset(void *str, int c, size_t n) 
// copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str.

#include <stdio.h>
#include <string.h>

int main () {
   char str[50];

   strcpy(str,"A string of some kind");
   puts(str);

   memset(str,'@',3);
   puts(str);
   
   return(0);
}