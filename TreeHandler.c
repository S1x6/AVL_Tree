#include "TreeHandler.h"

void addNode(TreeNode ** node, int value)
{
	if (!(*node)) {
		*node = calloc(1, sizeof(TreeNode));
		(*node)->value = value;
		return;
	}

	if (value > (*node)->value) {
		if (!(*node)->right) {
			(*node)->right = calloc(1, sizeof(TreeNode));
			(*node)->right->value = value;
			return;
		}
		else {
			addNode(&((*node)->right), value);
			return;
		}
	}
	else {
		if (!(*node)->left) {
			(*node)->left = calloc(1, sizeof(TreeNode));
			(*node)->left->value = value;
			return;
		}
		else {
			addNode(&((*node)->left), value);
			return;
		}
	}
}

TreeNode * srRotate(TreeNode * root)
{
	TreeNode * tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	return tmp;
}

TreeNode * slRotate(TreeNode * root)
{
	TreeNode * tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	return tmp;
}

TreeNode * blRotate(TreeNode * root)
{
	root->right = srRotate(root->right);
	return slRotate(root);
}


TreeNode * brRotate(TreeNode * root)
{
	root->left = slRotate(root->left);
	return srRotate(root);
}

TreeNode * balance(TreeNode * root)
{
	if (root->left->height > root->right->height)
	{
		unsigned char l = root->left->left ? root->left->left->height : 0;
		unsigned char r = root->left->right ? root->left->right->height : 0;
		
	}
}
unsigned char balFactor(TreeNode * node)
{
	return getHeight(node->right) - getHeight(node->left);
}

unsigned char getHeight(TreeNode * node)
{
	unsigned char l = node->left ? node->left->height : 0;
	unsigned char r = node->right ? node->right->height : 0;
	return (l > r) ? l + 1 : r + 1;
}

