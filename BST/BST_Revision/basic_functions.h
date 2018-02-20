//
//  basic_functions.h
//  BST_Revision
//
//  Created by Surya Sahukar on 7/22/16.
//  Copyright © 2016 Surya Sahukar. All rights reserved.
//

#ifndef basic_functions_h
#define basic_functions_h

#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *create_node(int);
struct node *insert_bst(struct node *,int);
void inorder_traversal(struct node *);
void preorder_traversal(struct node *);
void postorder_traversal(struct node *);
void level_traversal(struct node *);
void print_level(struct node *, int);
void print_between(struct node *,int, int);
void inorder_traversal_bounded(struct node *,int, int);
int sum_between(struct node *, int, int);
int find_min(struct node *);
int find_max(struct node *);
int size_bst(struct node *);
int height(struct node *);
int is_balanced(struct node *);

int is_symmetric(struct node *);
int check_symmetric(struct node *, struct node *);

struct node *search_bst(struct node *, int );
struct node *inorder_successor(struct node *, int);

#endif /* basic_functions_h */
