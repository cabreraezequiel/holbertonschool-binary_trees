#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if ((binary_tree_is_bst(tree) == 1) &&
	    (binary_tree_balance(tree)) <= 1 &&
	    (binary_tree_balance(tree)) >= -1 &&
	    (binary_tree_balance(tree->right)) <= 1 &&
	    (binary_tree_balance(tree->right)) >= -1 &&
	    (binary_tree_balance(tree->left) <= 1) &&
	    (binary_tree_balance(tree->left) >= -1))
		return (1);

	return (0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int height, left, right = 0;

	if (tree == NULL)
		return (-1);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left > right)
		height = 1 + left;
	else
		height = 1 + right;

	return (height);
}


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}

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
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (isBSTUtil(tree, INT_MIN, INT_MAX));
}
