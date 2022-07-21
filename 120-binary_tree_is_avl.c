#include <stdlib.h>
#include "binary_trees.h"


int is_avl(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	if (abs(left_height - right_height) <= 1 && is_avl(tree->left) && is_avl(tree->right))
		return (1);
	return (0);
}


/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->right == NULL)
		return (0);
	if (tree->left == NULL)
		return (0);

	return (is_avl(tree));
}


/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left == 0 && node->right == 0)
		return (1);

	else
		return (0);
}
