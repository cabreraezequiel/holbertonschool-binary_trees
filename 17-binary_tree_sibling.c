#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_sibling - function that finds the sibling of a node
 * @node: pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->n < node->parent->n)
	{
		if (node->parent->right == NULL)
			return (NULL);
		else
			return (node->parent->right);
	}
	else if (node->n > node->parent->n)
	{
		if (node->parent->left == NULL)
			return (NULL);
		else
			return (node->parent->left);
	}
	else
		return (NULL);
}
