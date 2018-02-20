//
//  Find_Middle_Node.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 05/03/15.
//  Copyright (c) 2015 Surya Sahukar. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#include "linkedList.h"

struct node* FindMiddle(struct node* head)
{
    struct node *nearPtr, *farPtr;
    farPtr = head;nearPtr = head;
    
    while (farPtr != NULL)
    {
        farPtr = farPtr -> next;
        if (farPtr != NULL)
        {
            nearPtr = nearPtr -> next;
            farPtr = farPtr -> next;
        }
    }
    
    return nearPtr;
}

