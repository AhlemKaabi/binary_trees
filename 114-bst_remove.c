#include "binary_trees.h"
/**
 * minValue - find the leftmost leaf
 * @node: pointer to the root node of the tree where you will remove a node.
 * Return: pointer to the leftmost leaf.
 */
bst_t *minValue(bst_t *node)
{
	bst_t *current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL)
		current = current->left;
	return (current);
}
/**
 * bst_remove - function that removes a node from a Binary Search Tree.
 * @root: pointer to the root node of the tree where you will remove a node.
 * @value: the value to remove in the tree.
 * Return: pointer to the new root node of the tree
 * after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (root == NULL)
		return (root); /*base case*/
	/**
	 * If the value to be deleted is smaller than the root's
	 * value, then it lies in left subtree
	 */
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	/**
	 * If the value to be deleted
	 * is greater than the root's
	 * value, then it lies in right subtree
	 */
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	/*If key is same as root's value, then This is the node to be deleted*/
	else
	{/* node with only one child or no child*/
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		/*node with two children: Get the inorder successor*/
		temp = minValue(root->right);
		/*Copy the inorder successor's content to this node */
		root->n = temp->n;
		/*Delete the inorder successor*/
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
