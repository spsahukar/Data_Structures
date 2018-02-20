//
//  main.c
//  LinkedList_Rev
//
//  Created by Surya Sahukar on 21/01/15.
//  Copyright (c) 2015 Surya Sahukar. All rights reserved.
//

#include <stdio.h>
#include "linkedList.h"


int main(int argc, const char * argv[])
{
    struct node *head;
    head = create_root(2);
    insert_node_at_tail(head, 1);
    //print_ll(head);
    insert_node_at_tail(head, 7);
    //print_ll(head);
    head = insert_at_head(&head,707);
    //print_ll(head);
    insert_node_at_tail(head,101);
    insert_node_at_tail(head, 707);
    //insert_node_at_tail(head,202);
    
    /* Const time traversal */
    
    struct node *result = const_time_traversal(head, 2);
    
    printf("Result = 0x%x\n\n", result);
    

    
    printf("Current List\n");
    print_ll(head);

    printf("Remove all occurence of element\n");
    head = removeAll(707, head);
    print_ll(head);
    
    /* Remove Duplicates New */
    
    head = create_root(1);
    insert_node_at_tail(head, 2);
    insert_node_at_tail(head, 1);
    insert_node_at_tail(head, 1);
    insert_node_at_tail(head, 2);
    //insert_node_at_tail(head, 1);
    //insert_node_at_tail(head, 2);
    //insert_node_at_tail(head, 6);
    
    remove_duplicates(head);
    
    printf("Remove Duplicates New\n");
    print_ll(head);
    
    /*********** Testing Rev K nodes ***********/
    printf("Reverse K nodes\n");
    head = Reverse_K_nodes(head, 3);
    print_ll(head);
    
    /* Zipper Testing *******************************************************************/
    
    head = zipper(head);
    printf("Zipped List\n");
    print_ll(head);
    
    /* Zipper 2 Linked list Testing ****************************************************/
    
    struct node *head1, *head2;
    head1 = create_root(4);
    insert_node_at_tail(head1, 7);
    insert_node_at_tail(head1, 2);
    insert_node_at_tail(head1, 77);
    insert_node_at_tail(head1, 21);
        
    head2 = create_root(1);
    insert_node_at_tail(head2, -1);
    insert_node_at_tail(head2, 3);
  
    head1 = zip_two_linked_lists(head1, head2);
    printf("Zipping 2 linked lists \n");
    print_ll(head1);
    
    
    /* Testing Median Circular linked list */
    
    
    head = selection_sort(head);
    printf("Cicular list testing -- Sorted list\n");
    print_ll(head);
    head = create_circular(head);
    
    printf("Median value of the list is %d\n", median_circular(head));
    
    
    /*********** Testing Odd Even Merge ***************/
    
    head1 = odd_even_merge(head1);
    
    printf("Odd Even Merge \n");
    print_ll(head1);
    
    
    /****************** Common Node testing *************/
    
    head1 = create_root(4);
    insert_node_at_tail(head1, 7);
    insert_node_at_tail(head1, 2);
 
    
    head2 = create_root(7);
    insert_node_at_tail(head2, 4);
    insert_node_at_tail(head2, 3);

    //head2->link->link = head1->link->link->link->link;
    struct node *common = find_intersection_two_linked_lists(head1, head2);
    
    if (common)
        printf("Commond Node = %d\n", common->data);
    else
        printf("No Common node\n");
    
    
    
    //******************** Adding integers using linked lists ***********************/
    head1 = create_root(4);
    insert_node_at_tail(head1, 7);
    insert_node_at_tail(head1, 2);
    insert_node_at_tail(head1, 9);
    
    
    
    head2 = create_root(7);
    insert_node_at_tail(head2, 4);
    insert_node_at_tail(head2, 7);
    
    result = add_numbers_linked_list(head1, head2);
    
    printf("After Add the numbers in linked list\n\n");
    print_ll(result);
    
    
    
    
    /* Selection Sort Testing */
    
    printf("Before Selection Sort\n");
    print_ll(head);
    head=selection_sort(head);
    printf("Selection Sort\n");
    print_ll(head);
    
    
    /* Merge Sort Testing   */
    
    /*
    root=merge_sort(root);
    printf("Merge sort\n0");
    print_ll(root);
     
     */
    
    //reversePrint(root);
    
    //reverse_recursive(root);
    //root=Remove_Duplicates(root);
    //print_ll(root);
    
    //root=Insert_SortedList(root, 303);
    //root=Insert_SortedList(root, 909);
    //print_ll(root);
    
    
     
    //root=Delete_Alt_Node(root);
    //print_ll(root);
    
    

    
    
    //reversePrint(root);
    
    
    //struct node *rev = reverse_ll_method1(root);
    //root = reverse_ll_method2(root);
    //printf("Root = %p\n", root);
    //sort(&root);
    //print_ll(root);
    //root = bubble_sort(root);
    //print_ll(root);
    //reverse_recursive(root);
    //print_ll(rev_head);
    //root = swap_pairs(root);
   // printf("Reverse in pair\n");
    //root=reverse_in_pairs(root);
    //print_ll(root);
    //print_ll(root);
    /*
    root=RighShift(root);
    print_ll(root);
    root=LeftShift(root);
    print_ll(root);
     */
     
    //root=ReverseBetween( root->link, root->link->link);
    //print_ll(root);
    //root=ReverseKBlocks(root, 2);
    //print_ll(root);
    //insert_node_at_tail(root,111);
    //print_ll(root);
    //struct node *middle_node = FindMiddle(root);
    //printf("Middle Node: Data = %d\n",middle_node->data);
    //mergeSort(&root);
   // print_ll(root);
    
    /* Merge Sort Linked Lists */
    
    //struct node *A = create_linked_list();
    

    
    
    return 0;
}










