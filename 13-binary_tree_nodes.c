#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: number of nodes with at least 1 child
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int node;

	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);

	binary_tree_nodes(tree->left);
	binary_tree_nodes(tree->right);

	return (node + 1);
}
