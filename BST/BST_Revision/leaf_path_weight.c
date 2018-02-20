//
//  leaf_path_weight.c
//  BST_Revision
//
//  Created by Surya Sahukar on 8/2/16.
//  Copyright © 2016 Surya Sahukar. All rights reserved.
//

#include "leaf_path_weight.h"

int path_weight  = 0;
int leaf_array[10];
int idx = 0;
int leaf_path_weight(struct node *root, int leaf_value)
{
    path_weight = 0;
    
    if (!root)
        return 0;
    
    if ( (root -> left || root -> right) && (root -> data == leaf_value) )
    {
        path_weight = 0;
        return 0;
    }
    
    if (!(root ->left) && !(root -> right))
        return ( path_weight + root -> data);
    
    if (root -> data > leaf_value)
        path_weight = path_weight + root -> data + leaf_path_weight(root -> left, leaf_value);
    else
        path_weight = path_weight + root -> data + leaf_path_weight(root -> right, leaf_value);
    
    return path_weight;
    
}

int find_all_leaves (struct node *root)
{
    if (!root)
        return 0;
    
    if (!root -> left && !root -> right)
    {
        leaf_array[idx] = root -> data;
        idx++;
        return idx;
    }
    
    if (root -> left)
    {
        find_all_leaves(root -> left);
    }
    
    if (root -> right)
    {
        find_all_leaves(root -> right);
    }
    
    return idx;
    
}

struct node *find_leaf_of_given_path_weight (struct node *root, int given_path_weight)
{
    int leaf_array_size;
    struct node *found_leaf_node;
    found_leaf_node = (struct node *) malloc(sizeof(struct node));
    leaf_array_size = 0;
    leaf_array_size = find_all_leaves(root);
    
    for (int j = 0; j < leaf_array_size; j++)
    {
        if ( leaf_path_weight(root, leaf_array[j]) == given_path_weight )
        {
            found_leaf_node = search_bst(root, leaf_array[j]);
            break;
        }
    }
    
    return found_leaf_node;
}
