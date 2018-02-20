//
//  Basic_Functions.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 07/02/15.
//  Copyright (c) 2015 Surya Sahukar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "linkedList.h"

struct node * create_head(int value)
{
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = value;
    newnode-> next = NULL;
    return newnode;
}

pthread_mutex_t pmtx = PTHREAD_MUTEX_INITIALIZER;

struct node * insert_node_at_tail( struct node *head, int val)
{
    //printf("---------Inserting----------\n");
    int counter=0;
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode -> data = val;
    newnode -> next = NULL;
    
    pthread_mutex_lock(&pmtx);
    if (head == NULL) {
        head = newnode;
        return (newnode);
    }
    else {
        while(head-> next!=NULL) {
            // printf("insert_node element %d from head =%d\n",counter,head->data);
            head = head -> next;
            counter++;
        }
        
    }
    head -> next = newnode;
    //printf ("newnode %d is inserted at address %p end of the linked_list\n",head->data,head);
    pthread_mutex_unlock(&pmtx);
    return ( newnode);
}

/*
 Always pass double pointer while inserting at head
 
 https://stackoverflow.com/questions/7271647/what-is-the-reason-for-using-a-double-pointer-when-adding-a-node-in-a-linked-lis
 
 void insert_at_head(struct node** head, int val)
 {
 struct node *newnode = (struct node *) malloc(sizeof(struct node));
 newnode->data = val;
 newnode-> next = *head;
 *head = newnode;
 }

 */


struct node* insert_at_head(struct node* head, int val)
{
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode -> data = val;
    pthread_mutex_lock(&pmtx);
    newnode -> next = head;
    pthread_mutex_unlock(&pmtx);
    return newnode;
}


void print_ll(struct node* head)
{
    //printf("---------Printing----------\n");
    int counter = 0;
    while (head != NULL)
    {
        printf("element %d from head =%d and its address = %p\n",counter,head->data,head);
        head = head -> next;
        counter++;
    }
}

int count(struct node * head)
{
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head -> next;
    }
    return cnt;
}

struct node * removeAll(int val, struct node *head) {
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *next = NULL;
    
    while(curr) {
        next = curr -> next;
        if (curr -> data == val)
        {
            
            if (prev)
            {
                prev -> next = next;  
            }
            else
            {
                head = next;
            }
            free(curr);
        }
        
        prev = curr;
        curr = next;
    }
    
    return head;
    
}

