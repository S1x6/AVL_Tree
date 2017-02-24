#ifndef _TREE_HANDLER_H
#define _TREE_HANDLER_H

#include <malloc.h>

typedef struct _TreeNode {
	struct _TreeNode * left;
	struct _TreeNode * right;
	unsigned char value;
	unsigned char height;
} TreeNode;

void addNode(TreeNode ** node, int value);
TreeNode * slRotate(TreeNode * root);
TreeNode * srRotate(TreeNode * root);
TreeNode * blRotate(TreeNode * root);
unsigned char getHeight(TreeNode * node);
TreeNode * brRotate(TreeNode * root);
TreeNode * balance(TreeNode * root);
#endif 
