#include<stdio.h>
#include<stdlib.h>

struct DoubleLinkedList{
    int val;
    struct DoubleLinkedList *next;
    struct DoubleLinkedList *prev;
};

void insertFirst(struct DoubleLinkedList **head, int val){
    struct DoubleLinkedList *newNode = (struct DoubleLinkedList *)malloc(sizeof(struct DoubleLinkedList));
    newNode->val = val;
    newNode->next = *head;
    newNode->prev = NULL;
    if(*head != NULL){
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void  insertLast(struct DoubleLinkedList **head, int val){
    struct DoubleLinkedList *newNode = (struct DoubleLinkedList *)malloc(sizeof(struct DoubleLinkedList));
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct DoubleLinkedList *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
