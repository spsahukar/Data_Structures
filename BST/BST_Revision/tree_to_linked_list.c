//
//  tree_to_linked_list.c
//  BST_Revision
//
//  Created by Surya Sahukar on 7/22/16.
//  Copyright © 2016 Surya Sahukar. All rights reserved.
//

#include "tree_to_linked_list.h"

struct node *tree_to_linked_list(struct node *root)
{
    if (root == NULL )
        return NULL;
    if (root -> left == NULL )
        return root;
    struct node *left, *right, *cur;
    
    
    cur = root;
    left = root -> left;
    right = root -> right;
    
    
    root -> left = NULL;
    free(root -> left);
    
  //  tree_to_linked_list(left);
   cur = tree_to_linked_list(right);
   // root->right = left;
    
    while(cur -> right != NULL)
        cur = cur -> right;
    cur -> right = tree_to_linked_list(left);
    
    return root;
    
}
