#include "binary_trees.h"
/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 *
 * Return: If tree is NULL, the function must return 0, else return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t occ_nodes = 0;

	if (tree)
	{
		if (tree->left || tree->right)
		{
			occ_nodes++;
		}
		occ_nodes += binary_tree_nodes(tree->left);
		occ_nodes += binary_tree_nodes(tree->right);
	}
	return (occ_nodes);
}
