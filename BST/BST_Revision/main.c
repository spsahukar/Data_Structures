//
//  main.c
//  BST_Revision
//
//  Created by Surya Sahukar on 7/21/16.
//  Copyright © 2016 Surya Sahukar. All rights reserved.
//

#include <stdio.h>
#include "basic_functions.h"
#include "tree_to_linked_list.h"
#include "linked_list_to_tree.h"
#include "find_k_unbalanced_nodes.h"
#include "least_common_ancestor.h"
#include "leaf_path_weight.h"

// To execute C, please define "int main()"



int main() {
    struct node *root=create_node(10);
    insert_bst(root,3);
    insert_bst(root,40);
    insert_bst(root,-1);
    insert_bst(root,70);
    insert_bst(root,11);
    insert_bst(root,7);
    
    inorder_traversal(root);
    preorder_traversal(root);
    postorder_traversal(root);
    level_traversal(root);
    
    printf("\n Size of BST=%d\n", size_bst(root));
    printf("\n Height of BST=%d\n", height(root));
    printf("\n Min Element = %d\n", find_min(root));
    printf("\nMax Element = %d\n", find_max(root));
    printf("\n Sum Between = %d\n", sum_between(root,1,100));
    
    printf("\n Is Balanced = %d\n",is_balanced(root));
    
    struct node *search=search_bst(root, 70);
    if (search)
    {
        printf("Search Node address=0x%x, data=%d\n",search, search->data);
    }
    
    print_between(root,10,100);
    
    printf("Inorder Sucessor of 11 is %d\n", (inorder_successor(root, 11))->data );
    
   // level_traversal(root);
    
    /* Flatten tree to linked list */
    
    
    
    
    struct node *head = tree_to_linked_list(root);
    
    printf("\n");
    while(head != NULL)
    {
        printf("Flatten Tree: %d\n", head->data);
        head = head->right;
        
    }
    
     
     /*
    struct ll_node *ll_head;
    ll_head = create_head(2);
    insert_ll_node_at_tail(ll_head, 1);
    insert_ll_node_at_tail(ll_head, 7);
    insert_ll_node_at_tail(ll_head,101);
    insert_ll_node_at_tail(ll_head,202);
    
    struct node *rootNew = linked_list_to_tree(ll_head);
    
    level_traversal(rootNew);
    
     
     */
    
    /* Find k unbalanced */
    root=create_node(10);
    insert_bst(root,3);
    insert_bst(root,40);
    insert_bst(root,70);
    insert_bst(root,11);
    insert_bst(root,7);
    insert_bst(root, 21);
    insert_bst(root, -1);
    
    level_traversal(root);
    struct node *ret;
    ret = find_k_unbalanced(root, 1);
    
    if (ret)
        printf("Unbalanced Node = %d\n", ret->data);
    else
        printf("No unbalanced node\n");
    

    
    /********* Check symmetric ******/
    int ret_val;
    ret_val = is_symmetric(root);
    
    if (ret_val > 0 )
        printf ("Tree is symmetric\n");
    else
        printf (" Tree is not symmetric\n");
    
    ///********* Check LCA **********/
    
    /*
    
    struct node *lca;
    lca = least_common_ancestor(root, 70, -1);
    
    printf("LCA Data = %d, LCA = 0x%x\n", lca->data, lca);
     
     */
    
    /** Leaf path weight */
    int path_weight;
    int leaf_value;
    leaf_value = 40;
    path_weight = leaf_path_weight(root, leaf_value);
    
    printf("Path weight of %d is %d\n", leaf_value, path_weight);
    
    struct node *result;
    result = (struct node *) malloc(sizeof(struct node));
    result = find_leaf_of_given_path_weight(root, 120);
    
    if (result)
        printf("Leaf node is  and its data is %d\n", result->data);
    else
        printf("No leaf node with given path weight found\n");
    
    
    
}


