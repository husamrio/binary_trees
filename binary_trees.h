#ifndef __BINARY_TREES_H__
#define __BINARY_TREES_H__

#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>



/* Structures for holding and organizing data. */

/**
 * struct binary_tree_s - Binary tree node
 * @parent: Pointer to the parent node
 * @n: Integer stored in the node
 * @right: Pointer to the right child node
 * @left: Pointer to the left child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *left;
    struct binary_tree_s *right;
    struct binary_tree_s *parent;	
};

typedef struct binary_tree_s heap_t;
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s bst_t;


/**
 * struct levelorder_queue_s - Level order traversal queue.
 * @next: The next node to traverse to in the binary tree.
 * @node: A node of a binary tree.
 */
typedef struct levelorder_queue_s
{
	
    struct levelorder_queue_s *next;
    binary_tree_t *node;
	
} levelorder_queue_t;

/* Auxiliary function for displaying output or content. */
void binary_tree_print(const binary_tree_t *);

/* Function declarations that outline the structure and input/output of tasks to be performed. */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
size_t binary_tree_nodes(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_delete(binary_tree_t *tree);
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_leaf(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_root(const binary_tree_t *node);
int *heap_to_sorted_array(heap_t *heap, size_t *size);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
int heap_extract(heap_t **root);
int binary_tree_is_complete(const binary_tree_t *tree);
heap_t *array_to_heap(int *array, size_t size);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int binary_tree_is_heap(const binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
avl_t *sorted_array_to_avl(int *array, size_t size);
bst_t *bst_insert(bst_t **tree, int value);
avl_t *avl_remove(avl_t *root, int value);
bst_t *array_to_bst(int *array, size_t size);
avl_t *array_to_avl(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
		
avl_t *avl_insert(avl_t **tree, int value);
int binary_tree_is_avl(const binary_tree_t *tree);
bst_t *bst_remove(bst_t *root, int value);

#endif /* BINARY_TREES_H */