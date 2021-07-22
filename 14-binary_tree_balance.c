#include "binary_trees.h"
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

	while (tree)
	{
		hl++;
		if (tree->left == NULL)
		{
			break;
		}

		tree = tree->left;
	}

	while (tree)
	{
		hr++;
		if (tree->right == NULL)
		{
			break;
		}
		tree = tree->right;
	}

	balance = hl - hr;

	return (balance);
}
