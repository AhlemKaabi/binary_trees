#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current;

	if (!(*tree))
	{
		(*tree) = (binary_tree_node(NULL, value));
		return (*tree);
	}
	current = *tree;
	while (current)
	{
		if (current->n == value)
		{
			break;
		}
		if (current->n < value)
		{
			if (current->right == NULL)
			{
				current->right = (binary_tree_node(current, value));
				return (current->right);
			}
			current = current->right;
		}
		else if (current->n > value)
		{
			if (current->left == NULL)
			{
				current->left = (binary_tree_node(current, value));
				return (current->left);
			}
			current = current->left;
		}
	}
	return (NULL);
}
