#include <stdio.h>
#include <stdlib.h>

// Todo : Not working

struct HashTableItem
{
    int key;
    int value;
};

const SIZE = 10;
int hashArray[SIZE];

int gethashCode(int key)
{
    return key % SIZE;
}

void insert(int key, int data)
{
    struct HashTableItem *item = (struct HashTableItem *)malloc(sizeof(struct HashTableItem));
    item->key = key;
    item->value = data;

    int hashIndex = gethashCode(key);
    while (hashArray[hashIndex] != NULL || hashArray[hashIndex]->key != -1)
    {
        ++hashIndex;
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
}

// struct HashTableItem *search(int key)
// {
//     if (key == NULL)
//     {
//         return NULL;
//     }

//     int hashIndex = gethashCode(key);
//     while (hashArray[hashIndex] != NULL)
//     {
//         if (hashArray[hashIndex]->key == key)
//         {
//             return hashArray[hashIndex];
//         }

//         // Goto next locationa nd wrap around the table
//         ++hashIndex;
//         hashIndex %= SIZE;
//     }

//     return NULL;
// };

// struct delete(int key)
// {
//     if (key == NULL)
//     {
//         return NULL;
//     }

//     int hashIndex = 0;
//     while (hashArray[hashIndex] != NULL)
//     {
//         if (hashArray[hashIndex]->key == key)
//         {
//             struct HashTableItem *temp = hashArray[hashIndex];
//             hashArray[hashIndex] = NULL;
//             return temp;
//         }

//         // Goto next locationa nd wrap around the table
//         ++hashIndex;
//         hashIndex %= SIZE;
//     }

//     return NULL;
// };




int main()
{

    int key = 5;
    int hashCode = gethashCode(key);
    hashArray[hashCode] = key;

    int key2 = 6;
    int hashCode2 = gethashCode(key2);
    hashArray[hashCode2] = key2;

    search(6);
}