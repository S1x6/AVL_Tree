#include "TreeHandler.h"

TreeNode * addNode(TreeNode * node, int value)
{
	if (!node) {
		TreeNode * ret = malloc(sizeof(TreeNode));
		ret->height = 1;
		ret->left = NULL;
		ret->right = NULL;
		ret->value = value;
		return ret;
	}
	if (value < node->value)
		node->left = addNode(node->left, value);
	else
		node->right = addNode(node->right, value);
	return balance(node);
}

TreeNode * srRotate(TreeNode * root)
{
	TreeNode * tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	root->height = getHeight(root);
	tmp->height = getHeight(tmp);
	return tmp;
}

TreeNode * slRotate(TreeNode * root)
{
	TreeNode * tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	root->height = getHeight(root);
	tmp->height = getHeight(tmp);
	return tmp;
}

TreeNode * balance(TreeNode * root)
{
	root->height = getHeight(root);

	if (balFactor(root) > 1) {
		if (balFactor(root->right) < 0)
			root->right = srRotate(root->right);
		return slRotate(root);
	}
	else
		if (balFactor(root) < -1) {
			if (balFactor(root->left) > 0)
				root->left = slRotate(root->left);
			return srRotate(root);
		}
		else
			return root;

}

char balFactor(TreeNode * node)
{
	if (!node)
		return 0;
	return getHeight(node->right) - getHeight(node->left);
}

unsigned char getHeight(TreeNode * node)
{
	if (!node)
		return 0;
	unsigned char l = node->left ? node->left->height : 0;
	unsigned char r = node->right ? node->right->height : 0;
	return (l > r) ? l + 1 : r + 1;
}

