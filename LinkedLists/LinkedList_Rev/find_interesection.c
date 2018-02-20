
//
//  find_interesection.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 7/30/16.
//  Copyright © 2016 Surya Sahukar. All rights reserved.
//

#include <stdio.h>
#include "linkedList.h"

int find_gcd(int a, int b)
{
    while(a != b)
    {
        if(a > b)
            a =  a - b;
        else
            b = b - a ;
    }
    
    return a;
}

struct node * step_n( struct node * head, int n)
{
    int cnt;
    cnt = 0;
    
    while(cnt != n && head)
    {
        head = head -> next;
        cnt++;
    }
    
    return head;
    
}
/*
struct node * find_intersection_two_linked_lists ( struct node * head1, struct node * head2)
{
    int size1, size2;
    int step;
    
    int found, foundprev;
    struct node *common;
    struct node *temphead1, *temphead2;
    
    
    found = 0; foundprev =0;
    
    common = NULL;
    temphead1 = head1;
    temphead2 = head2;
    
    
    size1 = count (head1);
    size2 = count (head2);
    
    step = find_gcd(size1 - 1 ,size2 - 1  );
    
    if (head1 == head2)
    {
        found = 1;
        common = head1;
        return head1;
    }
    
    while (head1 && head2 && step >= 1)
    {
        switch(step)
        {
        
            case 5:
            {
                head1 = step_n(head1, 5);
                head2 = step_n(head2, 5);
                break;
                
            }
            case 4:
            {
                head1 = step_n(head1, 4);
                head2 = step_n(head2, 4);
                break;
            }
            case 3:
            {
                head1 = step_n(head1, 3);
                head2 = step_n(head2, 3);
                break;
            }
            case 2:
            {
                head1 = step_n(head1, 2);
                head2 = step_n(head2, 2);
                break;
            }
            default:
            {
                head1 = step_n(head1, 1);
                head2 = step_n(head2, 1);
                break;
            }
        }
        
        if (head1 == head2)
        {
            found = 1;
            common = head1;
        }
        
       // head1 = temphead1;
       // head2 = temphead2;
        
        if (!found && foundprev)
        {
            return common;
        }
        
        if ( found )
        {
            step = step / 2;
            foundprev = 1;
            found = 0;
        }
        
        
    }
    
    return common;
    
    
}

*/

struct node* find_intersection_two_linked_lists ( struct node *head1, struct node *head2)
{
    int size1, size2;
    
    size1 = count(head1);
    size2 = count(head2);
    
    
    int array1[20];
    int array2[20];
    
    int i, j, k, cidx;
    
    struct node *curr1, *curr2;
    
    i = 0;k = 0;
    curr1 = head1;
    curr2 = head2;
    
    while (curr1  && i < size1)
    {
        array1[i] = curr1 -> data;
        i++;
        curr1 = curr1 -> next;
    }
    
    i = 0;
    
    while ( curr2 && i < size2)
    {
        array2[i] = curr2 -> data;
        i++;
        curr2 = curr2 -> next;
    }
    
    
    for ( i = size1 - 1, j = size2 - 1; i >= 0, j >= 0; i--, j--)
    {
        if (array1[i] != array2[j])
        {
            printf("i = %d, j= %d\n", i, j);
            cidx = i;
        }
    }
    
    
    curr1 = head1;
    
    while ( k <= cidx && curr1)
    {
        curr1 = curr1 -> next;
        k++;
    }
    
    return curr1 -> next;
    
}
