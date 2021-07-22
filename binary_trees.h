#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
}binary_tree_s;

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *);
void binary_tree_delete(binary_tree_t *tree);

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

size_t binary_tree_height(const binary_tree_t *tree);
void print_levelorder(const binary_tree_t *root, void (*func)(int));
void print_current_level(const binary_tree_t *root, size_t level, void (*func)(int));



int binary_tree_is_leaf(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
int is_BST(const binary_tree_t *tree, int min, int max);

bst_t *bst_insert(bst_t **tree, int value);

bst_t *array_to_bst(int *array, size_t size);

bst_t *bst_remove(bst_t *root, int value);
#endif /* _BINARY_TREES_H_ */