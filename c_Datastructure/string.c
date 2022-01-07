#include<stdio.h>
#include<stdlib.h>

// strlen function
int myStrlen(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

//strcmp function
int myStrcmp(char *s1, char *s2)
{
     printf("%c and %c\n",s1[0], s2[0]);
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            return s1[i] - s2[i];
        }
        i++;
    }
    return s1[i] - s2[i];
}

//ptrstrcmp function
int myptrStrcmp(char *s1, char *s2)
{
    printf("%c and %c\n",*s1, *s2);
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
        {
            return *s1 - *s2;
        }
    }
    return *s1 - *s2;
}

//strcpy function
char *myStrcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

// strcat function
char *myStrcat(char *dest, char *src)
{
    int i = 0;
    while (dest[i] != '\0')
    {
        i++;
    }
    int j = 0;
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}

int main(){
    char *str="Hello World";
    printf("%s\n",str);
    printf("%s\n",str+1);
    // printf("%s\n",str+2);

    printf("%c\n",*str);   // dereference top get the value at address
    printf("%c\n",*(str+1));
    // printf("%c\n",*(str+2));

    printf("%d\n",myStrlen(str));
    printf("%d\n",myStrcmp("abc","cd"));
    printf("%d\n",myptrStrcmp("abc","cd"));

    char charr[4];
    printf("%s\n",myStrcpy(charr,"cd"));

    printf("%s\n",myStrcat(charr,"ef"));
    

}