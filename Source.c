#define _CRT_SECURE_NO_WARNINGS
#include "TreeHandler.h"
#include <stdio.h>


extern void addNode(TreeNode ** node, int value);
TreeNode * readData();

int main()
{
	TreeNode * root = readData();
	return 0;
}

TreeNode * readData()
{
	TreeNode * root = NULL;
	FILE * fin = fopen("in.txt", "r");
	int n, buf;
	int i = 0;
	fscanf(fin, "%d\n", &n);
	for (; i < n; i++) {
		fscanf(fin, "%d", &buf);
		addNode(&root, buf);
	}
	return root;
}
