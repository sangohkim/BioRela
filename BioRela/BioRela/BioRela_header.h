	#ifndef __BIORELA_HEADER__

#define __BIORELA_HEADER__

#define NUM 15
#define LEN 100


// ��� ����ü �����ϱ�
typedef struct node* treeptr;
typedef struct node {
	int data;
	char name[LEN];
	treeptr leftChild, rightChild;
} node;

char species[NUM][LEN] = {
    "Magnoliopsida", "Asterales", "Fabales_big", "Asteraceae", "Argophyllaceae", "Fabales", "Polygalaceae", "Helianthus", "Cosmos", "Argophyllum", "Corokia", "Phaseolus", "Pisum", "Polygala", "FORM"
};

// �������� Ʈ�� ��ȸ ���
void preorder(treeptr ptr, char* target);  // ������ȸ

void inorder(treeptr ptr, char* target);  // ������ȸ
void postorder(treeptr ptr, char* target);  // ������ȸ
int lca_basic(int a, int b);  // LCA �Լ�(��������Ʈ�������� �۵�����)


#endif