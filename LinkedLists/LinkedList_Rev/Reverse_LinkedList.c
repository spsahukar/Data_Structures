//
//  Reverse_LinkedList.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 07/02/15.
//  Copyright (c) 2015 Surya Sahukar. All rights reserved.
//

#include <stdio.h>
#include "linkedList.h"

// Using another linked list
struct node* reverse_ll_method1(struct node *head)
{
    printf("---------Reversing----------\n");
    struct node *revhead, *temp;
    revhead= NULL;
    
    while (head != NULL)
    {
        temp = revhead;
        revhead = head;
        head = head -> next;
        revhead -> next = temp;;
    }
    return (revhead);
}
// Reverseing my changing links
struct node* reverse_ll_method2(struct node *head)
{
    printf("---------Reversing Method2----------\n");
    struct node *next, *prev, *current;
    prev = NULL;
    current = head;
    while(current != NULL)
    {
        next = current -> next;
        current -> next=prev;
        prev = current;
        current = next;
    }
    return prev;
}

int reversePrint(struct node *head)
{
    if (!head)
        return 0;
    reversePrint(head -> next);
    printf("Reverse print: %d\n", head -> data);
    return 0;
}



static struct node * rev_head;
void reverse_recursive(struct node *head)
{
    printf("---------Reversing Recursive----------\n");
    if (head -> next==NULL) {
        rev_head=head;
        return;
    }
    reverse_recursive(head -> next);
    
    struct node *temp;
    temp=head -> next;
    temp -> next=head;
    head -> next=NULL;
}
