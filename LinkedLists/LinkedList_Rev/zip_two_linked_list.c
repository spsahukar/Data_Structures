//
//  zip_two_linked_list.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 7/30/16.
//  Copyright © 2016 Surya Sahukar. All rights reserved.
//

#include <stdio.h>
#include "linkedList.h"

struct node* zip_two_linked_lists(struct node *head1, struct node *head2)
{
    struct node *revhead, *curr1, *curr2, *temp1, *temp2;
    revhead = head1;
    curr1 = head1;
    curr2 = head2;
    
    while(curr1 && curr2)
    {
        temp1 = curr1 -> next;
        temp2 = curr2 -> next;
        
        curr1 -> next = curr2;
        curr2 -> next = temp1;
        
        curr1 = temp1;
        curr2 = temp2;
        
    }
    

    return revhead;
}
