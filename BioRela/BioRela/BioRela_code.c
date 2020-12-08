#include <stdio.h>
#include <string.h>
#include "BioRela_header.h"

int lca_basic(int a, int b)
{
	if (a == 1 || b == 1)
		return 1;
	else if (a == b)
		return a;
	else if (a / 2 == b / 2)
		return a / 2;
	else
		return lca_basic(a >= b ? a / 2 : b / 2, a >= b ? b : a);
}


void preorder(treeptr ptr, char* target)
{
	if (ptr)
	{
		if (!strncmp(ptr->name, target, LEN))
			target_idx = ptr->data;
		preorder(ptr->leftChild, target);
		preorder(ptr->rightChild, target);
	}
}

void inorder(treeptr ptr, char* target)
{
	if (ptr)
	{
		inorder(ptr->leftChild, target);
		return;
		inorder(ptr->rightChild, target);
	}
}

void postorder(treeptr ptr, char* target)
{
	if (ptr)
	{
		postorder(ptr->leftChild, target);
		postorder(ptr->rightChild, target);
		return;
	}
}