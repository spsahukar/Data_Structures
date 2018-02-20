//
//  linked_list_to_tree.c
//  BST_Revision
//
//  Created by Surya Sahukar on 7/24/16.
//  Copyright © 2016 Surya Sahukar. All rights reserved.
//


#include "linked_list_to_tree.h"


struct ll_node *create_head(int val)
{
    struct ll_node *newll_node = (struct ll_node *) malloc(sizeof(struct ll_node));
    newll_node -> data = val;
    newll_node -> next = NULL;
    return newll_node;
}

struct ll_node *insert_ll_node_at_tail( struct ll_node *head, int val)
{
   // printf("---------Inserting----------\n");
    struct ll_node *newll_node = malloc(sizeof(struct ll_node));
    newll_node -> data = val;
    newll_node -> next = NULL;
    
    if (head == NULL)
    {
        head = newll_node;
        return (newll_node);
    }
    else
    {
        while(head->next != NULL)
        {
            // printf("insert_ll_node element %d from root =%d\n",counter,root->data);
            head = head->next;
        }
        
    }
    head->next = newll_node;
    //printf ("newll_node %d is inserted at address %p end of the linked_list\n",root->data,root);
    return ( newll_node);
}


int *sort_array(int *array, int len)
{
    int i,j;
    int minindex;
    int temp;
    
    i=0;
    j=0;
    
    for (i = 0; i < len ; i++)
    {
        minindex =i;
        for (j = i; j < len; j++ )
        {
            if (array[j] < array[i])
                minindex = j;
        }
        
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        
    }
    
    
    return array;
    
}


struct node *create_tree ( int *array, int start, int end)
{
    if (start > end)
        return NULL;
    
    struct node *newNode = malloc(sizeof(struct node));
    int mid;
    
    mid = ( start + end ) / 2;
    
    newNode->data = * (array + mid);
    newNode->left = create_tree(array, start, mid - 1);
    newNode->right = create_tree(array, mid + 1, end);
    
    return newNode;

}


struct node *linked_list_to_tree(struct ll_node * head)
{
    int count;
    int i;
    struct ll_node *temphead;
    temphead = head;
    
    
    count =0;
    i =0;
    
    while(head)
    {
        count++;
        head = head -> next;
    }
    
    int array[count];
    int *sorted_array;
    head = temphead;
    
    
    while (head)
    {
        array[i] = head->data;
        i++;
        head = head -> next;
    }
    
    for (int k = 0; k < count; k++)
        printf("Created Array A[%d] = %d\n", k, array[k]);
    
    
    sorted_array = sort_array(array, count);
    
    for (int k = 0; k < count; k++)
        printf("Sorted Array A[%d] = %d\n", k, sorted_array[k]);
    
    struct node *root = create_tree(sorted_array, 0, count - 1);
    
    return root;
    
    
}















