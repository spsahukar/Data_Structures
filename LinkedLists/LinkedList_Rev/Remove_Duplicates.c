//
//  Remove_Duplicates.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 07/02/15.
//  Copyright (c) 2015 Surya Sahukar. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#include "linkedList.h"


struct node* Remove_Duplicates(struct node *head)
{
    printf("---------Remove Duplicates----------\n");
    head=bubble_sort(head);
    struct node *headtemp = head;
    print_ll(head);
    struct node *temp;
    while(head -> next!=NULL) {
        temp = head -> next;
        if (head->data == temp->data)
        {
            head -> next = temp -> next;
            free(temp);
        }
        else
            head = head -> next;
        
    }
    return headtemp;
}

struct node* remove_duplicates(struct node *head)
{
    if (!head) return NULL;
    int hash[100] = { 0 };
    
    struct node *curr;
    struct node *prev = NULL;
    struct node *next = NULL;
    
    curr = head;
    
    while(curr)
    {
        hash [curr -> data] = 1;
        curr = curr -> next;
    }
    
    curr = head;
    
    while(curr)
    {
        if (!hash[curr -> data])
        {
            prev -> next = curr -> next;
            next = curr -> next;
            free(curr);
            curr = next;
        }
        else
        {
            hash[curr -> data] = 0;
            prev = curr;
            curr = curr -> next;
        }
        
        
    }
    
    return head;
    
    
    
}

