//
//  selection_sort.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 7/21/16.
//  Copyright © 2016 Surya Sahukar. All rights reserved.
//

#include <stdio.h>
#include "linkedList.h"
#include "limits.h"

struct node* min_node(struct node* head)
{
    if (!head) return NULL;
    if (!head -> next) return head;
    
    struct node *min, *curr;
    min = head; curr = head;
    
    while(curr)
    {
        if (curr -> data < min -> data)
            min = curr;
        curr = curr -> next;
    }
    
    return min;
}

struct node* selection_sort(struct node* head)
{
    if (!head) return NULL;
    
    int len = count(head);
    struct node *min, *curr;
    curr = head;
    
    for (int i = 0; i < len - 1 ; i++)
    {
        int k = 0;
        curr = head;
        while (curr && k < i)
        {
            curr = curr -> next;
            k++;
        }
        min = min_node(curr);
        if (min -> data < curr -> data)
        {
            int temp;
            temp = min -> data;
            min -> data = curr -> data;
            curr -> data = temp;
        }
        
    }
    
    return head;
}




/*   Working but complex algo


struct node * selection_sort(struct node * head)
{
    struct node *minptr=NULL;
    struct node *temphead,*innerloophead;
    int len = count(head);
    int mindata=INT_MAX;
    int temp;
    temphead=head;
    int j;
    int flag=0;
    
    for (int i=0; i< len;i++)
    {
        head=temphead;
        j=0;
        flag=0;
        mindata=INT_MAX;
        while(j<i)
        {
            head=head -> next;
            j++;
        }
        
        innerloophead=head;
        //mindata=head->data;
        while(head)
        {
            if(head->data<mindata)
            {
                mindata=head->data;
                minptr=head;
                flag=1;
                
            }
            head=head -> next;
        }
        
        if(flag)
        {
            temp=minptr->data;
            minptr->data=innerloophead->data;
            innerloophead->data=temp;
        }
        
    }
    
    return temphead;
}

*/
