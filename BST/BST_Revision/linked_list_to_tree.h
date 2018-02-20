//
//  linked_list_to_tree.h
//  BST_Revision
//
//  Created by Surya Sahukar on 7/24/16.
//  Copyright © 2016 Surya Sahukar. All rights reserved.
//

#ifndef linked_list_to_tree_h
#define linked_list_to_tree_h

#include <stdio.h>
#include <stdlib.h>
#include "basic_functions.h"

struct ll_node {
    int data;
    struct ll_node *next;
};
struct ll_node *insert_ll_node_at_tail( struct ll_node *, int);
struct ll_node *create_head(int);
int *sort_array(int *, int);
struct node *linked_list_to_tree(struct ll_node * );

#endif /* linked_list_to_tree_h */
