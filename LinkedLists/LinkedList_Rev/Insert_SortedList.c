//
//  Insert_SortedList.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 07/02/15.
//  Copyright (c) 2015 Surya Sahukar. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#include "linkedList.h"


struct node *Insert_SortedList(struct node * head,int data)
{
    printf("---------Insert Sorted List----------\n");
    head = bubble_sort(head);
    print_ll(head);
    struct node *curr, *next;
    curr=head;
    
    struct node *newNode;
    newNode = (struct node*) malloc(sizeof(struct node));
    
    while(curr -> next != NULL)
    {
        next = curr -> next;
        
        if (data < curr -> data) {
            newNode -> data = data;
            newNode -> next = head;
            return newNode;
        }
        if(data > curr -> data && data < next -> data) {
            newNode -> data = data;
            curr -> next = newNode;
            newNode -> next = next;
        }
        
        curr = curr -> next;
    }
    
    if(data > next -> data) {
        newNode -> data = data;
        newNode -> next = NULL;
        next -> next = newNode;
    }
        
    
    return head;
}

