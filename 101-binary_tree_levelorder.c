#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: the input root address
 * Return: height of the binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t rs, ls;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	ls = binary_tree_height(tree->left);
	rs = binary_tree_height(tree->right);
	if (ls < rs)
		return (rs + 1);
	return (ls + 1);
}

/**
 * printer - prints out the level where you are at.
 * @tree: the input root address
 * @func: input func address
 * @level: height of node to be printed
 */
void printer(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);

	else if (level > 1)
	{
		printer(tree->left, func, level - 1);
		printer(tree->right, func, level - 1);
	}
}


/**
 * binary_tree_levelorder - traverse a binary tree using level-order traversal
 * @tree: the input root address
 * @func: input func address
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i = 1;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree) + 1;

	while (i <= height)
	{
		printer(tree, func, i);
		i++;
	}
}
