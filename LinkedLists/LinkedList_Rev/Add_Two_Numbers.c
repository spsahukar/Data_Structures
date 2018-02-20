//
//  Add_Two_Numbers.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 07/02/15.
//  Copyright (c) 2015 Surya Sahukar. All rights reserved.
//
/*Input:
 First List: 5->6->3  // represents number 563
 Second List: 8->4->2 //  represents number 842
 Output
 Resultant list: 1->4->0->5  // represents number 1405
 */

#include <stdio.h>
#include<stdlib.h>
#include "linkedList.h"
struct node * Add_Two_Num_LL(struct node *, struct node *);

#if 0
int main(int argc, const char * argv[])
{
    struct node *head1,*head2,*head3;
    head1 = create_root(5);
    insert_node_at_tail(head1, 6);
    insert_node_at_tail(head1, 3);
    print_ll(head1);
    head2 = create_root(8);
    insert_node_at_tail(head2, 4);
    insert_node_at_tail(head2, 2);
    print_ll(head2);
    head3 = Add_Two_Num_LL(head1, head2);
    return 0;
}

#endif

struct node* Add_Two_Num_LL(struct node *head1, struct node *head2)
{
    struct node *head3 = (struct node *) malloc(sizeof(struct node));
    head3 -> data = 0;
    struct node *head3_temp = head3;
    head1 = reverse_ll_method1(head1);
    head2 = reverse_ll_method1(head2);
    print_ll(head1);
    print_ll(head2);
    
    while(head1 != NULL && head2 != NULL) {
        head3 -> data = head3 -> data + head1 -> data + head2->data;
        if (head3 -> data >= 10)
        {
            struct node *newNode = (struct node *) malloc(sizeof(struct node));
            newNode -> data = head3 -> data / 10;
            newNode -> next = NULL;
            head3 -> next = newNode;
            head3 -> data = head3 -> data % 10;
            head1 = head1 -> next;
            head2 = head2 -> next;
            head3 = head3 -> next;
        }
        else
        {
        struct node *newNode = (struct node *) malloc(sizeof(struct node));
        newNode -> data = 0;
        newNode -> next = NULL;
        head3 -> next = newNode;
        head1=head1 -> next;
        head2=head2 -> next;
        head3=head3 -> next;
        }
    }
    
    if (head1)
    {
        head3 -> data = head3 -> data + head1->data;
        if (head3 -> data >= 10)
        {
            struct node *newNode = (struct node*) malloc(sizeof(struct node));
            newNode -> data = head3 -> data / 10;
            newNode -> next = NULL;
            head3 -> next = newNode;
            head3 -> data = head3 -> data % 10;
        }

    }
    
    if (head2)
    {
        head3 -> data = head3 -> data + head2 -> data;
        if (head3 -> data >= 10)
        {
            struct node *newNode = (struct node*) malloc(sizeof(struct node));
            newNode -> data = head3 -> data / 10;
            newNode -> next = NULL;
            head3 -> next = newNode;
            head3 -> data = head3 -> data % 10;
        }
        
    }
    
    head3_temp = reverse_ll_method1(head3_temp);
    print_ll(head3_temp);
    return head3_temp;
    
}

/** New problem from the Elements of Programming 8.18 */
struct node* add_numbers_linked_list(struct node *head1, struct node *head2)
{
    struct node *result, *curr1, *curr2;
    int sum, carry;
    
    carry = 0;
    curr1 = head1;
    curr2 = head2;
    result = (struct node *) malloc(sizeof(struct node));
    
    sum = (carry + curr1 -> data + curr2 -> data) % 10;
    carry = (carry + curr1 -> data + curr2 -> data) / 10;
    
    result = create_head (sum);
    
    curr1 = curr1 -> next;
    curr2 = curr2 -> next;
    
    while ( curr1 && curr2 )
    {
        sum = (carry + curr1 -> data + curr2 -> data) % 10;
        carry = (carry + curr1 -> data + curr2 -> data) / 10;
        insert_node_at_tail(result, sum);
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }
    
    while (curr1)
    {
        sum = (carry + curr1 -> data ) % 10;
        carry = (carry + curr1 -> data ) / 10;
        insert_node_at_tail(result, sum);
        curr1 = curr1  -> next;
        
    }
    
    while (curr2)
    {
        sum = (carry + curr2 -> data ) % 10;
        carry = (carry + curr2 -> data ) / 10;
        insert_node_at_tail(result, sum);
        curr2 = curr2  -> next;
    }
    
    if (carry)
        insert_node_at_tail(result, carry);
    
    return result;
}






































