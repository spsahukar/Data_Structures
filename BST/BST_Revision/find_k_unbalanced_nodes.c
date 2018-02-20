//
//  find_k_unbalanced_nodes.c
//  BST_Revision
//
//  Created by Surya Sahukar on 8/2/16.
//  Copyright © 2016 Surya Sahukar. All rights reserved.
//

#include "find_k_unbalanced_nodes.h"
#include "stdlib.h"

struct node *find_k_unbalanced(struct node *root, int k)
{
    if (!root)
        return NULL;
    
    struct node *curr_root, *ret_node;
    curr_root = root;
    ret_node = NULL;
    
    int lheight, rheight;
    
    lheight = height(root -> left);
    rheight = height((root -> right));
    
    if ( abs ( lheight - rheight) == k )
    {
        ret_node = curr_root;
        return ret_node;
    }
    
    if (!ret_node)
    ret_node = find_k_unbalanced(root -> left, k);
    
    if (!ret_node)
        ret_node = find_k_unbalanced(root -> right, k);
    
    
    return ret_node;
}
