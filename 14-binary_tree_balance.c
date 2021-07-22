#include "binary_trees.h"
/**
 * binary_tree_height - height of a binary tree.
 * @tree: pointer root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lh = 0, rh = 0;

		lh = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		rh = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((lh > rh) ? lh : rh);
	}
	return (0);
}
/**
 * binary_tree_balance - function that measures the balance
 * factor of a binary tree.
 * @tree: pointer to the root node of the tree to measure the balance factor.
 * Return: the Balance factor, if tree is NULL return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	/*Balance Factor = height(left-child) - height(right-child)*/

	int balance = 0, hl = 0, hr = 0;

	if (tree == NULL)
	{
		return (0);
	}

	hl = binary_tree_height(tree->left);
	hr = binary_tree_height(tree->right);

	balance = hl - hr;

	return (balance);
}
