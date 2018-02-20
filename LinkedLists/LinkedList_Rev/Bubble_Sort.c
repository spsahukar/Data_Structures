//
//  Bubble_Sort.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 07/02/15.
//  Copyright (c) 2015 Surya Sahukar. All rights reserved.
//

#include <stdio.h>
#include "linkedList.h"


struct node* bubble_sort(struct node* head)
{
    printf("--------- Bubble Sort----------\n");
    int cnt = count(head);
    int lcnt = 0;
    struct node *p,*q;
    p = head;
    q = head -> next;
    
    for (int i= cnt-1; i > 0; i--) {
        while(q != NULL && lcnt <= i) {
            if(p -> data > q -> data) {
                int temp = p -> data;
                p -> data = q -> data;
                q -> data = temp;
            }
            q = q -> next; p = p -> next;lcnt++;
        }
        lcnt = 0;
        p = head;
        q = head -> next;
    }
    return head;
}
