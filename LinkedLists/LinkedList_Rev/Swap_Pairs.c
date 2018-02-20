//
//  Swap_Pairs.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 07/02/15.
//  Copyright (c) 2015 Surya Sahukar. All rights reserved.
//

#include <stdio.h>
#include "linkedList.h"

struct node* swap_pairs(struct node *head)
{
    printf("---------Swap Pairs----------\n");
    struct node *temp, *curr, *nextNode;
    
    if (!head) return NULL;
    if (!head -> next) return head;
    
    temp = head;
    curr = head -> next;
    nextNode = curr -> next;
    
    curr -> next = temp;
    temp -> next = swap_pairs(nextNode);
    return curr;
    
}

struct node* reverse_in_pairs(struct node *head)
{
    struct node  *revhead,*curr, *next,*temp;
    if (head==NULL)
        return NULL;
    if (head -> next==NULL)
        return head;
    
    // prev=NULL;
    curr=head;
    revhead=head -> next;
    if(curr && curr -> next)
    {
        next=curr -> next;
        temp=next -> next;
        next -> next=curr;
        curr -> next=reverse_in_pairs(temp);
        //prev=next;
        curr=temp;
    }
    return revhead;
}
