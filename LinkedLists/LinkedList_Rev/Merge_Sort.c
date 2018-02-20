//
//  Merge_Sort.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 07/21/16.
//  Copyright (c) 2015 Surya Sahukar. All rights reserved.
//


#include <stdio.h>
#include "linkedList.h"


struct node * merge_sort(struct node *head)
{
    struct node *left, *right,*temphead,*templeft,*tempright;
    int len,mid,i;
    len=count(head);
    mid = len/2;
    i=0;
    temphead=head;


    
    if (head==NULL) return NULL;
    if (head -> next==NULL) return head;
   
    
    while (i<mid)
    {
        if (i==0)
        {
            left=create_head(head->data);
            templeft=left;
        }
        else
        {
            left -> next= insert_node_at_tail(templeft,head->data);
            left=left -> next;
            
        }
        head=head -> next;
        i++;
    }
    
    
    left -> next=NULL;
    left=templeft;
    
    i=mid;
    tempright=head;
    while (i<len)
    {
        if (i==mid)
        {
            right=create_head(head -> data);
            tempright=right;
        }
        else
        {
            right -> next= insert_node_at_tail(tempright,head -> data);
            right=right -> next;
            
        }
        head=head -> next;
        i++;

    }
    
    right -> next=NULL;
    right=tempright;

    printf("left linkedlist \n");
    print_ll(left);
    printf("right linkedlist \n");
    print_ll(right);

    left=merge_sort(left);
    right=merge_sort(right);
    
    head=temphead;
    
    merge_left_right(head, left, right);
    return head;
}

struct node * merge_left_right( struct node * head, struct node *left, struct node *right)
{

 //   int nL, nR,i,j,k;
  //  nL=count(left);
   // nR=count(right);
    //i=0;j=0;k=0;
    
    struct node *temphead,*templeft,*tempright;
    temphead=head;
    templeft=left;
    tempright=right;
    
    if (left ==NULL && right == NULL)
        return temphead;
/*
    if (left==NULL)
    {
        (head)->data=right->data;
        head=(head) -> next;
        right=right -> next;
        return temphead;
        
    }
    
    if (right==NULL)
    {
        (head)->data=left->data;
        head=(head) -> next;
        left=left -> next;
        return temphead;
        
    }
    
 */
    while(left!=NULL && right!=NULL)
    {
        if (left->data < right->data)
        {
            (head)->data=left->data;
            head=(head) -> next;
            left=left -> next;
            
        }
        else
        {
            (head)->data=right->data;
            head=(head) -> next;
            right=right -> next;
            
        }
        
    }
    while(left)
    {
        (head)->data=left->data;
        head=(head) -> next;
        left=left -> next;
    }
    
    while(right)
    {
       (head)->data=right->data;
        head=(head) -> next;
        right=right -> next;
    }
    
    printf("temphead\n");
    print_ll(temphead);

    
    return temphead;
    
}

