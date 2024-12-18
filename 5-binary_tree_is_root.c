/**
 * binary_tree_is_root - checks if a node is a root of a binary tree.
 * @node: a pointer to the node to check.
 * Return: if the node is a root - 1.
 */
#include "binary_trees.h"
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
