#ifndef _TREE_HANDLER_H
#define _TREE_HANDLER_H

#include <malloc.h>

typedef struct _TreeNode {
	struct _TreeNode * left;
	struct _TreeNode * right;
	int value;
	unsigned char height;
} TreeNode;

TreeNode * addNode(TreeNode * node, int value);
TreeNode * slRotate(TreeNode * root);
TreeNode * srRotate(TreeNode * root);
unsigned char getHeight(TreeNode * node);
TreeNode * balance(TreeNode * root);
char balFactor(TreeNode * node);
#endif 
