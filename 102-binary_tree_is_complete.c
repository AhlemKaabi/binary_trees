#include "binary_trees.h"
/**
 * isComplete - check if binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @index: index where to start the check
 * @n: size of binary tree
 *
 * Return: 1 or 0 depends on complete or not
**/
int isComplete(const binary_tree_t *tree, size_t index, size_t n)
{
	if (tree == NULL)
	{
		return (1);
	}
	if (index >= n)
	{
		return (0);
	}
	return (isComplete(tree->left, 2 * index + 1, n) &&
			isComplete(tree->right, 2 * index + 2, n));
}
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size of
 *
 * Return: size of a binary tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
/**
 * binary_tree_is_complete -  checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise. If tree is NULL, return 0
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t n = 0;
	int res = 0;
	size_t index = 0;

	if (tree == NULL)
	{
		return (0);
	}
	n = binary_tree_size(tree);
	res = isComplete(tree, index, n);
	return (res);
}
