//
//  constant_time_traversal.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 5/9/17.
//  Copyright © 2017 Surya Sahukar. All rights reserved.
//

#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
struct node* const_time_traversal(struct node *head, int n)
{
    int length;
    struct node *curr = head;
    length = count(curr);
    
    if (n > length)
        return NULL;
    
    struct node *ptr[length];
    
    ptr[0] = head;
    
    return ptr[n];
    
    
}
