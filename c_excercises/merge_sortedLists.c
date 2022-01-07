#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

// function to ads a node at the begining of a linkedin list
void push(struct ListNode **head_ref, int new_data)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->val = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// function to print a linked list
void printList(struct ListNode *node)
{
    while (node != NULL)
    {
        printf("%s ", node->val);
        node = node->next;
    }
    printf("\n");
}

struct ListNode *sortedmergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    /* if either list runs out, use the other list */
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    // struct ListNode *head = NULL;
    // struct ListNode *tail = NULL;

    
    if(list1->val <= list2->val)
    {
        list1->next = sortedmergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = sortedmergeTwoLists(list1, list2->next);
        return list2;
    }
}

int main()
{
    ListNode *list1 = NULL;
    push(&list1, 15);
    push(&list1, 20);
    push(&list1, 30);

    ListNode *list2 = NULL;
    push(&list2, 2);
    push(&list2, 3);
    push(&list2, 50);

    list2->val = 5;
    list2->next = NULL;

    list1->val = 1;
    list1->next = list2;

    printList(sortedmergeTwoLists(list1, list2));
    return 0;
}