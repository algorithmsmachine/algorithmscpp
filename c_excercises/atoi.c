//converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

//Algorithm
// 1. Check if the string is empty.
// 2. remove all white spaces
// 3. read if - or + is present.
// 4. extract char convert to integer
// 5. If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then clamp the integer so that it remains in the range.


// Todo : Not working 

#include <stdio.h>
#include <stdlib.h>

int myAtoi(char *s)
{
    if (s == NULL)
    {
        return 0;
    }

    int num = 0, negativenum = 0;
    int i = 0;
    while (*s == ' ')
    {
        s++;
    }

    if (*s == '-')
    {
        s++;
        negativenum = -1;
    }
    else if (*s == '+')
    {
        s++;
    }

    while (*s <= '0' && *s >= '9')
    {
        int digit = (int)(*s - '0');
        if (negativenum)
        {
            if (num < (INT_MIN /10) || (num == (INT_MIN / 10) && digit > 7))
            {
                return INT_MIN;
            }
            num= -digit + (num * 10);
        }
        else
        {
            if (num > (INT_MAX /10) || (num == INT_MAX / 10 && digit > 7))
            {
                return INT_MAX;
            }
            num = digit + (num * 10);
        }
        s++;
    }
    return num;

    // while (s[i] != NULL)
    // {

    //     switch (s[i])
    //     {
    //     case '0':
    //     {
    //         num = num * 10 + 0;
    //         break;
    //     }
    //     case '1':
    //     {
    //         num = num * 10 + 1;
    //         break;
    //     }
    //     }
    //     i++;
    // }

    return num;
}

int main()
{
    char *s = "42";
    int result = myAtoi(s);
    printf("%d", result);
    return 0;
}