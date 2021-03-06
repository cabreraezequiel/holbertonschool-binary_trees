#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *aux;

	if (tree == NULL)
		return (NULL);
	if (tree->left == NULL)
		return (tree);

	aux = tree->left;
	if (aux->right != NULL)
		aux->right->parent = tree;
	aux->parent = tree->parent;
	tree->left = aux->right;
	aux->right = tree;
	tree->parent = aux;

	return (aux);
}
