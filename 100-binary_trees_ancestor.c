#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: lowest common ancestor node of the two given nodes
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
										const binary_tree_t *second)
{
	binary_tree_t *tmp;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first->parent == second->parent)
	{
		return ((binary_tree_t *)first->parent);
	}
	/* save position to go back */
	tmp = (binary_tree_t *)second;
	while (first)
	{
		while (second)
		{
			if (second == first)
			{
				return ((binary_tree_t *)first);
			}
			if (second->parent == first->parent)
			{
				return ((binary_tree_t *)first->parent);
			}
			second = second->parent;
		}
		second = tmp;
		first = first->parent;
	}
	return (NULL);
}
