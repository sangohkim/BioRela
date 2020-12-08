	#ifndef __BIORELA_HEADER__

#define __BIORELA_HEADER__

#define NUM 15
#define LEN 100


// 노드 구조체 선언하기
typedef struct node* treeptr;
typedef struct node {
	int data;
	char name[LEN];
	treeptr leftChild, rightChild;
} node;

char species[NUM][LEN] = {
    "Magnoliopsida", "Asterales", "Fabales_big", "Asteraceae", "Argophyllaceae", "Fabales", "Polygalaceae", "Helianthus", "Cosmos", "Argophyllum", "Corokia", "Phaseolus", "Pisum", "Polygala", "FORM"
};

// 기초적인 트리 순회 방법
void preorder(treeptr ptr, char* target);  // 전위순회

void inorder(treeptr ptr, char* target);  // 중위순회
void postorder(treeptr ptr, char* target);  // 후위순회
int lca_basic(int a, int b);  // LCA 함수(완전이진트리에서만 작동가능)


#endif