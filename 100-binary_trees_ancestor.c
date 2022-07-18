#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_ancestor - function that finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: height of the tree
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    int depth_first = binary_tree_depth(first);
    int depth_second = binary_tree_depth(second);
    
    if (depth_first < depth_second)
    {
        binary_trees_ancestor(first, second->parent);
    }
    else if (depth_first > depth_second)
    {
        binary_trees_ancestor(first->parent, second);
    }
    else
    {
        if (first->n < second->n)
            return (first);
        else
            return (second);
    }

    return (NULL);
}