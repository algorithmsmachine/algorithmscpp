#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int value;
} RandomizedSet;

RandomizedSet *randomizedSetCreate()
{
}

bool randomizedSetInsert(RandomizedSet *obj, int val)
{
    return true;
}

bool randomizedSetRemove(RandomizedSet *obj, int val)
{
    return true;
}

int randomizedSetGetRandom(RandomizedSet *obj)
{

    return 0;
}

void randomizedSetFree(RandomizedSet *obj)
{
}

int main()
{
    RandomizedSet *obj = randomizedSetCreate();
    printf("%d\n ", randomizedSetInsert(obj, 4));
    printf("%d\n ", randomizedSetInsert(obj, 4));
    printf("%d\n ", randomizedSetInsert(obj, 4));

    bool param_2 = randomizedSetRemove(obj, 5);

    int param_3 = randomizedSetGetRandom(obj);

    randomizedSetFree(obj);
}