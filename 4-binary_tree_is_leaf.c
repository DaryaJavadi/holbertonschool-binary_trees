/**
 * binary_tree_is_leaf - checks if a node is a leaf of a binary tree.
 * @node: a pointer to the node to check.
 *
 * Return: if the node is a leaf - 1.
 *         Otherwise - 0.
 */
#include "binary_trees.h"
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}
