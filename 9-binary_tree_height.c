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

	if (tree)
	{
		hl += binary_tree_height(tree->left);
		hr += binary_tree_height(tree->right);
		return ((hl > hr) ? hl + 1 : hr + 1);
	}
	return (0);
}
