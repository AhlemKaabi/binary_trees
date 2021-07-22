#include "binary_trees.h"
/**
 * binary_tree_rotate_right - rotate tree to the right
 * @tree: pointer to the root node of the tree to measure the size of
 *
 * Return: tree rotated with new root
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *p;
	binary_tree_t *b;

	if (tree == NULL)
		return (NULL);
	p = tree->parent;
	b = tree->left;
	tree->left = b->right;
	if (b->right != NULL)
		b->right->parent = tree;
	b->right = tree;
	tree->parent = b;
	b->parent = p;
	if (p != NULL)
	{
		if (p->left == tree)
		{
			p->left = b;
		}
		else
		{
			p->right = b;
		}
	}
	return (b);
}
