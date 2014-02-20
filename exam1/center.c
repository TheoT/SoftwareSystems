/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Returns a heap-allocated string with length n, with
// the given string in the middle, surrounded by fillchar.
//
// For example, if s is allen, n is 10 and fillchar is .
// the result is ..allen... 

char *center(char *s, int n, char fillchar)
{
    if (n<0){
        fprintf(stderr, "Desired string length is less than 0\n");
        exit(1);
    }
    char *res = (char*) malloc(n+1);
    char *buff;
    buff=res; // use this buffer to step through our return string
    
    // figure out how many fillchars we need before/after
    int s_len=strlen(s);
    int fill_num = n-s_len;
    int prior = fill_num/2; // integer division is intended
    
    // fill before string
    int i;
    for (i=0;i<prior;i++){
        *buff = fillchar;
        buff+=1;
    }

    // copy string into the middle
    strcpy(buff,s);

    // fill in after string
    buff+=s_len;
    for (i=0;i<(fill_num-prior);i++){
        *buff = fillchar;
        buff+=1;
    }
    return res;
}   


int main (int argc, char *argv[])
{
    char *s = center("Software", 30, '.');
    printf("%s\n", s);

    char *s2 = center("Systems", 31, '-');
    printf("%s\n", s2);

    char *s3 = center("Spring 2014", 32, '*');
    printf("%s\n", s3);

    char *s4 = center("Exam 1", 33, '^');
    printf("%s\n", s4);

    return 0;
}
