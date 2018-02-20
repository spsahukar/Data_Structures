//
//  Delete_Alternate_Node.c
//  nextedList_Rev
//
//  Created by Surya Sahukar on 07/02/15.
//  Copyright (c) 2015 Surya Sahukar. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#include "linkedList.h"

struct node* Delete_Alt_Node(struct node* head)
{
    int count = 1;
    struct node *curr = head;
    struct node *next;
    while(curr -> next != NULL)
    {
        next = curr -> next;
        if(count %2 != 0) {
            curr -> next = next -> next;
            free(next);
            count++;
        }
        else {
            curr=curr -> next;
            count++;
        }
    }
    return head;
}
