//
//  Left_Right_Shift.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 07/02/15.
//  Copyright (c) 2015 Surya Sahukar. All rights reserved.
//

#include <stdio.h>
#include "linkedList.h"
struct node* RighShift(struct node * head)
{
    printf("---------Right Shift----------\n");
    struct node *temp,*tempprev;
    temp = head;
    
    while(temp -> next != NULL) {
        tempprev = temp;
        temp=temp -> next;
    }
    
    tempprev -> next = NULL;
    
    temp -> next = head;
    
    head = temp;
    
    return head;
}

struct node* LeftShift(struct node *head)
{
    struct node *temp,*temphead;
    temp=head;
    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    
    temp -> next=head;
    temphead=head -> next;
    head -> next = NULL;
    return temphead;
    
}


