#include <stdlib.h>
#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1,
                               struct ListNode *l2)
{
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;

        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if(carry > 0)
    {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = carry;
        newNode->next = NULL;
        tail->next = newNode;
    }
    
    return head;
}

int main()
{
    // addTwoNumbers( NULL, NULL);
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->val = 2;
    l1->next = NULL;

    struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->val = 4;
    l2->next = NULL;

    struct ListNode *l3 = addTwoNumbers(l1, l2);

    while (l3 != NULL)
    {
        printf("%d\n", l3->val);
        l3 = l3->next;
    }

    return 0;
}