//
//  least_common_ancestor.c
//  BST_Revision
//
//  Created by Surya Sahukar on 8/2/16.
//  Copyright © 2016 Surya Sahukar. All rights reserved.
//

#include "least_common_ancestor.h"

int i = 0;
int array[10];

int search_and_create_array(struct node *root, int value)
{
    
    int ret;
    ret = 0;
    
    if (root == NULL)
        return ret;
    
    if (value == root -> data)
    {
        array[i] = root -> data;
        i++;
        ret = i;
    }
    
    else if ( value >= root -> data)
    {
        array[i] = root -> data;
        i++;
        ret = search_and_create_array(root -> right, value);
    }
    
    else if ( value < root -> data)
    {
        array[i] = root -> data;
        i++;
        ret = search_and_create_array(root -> left, value);
    }
    
    return ret;

}


/* There is a simpler method */
struct node *least_common_ancestor ( struct node *root, int value1, int value2)
{
    
    int count1, count2, size1, size2;
    struct node *lca_node;
    int k, j;
    
    count1 = search_and_create_array(root, value1);
    count2 = search_and_create_array(root, value2);
    
    count2 = count2 - count1;
    
    size1 = count1;
    size2 = count2;
    
    
    if (size2 > size1)
    {
        size2 = 2*size1;
        count1 = size1 - 1 ;
        count2 = size2 - 1;
    }
    if (size1 > size2)
    {
        size1 = 2*size2;
        count1 = size2 -1;
        count2 = size1 -1;
    }
    
    if (size1 == size2)
    {
        size2 = 2*size1;
        count1 = size1 -1;
        count2 = size2 -1;
    }
    

    
    /*
    delta = abs(count1 - count2);
    
    if ( count1 > delta)
    {
        while (count1 - 1 != delta)
            count1--;
    }
    
    if ( count2 > delta)
    {
        while (count2 - 1!= delta)
            count2--;
    }
        
     
     */
    
    for ( k = count1, j = count2 ; k >= 0 && j > count1; k--,j--)
    {
        if (array[k] == array[j])
            break;
    }
    
    printf("LCA = %d\n", array[k]);
  
    lca_node = search_bst(root, array[k]);
    
    return lca_node;
    
}
