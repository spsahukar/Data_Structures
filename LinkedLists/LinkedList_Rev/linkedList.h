//
//  linkedList.h
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 07/02/15.
//  Copyright (c) 2015 Surya Sahukar. All rights reserved.
//

#ifndef LinkedList_Rev_linkedList_h
#define LinkedList_Rev_linkedList_h

#include <stdio.h>


struct node {
    int data;
    struct node *next;
};

struct node * removeAll(int, struct node *);
struct node * reverse_ll_method1(struct node *);
struct node *reverse_ll_method2(struct node *);
struct node * insert_node_at_tail( struct node *, int);
void reverse_recursive(struct node *);
struct node * insert_at_head(struct node*, int);
struct node * create_head(int);
int count(struct node*);
struct node *sort(struct node**);
void print_ll(struct node*);
int reversePrint(struct node *);
void reversePrint_new(struct node *);
void sort_ll(struct node*);
struct node * bubble_sort(struct node *);
struct node *swap_pairs(struct node*);
struct node * reverse_in_pairs(struct node *);
struct node *RighShift(struct node * );
struct node * LeftShift(struct node *);
struct node *ReverseKBlocks(struct node *, int);
struct node *ReverseBetween(struct node *, struct node *);
struct node *Reverse_K_nodes(struct node *, int );

/* Remove Duplicates */
struct node *Remove_Duplicates(struct node *);
struct node *remove_duplicates(struct node *);


struct node *Insert_SortedList(struct node *, int);
struct node * Delete_Alt_Node(struct node * );
struct node * FindMiddle(struct node *);

/* Merge Sort Functions */
struct node * merge_sort(struct node *);
struct node * merge_left_right(struct node *, struct node *, struct node *);

/* Selection Sort*/

struct node * selection_sort(struct node *);
struct node *min_node(struct node *);

/*Zipping 1 linkedlist */

struct node * zipper( struct node *);
struct node * zip_two_nodes(struct node *);

/* Zipping 2 linked lists*/

struct node * zip_two_linked_lists(struct node *, struct node *);

/* Median of Cirucular linked list */

struct node * create_circular (struct node *);
int median_circular ( struct node *);

/* Odd Even Merge of single linked list */

struct node * odd_even_merge(struct node *);

/* Find Intersection */

struct node * find_intersection_two_linked_lists ( struct node *, struct node *);

int find_gcd(int, int);

struct node * step_n( struct node *, int);

/* Add numbers represented by linked list */

struct node * add_numbers_linked_list(struct node *, struct node *);

/* Constant Time Traversal */
struct node * const_time_traversal(struct node *, int);



#endif
