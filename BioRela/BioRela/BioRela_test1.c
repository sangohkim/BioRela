/*
<Ʈ�� �����ϱ�>
Basic Branch������ ��������Ʈ���� �����Ѵ�.
*/

#include <stdio.h>
#include <string.h>


#define NUM 15
#define LEN 100


// ��� ����ü �����ϱ�
typedef struct node* treeptr;
typedef struct node {
	int data;
	char name[LEN];
	treeptr leftChild, rightChild;
} node;


// �������� Ʈ�� ��ȸ ���
void preorder(treeptr ptr, char * target);  // ������ȸ

void inorder(treeptr ptr, char * target);  // ������ȸ
void postorder(treeptr ptr, char * target);  // ������ȸ
int lca_basic(int a, int b);  // LCA �Լ�(��������Ʈ�������� �۵�����)


// ����ü ����
char species[NUM][LEN] = {
    "Magnoliopsida", "Asterales", "Fabales_big", "Asteraceae", "Argophyllaceae", "Fabales", "Polygalaceae", "Helianthus", "Cosmos", "Argophyllum", "Corokia", "Phaseolus", "Pisum", "Polygala", "FORM"
};


// ����� �Է�
char target[LEN], target1[LEN], target2[LEN];
int target_idx;
int a, b, c;


int main(void)
{
	node nodes[NUM + 1];
	int i, len1, len2;


	// Ʈ�� ��������
	for (i = 1; i <= NUM; i++)
	{
		nodes[i].data = i;
		strncpy(nodes[i].name, species[i - 1], LEN);
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	for (i = 1; i <= NUM; i++)
	{
		if (!(i % 2))
		{
			nodes[i / 2].leftChild = &nodes[i];
		}
		else
		{
			nodes[i / 2].rightChild = &nodes[i];
		}
	}

	while (1)
	{
		printf("***********************************************************************************\n");
		printf("������ �Է��ϼ���: ");
		scanf("%s", target);
		if (!strcmp(target, "q"))
		{
			puts("bye");
			break;
		}
		preorder(&nodes[1], target);
		a = target_idx;
		printf("�񱳸� ���ϴ� �� ������ �Է��ϼ���: ");
		scanf("%s %s", target1, target2);
		if (!strcmp(target1, "q") || !strcmp(target2, "q"))
		{
			puts("bye");
			break;
		}
		preorder(&nodes[1], target1);
		b = target_idx;
		preorder(&nodes[1], target2);
		c = target_idx;

		len1 = lca_basic(a, b);
		len2 = lca_basic(a, c);

		// len1, len2 ��ſ� �̿� ���� ptr->data���� ������ ���ڿ��� ����ϴ� �ڵ� �ۼ��ؾ� ��
		printf("%s�� %s�� %d�� ���մϴ�.\n", target, target1, len1);
		printf("%s�� %s�� %d�� ���մϴ�.\n", target, target2, len2);
		if (len1 / 2 < len2 / 2)
			printf("%s�� %s�� �������谡 %s�� %s���� �� �������ϴ�.\n", target, target1, target, target2);
		else if (len1 / 2 > len2 / 2)
			printf("%s�� %s�� �������谡 %s�� %s���� �� �������ϴ�.\n", target, target2, target, target1);
		else
			printf("%s�� %s�� LCA�� %s�� �����մϴ�.\n", target1, target2, target);
		printf("***********************************************************************************\n\n");
	}


	return 0;
}


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


void preorder(treeptr ptr, char * target)
{
	if (ptr)
	{
		if (!strncmp(ptr->name, target, LEN))
			target_idx = ptr->data;
		preorder(ptr->leftChild, target);
		preorder(ptr->rightChild, target);
	}
}

void inorder(treeptr ptr, char * target)
{
	if (ptr)
	{
		inorder(ptr->leftChild, target);
		return;
		inorder(ptr->rightChild, target);
	}
}

void postorder(treeptr ptr, char * target)
{
	if (ptr)
	{
		postorder(ptr->leftChild, target);
		postorder(ptr->rightChild, target);
		return;
	}
}