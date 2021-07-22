#include "binary_trees.h"
/**
 * find_a_depth - function that finds the depth of leftmost leaf.
 * @node: pointer to the root of the tree to check.
 * Return: depth of leftmost leaf.
 */
size_t find_a_depth(const binary_tree_t *node)
{
	size_t d = 0;

	while (node != NULL)
	{
		d++;
		node = node->left;
	}
	return (d);
}
/**
 * is_perfect_recursive - This function tests if a binary tree is perfect
 * or not. It basically checks for two things :
 * 1) All leaves are at same level.
 * 2) All internal nodes have two children.
 * @node: pointer to the root of the tree to check.
 * @depth: depth of leftmost leaf.
 * @level: level of the leaf node.
 * Return: 1 success, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *node, size_t depth, size_t level)
{
	if (node == NULL)
	{
		return (0);
	}
	/**
	 * If leaf node, then its depth must be same as
     * depth of all other leaves.
	 */
	if (node->left == NULL && node->right == NULL)
	{
		if (depth == level + 1)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
	/*If internal node and one child is empty*/
	if (node->left == NULL || node->right == NULL)
	{
		return (0);
	}
	return (is_perfect_recursive(node->left, depth, level + 1) &&
	is_perfect_recursive(node->right, depth, level + 1));
}
/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect.
 * @tree: pointer to the root of the tree to check.
 * Return: 0 if tree is NULL, 1 if success.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth = 0;

	/*An empty tree is perfect*/
	if (tree == NULL)
	{
		return (1);
	}
	depth = find_a_depth(tree);
	return (is_perfect_recursive(tree, depth, 0));
}
