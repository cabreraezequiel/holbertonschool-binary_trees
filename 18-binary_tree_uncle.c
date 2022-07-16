#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 * Return: pointer to the uncle node, or NULL if node is NULL or no uncle
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	int parent_n = 0;
	binary_tree_t *aux;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	aux = node->parent;
	parent_n = aux->n;
	if (aux->parent == NULL)
		return (NULL);

	aux = aux->parent;
	if (aux->left == NULL || aux->right == NULL)
		return (NULL);

	if (parent_n < aux->n)
		aux = aux->right;
	else if (parent_n > aux->n)
		aux = aux->left;

	return (aux);
}
