#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
#include <limits.h>

/**
 * bst_insert_aux - Aux function that inserts a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */

bst_t *bst_insert_aux(binary_tree_t *tree, int value)
{
	if (value < (tree)->n)
	{
		if ((tree)->left == NULL)
			(tree)->left = binary_tree_insert_left(tree, value);
		else
			(tree)->left = bst_insert_aux(tree->left, value);
	}
	else if (value > (tree)->n)
	{
		if ((tree)->right == NULL)
			(tree)->right = binary_tree_insert_right(tree, value);
		else
		{
			(tree)->right = bst_insert_aux(tree->right, value);
		}
	}

	return (tree);
}

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node;

	node = malloc(sizeof(bst_t));

	if (node == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(node, value);
	}

	node->n = value;

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
			(*tree)->left = binary_tree_insert_left(node, value);
		else
			return (bst_insert_aux((*tree)->left, value));
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
			(*tree)->right = binary_tree_insert_right(node, value);
		else
		{
			return (bst_insert_aux((*tree)->right, value));
		}
	}

	return (node);
}
/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 * Return: pointer to the new node, or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);


	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	new_node->parent = parent;
	parent->left = new_node;

	return (new_node);
}
/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 * Return: pointer to the new node, or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->right = NULL;
	new_node->left = NULL;
	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}

	new_node->parent = parent;
	parent->right = new_node;
	return (new_node);
}
