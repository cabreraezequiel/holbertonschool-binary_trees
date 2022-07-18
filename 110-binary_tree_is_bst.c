#include <stdlib.h>
#include "binary_trees.h"
#include <limits.h>

/**
 * isBSTUtil - utility helper function
 * @node: pointer to the root node of the tree to check
 * @max: max
 * @min: min
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int isBSTUtil(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);

	if (node->n < min || node->n > max)
		return (0);

	return (isBSTUtil(node->left, min, node->n - 1) &&
		isBSTUtil(node->right, node->n + 1, max));
}


/**
 * find_max_value - finds the maximum value in a binary tree
 * @root: pointer to the root node of the tree to check
 * Return: max value
 */

int find_max_value(const binary_tree_t *root)
{
	int res, lres, rres;

	if (root == NULL)
		return (INT_MIN);

	res = root->n;
	lres = find_max_value(root->left);
	rres = find_max_value(root->right);
	if (lres > res)
		res = lres;
	if (rres > res)
		res = rres;
	return (res);
}


/**
 * find_min_value - finds minimum value in a binary tree
 * @root: pointer to the root node of the tree to check
 * Return: min value
 */

int find_min_value(const binary_tree_t *root)
{
	int res, lres, rres;

	if (root == NULL)
		return (INT_MAX);

	res = root->n;
	lres = find_min_value(root->left);
	rres = find_min_value(root->right);
	if (lres < res)
		res = lres;
	if (rres < res)
		res = rres;
	return (res);
}


/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left != NULL && find_max_value(tree->left) > tree->n)
		return (0);

	if (tree->right != NULL && find_min_value(tree->right) < tree->n)
		return (0);

	if (!binary_tree_is_bst(tree->left) || !binary_tree_is_bst(tree->right))
		return (0);

	return (1);
}
