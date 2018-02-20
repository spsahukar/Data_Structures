//
//  RevKBlocks.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 07/02/15.
//  Copyright (c) 2015 Surya Sahukar. All rights reserved.
//

#include <stdio.h>
#include "linkedList.h"

/*

struct node *ReverseBetween(struct node *p, struct node *q)
{
    struct node *temp;
    struct node *root;
    struct node *tempq;
    if(q) {
        tempq=q -> next;
        q -> next=NULL;
    }
    temp=reverse_ll_method1(p);
    root=temp;
    //print_ll(temp);
    while(temp -> next!=NULL)
        temp=temp -> next;
    if(q)
        temp -> next=tempq;
    else
        temp -> next=NULL;
    //print_ll(root);
    return root;
}
struct node *ReverseKBlocks(struct node *root, int k)
{
    printf("--------- Reverse K Blocks----------\n");
    int i=count(root);
    if (root==NULL)
        return NULL;
    if(i<k)
        return root;
    
    struct node *p,*q,*temp;
    int cnt=0;
    p = root;
    
    while(cnt<k-1) {
        p=p -> next;
        cnt++;
    }
    
    q=p;
    p=root;
    root = ReverseBetween(p,q);
    temp=root;
    while(root!=p)
        root=root -> next;
    root -> next=ReverseKBlocks(root -> next,k);
    root=temp;
    return root;
    
}

 
 */

struct node* Reverse_K_nodes(struct node *head, int k)
{
    struct node *curr, *prev, *next;
    struct node *revhead;
    int count = 0;
    prev = NULL;
    next = NULL;
    curr = head;
    
    while(curr && count < k)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    revhead = prev;
    
    
    if (next)
    {
        head -> next = Reverse_K_nodes(next, k);
    }
    
    return revhead;
    
}


