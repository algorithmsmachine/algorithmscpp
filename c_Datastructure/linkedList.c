#include<stdio.h>
#include<stdlib.h>

struct LinkedinListNode{
    int val;
    struct LinkedinListNode *next;
};

void insertFirst(struct LinkedinListNode **head, int val){
    struct LinkedinListNode *newNode = (struct LinkedinListNode *)malloc(sizeof(struct LinkedinListNode));
    newNode->val = val;
    newNode->next = *head;
    *head = newNode;
}


void insertLast(struct LinkedinListNode **head, int val){
    struct LinkedinListNode *newNode = (struct LinkedinListNode *)malloc(sizeof(struct LinkedinListNode));
    newNode->val = val;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct LinkedinListNode *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}


void deleteFirst(struct LinkedinListNode **head){
    if(*head == NULL){
        return;
    }
    struct LinkedinListNode *temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteLast(struct LinkedinListNode **head){
    if(*head == NULL){
        return;
    }
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    struct LinkedinListNode *temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

int main(){
    struct LinkedinListNode *head = NULL;
    insertFirst(&head, 1);
    insertFirst(&head, 2);
    insertFirst(&head, 3);
    insertLast(&head, 4);
    insertLast(&head, 5);
    insertLast(&head, 6);
    struct LinkedinListNode *temp = head;
    while(temp != NULL){
        printf("%d\n", temp->val);
        temp = temp->next;
    }
    return 0;
}