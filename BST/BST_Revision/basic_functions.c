//
//  basic_functions.c
//  BST_Revision
//
//  Created by Surya Sahukar on 7/22/16.
//  Copyright © 2016 Surya Sahukar. All rights reserved.
//

#include "basic_functions.h"


struct node *create_node(int data)
{
    struct node *temp  =  malloc(sizeof(struct node));
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

struct node *insert_bst(struct node *root,int data)
{
    if(root == NULL)
        return(create_node(data));
    if(root != NULL && data >= root -> data && root -> right  ==  NULL)
    {
        root -> right = create_node(data);
        return root -> right;
    }
    if(root != NULL && data < root -> data && root -> left  ==  NULL)
    {
        root -> left = create_node(data);
        return root -> left;
    }
    
    
    if (data >= root -> data)
        insert_bst(root -> right,data);
    if(data<root -> data)
        insert_bst(root -> left,data);
    
    return NULL;
}


void inorder_traversal(struct node *root)
{
    if(root == NULL)
        return;
    inorder_traversal(root -> left);
    printf("inorder traversal  = %d\n",root -> data);
    inorder_traversal(root -> right);
}

void preorder_traversal(struct node *root)
{
    if(root == NULL)
        return;
    printf("preorder traversal = %d\n",root -> data);
    preorder_traversal(root -> left);
    preorder_traversal(root -> right);
}



void postorder_traversal(struct node *root)
{
    if(root == NULL)
        return;
    
    postorder_traversal(root -> left);
    postorder_traversal(root -> right);
    printf("postorder traversal = %d\n",root -> data);
}

void level_traversal(struct node *root)
{
    int h, i;
    h = height(root);
    
    for (i = 0; i < h; i++)
    {
        print_level(root, i);
    }
    
}


void print_level(struct node *root, int h)
{
    if (root == NULL)
        return;
    
    if (h == 0) {
        printf("Level Order  =  %d\n", root -> data);
        return;
    }
    
    print_level(root -> left, h-1);
    print_level(root -> right, h-1);
    
}


void print_between (struct node *root, int a, int b)
{
    int min, max;
    if (a > b)
    {
        min = b;
        max = a;
    }
    
    if (a < find_max(root) && b > find_min(root))
    {
        inorder_traversal_bounded(root, min, max);
    }
    else
    {
        printf("Error: Invalid bounds\n");
    }
}

void inorder_traversal_bounded(struct node *root,int a, int b)
{
    if(root == NULL)
        return;
    
    if(root -> data > a && root -> data < b)
        printf("inorder traversal bounded  = %d\n",root -> data);
    
    inorder_traversal(root -> right);
}

int sum_between(struct node *root, int a, int b)
{
    int sum = 0;
    int min,max;
    min = find_min(root);
    max = find_max(root);
    
    if (root  ==  NULL)
        return sum;
    if (a < min && b < min)
        return sum;
    if(a > max && b > max)
        return sum;
    
    if (root -> data > a && root -> data < b)
        sum = root -> data;
    
    if (root -> data<b)
    {
        sum  =  sum + sum_between(root -> right, a,b);
        //return sum;
    }
    if (root -> data>a)
    {
        sum  =  sum +sum_between(root -> left,a,b);
        //return sum;
    }
    
    return sum;
}






int find_max(struct node *root)
{
    if (root == NULL)
        return 0;
    else if (root -> right == NULL)
        return root -> data;
    else
        return find_max(root -> right);
}

int find_min(struct node *root)
{
    if (root == NULL)
        return 0;
    else if (root -> left == NULL)
        return root -> data;
    else
        return find_min(root -> left);
}


int height(struct node *root)
{
    int lh,rh;
    if (root == NULL)
        return 0;
    lh = height(root -> left) + 1;
    rh = height(root -> right) + 1;
    
    if (lh>rh)
        return lh;
    else
        return rh;
}

int size_bst(struct node *root)
{
    if (root == NULL)
        return 0;
    else
        return (1 + size_bst(root -> left) + size_bst(root -> left));
}

int is_balanced(struct node *root)
{
    if (root == NULL)
        return 0;
    
    int lh,rh,diff,ret;
    lh = height(root -> left);
    rh = height(root -> right);
    
    if (diff*diff <= 1)
        ret  = 1;
    else
        ret = 0;
    
    return ret;
    
    
}

int is_symmetric(struct node * root)
{
    int ret;
    
    if (!root)
        ret  =  -1;
    else
        ret  =  check_symmetric(root -> left, root -> right);
    
    return ret;
    
}
int check_symmetric(struct node *left, struct node *right)
{
    int ret;
    
    if (!left && !right)
        return 1;
    
    else if (left  ->  data == right  ->  data)
            ret  =  check_symmetric(left -> right, right -> left) && check_symmetric(left -> left, right -> right);
    else
        ret  =  -1;
    
    return ret;
}


struct node *search_bst(struct node *root, int data)
{
    struct node *temp;
    
    if (root == NULL)
    return NULL;
    
    if (root -> data == data)
        temp = root;
    
    else if (root -> data > data)
        temp = search_bst(root -> left, data);
    else if (root -> data < data)
        temp = search_bst(root -> right, data);
    
    return temp;
    
}



struct node *inorder_successor(struct node *root, int data)
{
    struct node *search, *ancestor, *successor;
    ancestor  =  root;
    successor  =  NULL;
    search  =  search_bst(root, data);
    
    if (root == NULL)
        return NULL;
    
   while ( ancestor !=  search && ancestor)
   {
       if ( ancestor -> data > search -> data)
       {
           successor  =  ancestor;
           ancestor  =  ancestor -> left;
       }
       else
           ancestor  =  ancestor -> right;
   }
    
    return successor;
    
    
}
 


