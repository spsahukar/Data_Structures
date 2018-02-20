//
//  odd_even_merge.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 7/30/16.
//  Copyright © 2016 Surya Sahukar. All rights reserved.
//

#include <stdio.h>
#include "linkedList.h"

struct node* odd_even_merge(struct node *head)
{
    if (head == NULL)
        return NULL;
    if (count(head) < 3)
        return head;
    
    
    struct node *odd, *even, *tempodd, *tempeven, *revhead;
    
    revhead = head;
    tempeven = head;
    tempodd = head -> next;
    even = head;
    odd = head -> next;
    
    while (odd && even && odd -> next != NULL && odd -> next -> next != NULL)
    {
        even -> next = odd -> next;
        even = even -> next;
        odd -> next = even -> next;
        odd = odd -> next;
    }
    
    if ( odd -> next == NULL)
    {
        even -> next = NULL;
        odd -> next = NULL;
    }
    
    if ( odd -> next != NULL && odd -> next -> next == NULL)
    {
        even -> next = odd -> next;
        odd -> next = NULL;
    }
    
    even = tempeven;
    
    while (even -> next != NULL )
        even = even -> next;
    
    even -> next = tempodd;
    
    return  revhead;
    
    
    
}
