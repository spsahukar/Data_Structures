//
//  median_circular_linked_list.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 7/30/16.
//  Copyright © 2016 Surya Sahukar. All rights reserved.
//

#include <stdio.h>
#include "linkedList.h"

struct node* create_circular (struct node *head)
{
    struct node *curr;
    
    curr = head;
    
    while(curr -> next != NULL)
        curr = curr -> next;
    
    curr -> next = head;
    
    return head;
}
int median_circular ( struct node *anynode)
{
    struct node *head;
    struct node *next;
    
    int size, isodd;
    
    int counter;
    
    int median;
    
    next = anynode -> next;
    
    while( anynode -> data <= next -> data)
    {
        anynode = next;
        next = anynode -> next;
    }
    
    head = next;
    
    
    anynode -> next = NULL;
    
   // head = selection_sort(head);
    
    size = count(head);
    
    if (size%2)
        isodd = 1;
    else
        isodd = 0;
    
    
    counter = 0;
    
    while (counter < (size) /2)
    {
        head = head -> next;
        counter++;
    }
    
    if (isodd)
    {
        median = head -> data;
    }
    
    else
    {
        median = ( head -> data + head -> next -> data)/2;
    }
    
    
    return median;
    
    
}
