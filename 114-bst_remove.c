#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removing the desired
 * value
 */
typedef struct bst {
    int value;
    struct bst *left;
    struct bst *right;
} bst_t;

bst_t *bst_remove(bst_t *root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (value < root->value) {
        root->left = bst_remove(root->left, value);
    } else if (value > root->value) {
        root->right = bst_remove(root->right, value);
    } else {
        if (root->left == NULL) {
            bst_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }
        bst_t *temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->value = temp->value;
        root->right = bst_remove(root->right, temp->value);
    }
    return root;
}
