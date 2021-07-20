#include "binary_trees.h"
/**
 *binary_tree_insert_right - inserts a node as the right-child of another
 *@parent: pointer to the node to insert the right-child in.
 *@value: the value to store in the new node.
 * Return: pointer to the created node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *aux_node;

	if (parent == NULL)
	{
		return (NULL);
	}
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	if (parent->right ==  NULL)
	{
		parent->right = new_node;
		new_node->n = value;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->parent = parent;
	}
	else
	{
		aux_node = parent->right;
		parent->right = new_node;
		new_node->n = value;
		new_node->right = aux_node;
		new_node->left = NULL;
		new_node->parent = parent;
	}
	return (new_node);
}
