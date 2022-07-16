#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a binary tree
 * @tree: pointer to the root node of the tree to measure the depth
 * Return: depth of the tree
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t n = 0;
	binary_tree_t *aux;

	if (tree == NULL)
		return(0);

	aux = (binary_tree_t *)tree;

	for (n = 0; aux->parent != NULL; n++)
	{
		aux = aux->parent; }

	return (n);
}
