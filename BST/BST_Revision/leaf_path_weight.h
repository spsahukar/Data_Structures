//
//  leaf_path_weight.h
//  BST_Revision
//
//  Created by Surya Sahukar on 8/2/16.
//  Copyright © 2016 Surya Sahukar. All rights reserved.
//

#ifndef leaf_path_weight_h
#define leaf_path_weight_h

#include <stdio.h>
#include "basic_functions.h"

int leaf_path_weight(struct node *, int);
int find_all_leaves (struct node *);
struct node *find_leaf_of_given_path_weight (struct node *, int);
#endif /* leaf_path_weight_h */
