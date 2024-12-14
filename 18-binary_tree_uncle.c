/**
 * binary_tree_uncle - finds the uncle of a node
 *                     in a binary tree.
 * @node: a pointer to the node to find the uncle of.
 * Return: if node is NULL or has no uncle, NULL.
 *         otherwise, a pointer to the uncle node.
 */
#include "binary_trees.h"
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
	    node->parent == NULL ||
	    node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
