#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes)
{
    char ***result = (char ***)malloc(sizeof(char **) * strsSize);

    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            result[i][j]=strs[i][j];
        }
    }
    return result;
}

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
int main()
{
    char **strs = (char **)malloc(sizeof(char *) * 6);
    strs[0] = "eat";
    strs[1] = "tea";
    strs[2] = "tan";
    strs[3] = "ate";
    strs[4] = "nat";
    strs[5] = "bat";
    int strsSize = 6;

    int returnSize = 0;
    int **returnColumnSizes = (int **)malloc(sizeof(int *) * strsSize);
    for (int i = 0; i < strsSize; i++)
    {
        returnColumnSizes[i] = (int *)malloc(sizeof(int) * strsSize);
    }
    
    char ***result = groupAnagrams(strs, strsSize, &returnSize, returnColumnSizes);
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%s ", result[i][j]);
        }
        printf("\n");
    }

    // int *returnSize =  (int **)malloc(sizeof(int *));;
    // int **returnColumnSizes = (int **)malloc(sizeof(int *) * 3);

    // groupAnagrams(strs, strsSize, returnSize, returnColumnSizes);

    return 0;
}