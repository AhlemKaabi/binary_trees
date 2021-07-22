#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 *
 * Return: the height of the tree. If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t hl = 0, hr = 0;

	if (tree == NULL)
	{
		return (NULL);
	}
	if (tree)
	{
		hl += binary_tree_height(tree->left);
		hr += binary_tree_height(tree->right);
		return ((hl > hr) ? hl + 1 : hr + 1);
	}
	return (0);
}
/**
 * print_levelorder- Function to print level order traversal a tree
 * @root: pointer to the root node of the tree to traverse.
 * @func: pointer to a function to call for each node. The value in
 * the node must be passed
 * as a parameter to this function.
 */
void print_levelorder(const binary_tree_t *root, void (*func)(int))
{
	size_t h;
	size_t i;

	h = binary_tree_height(root);
	for (i = 1; i <= h; i++)
		print_current_level(root, i, func);
}
/**
 * print_current_level - print current level.
 * @root: pointer to the root node of the tree to traverse.
 * @func: pointer to a function to call for each node. The
 * value in the node must be passed as a parameter to this function.
 * @level: root level.
 */
void print_current_level(const binary_tree_t *root,
size_t level, void (*func)(int))
{
	if (root == NULL)
		return;
	if (level == 1)
		func(root->n);
	else if (level > 1)
	{
		print_current_level(root->left, level - 1, func);
		print_current_level(root->right, level - 1, func);
	}
}
/**
 * binary_tree_levelorder - function that goes through a binary
 * tree using level-order traversal.
 * @tree: pointer to the root node of the tree to traverse.
 * @func: pointer to a function to call for each node. The
 * value in the node must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	print_levelorder(tree, func);
}
