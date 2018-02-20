//
//  zipper.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 7/30/16.
//  Copyright © 2016 Surya Sahukar. All rights reserved.
//

#include <stdio.h>
#include "linkedList.h"

struct node* zipper( struct node *head)
{
    int size;
    size = count(head);
    struct node *curr, *tail;
    
    curr = head;
    
    if ( size >= 2 )
    {
        curr = zip_two_nodes(curr);
        tail = curr -> next;
        tail -> next = zip_two_nodes(tail -> next);
        
    }
    
    return head;
    
}


struct node * zip_two_nodes(struct node * ziphead)
{
    struct node *prev, *curr, *temp;
    
    prev = NULL;
    curr = ziphead;
    
    while(curr -> next)
    {
        prev = curr;
        curr = curr -> next;
    }
    
    temp = ziphead -> next;
    ziphead -> next = curr;
    prev -> next = NULL;
    curr -> next = temp;
    
    return ziphead;
}
