#include "binary_trees.h"
/**
 * binary_tree_rotate_left - function that performs a left-rotation
 * on a binary tree
 * @tree: pointer to the root node of the tree to rotate.
 * Return: pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL;

	if (tree == NULL)
	{
		return (NULL);
	}

	tmp = tree->right;
	tree->right = tmp->left;
	tmp->left = tree;
	tmp->parent = tree->parent;
	tree->parent = tmp;
	tree = tmp;

	return (tree);
}
