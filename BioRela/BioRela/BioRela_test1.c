/*
<트리 생성하기>
Basic Branch에서는 완전이진트리로 구현한다.
*/

#include <stdio.h>
#include <string.h>


#define NUM 7
#define LEN 100


// 노드 구조체 선언하기
typedef struct node* treeptr;
typedef struct node {
	int data;
	char name[LEN];
	treeptr leftChild, rightChild;
} node;


// 기초적인 트리 순회 방법
void preorder(treeptr ptr, char * target);  // 전위순회

void inorder(treeptr ptr, char * target);  // 중위순회
void postorder(treeptr ptr, char * target);  // 후위순회
int lca_basic(int a, int b);  // LCA 함수(완전이진트리에서만 작동가능)


// 생명체 예시
char species[NUM][LEN] = {
    "Magnoliopsida", "Asterales", "Fabales_big", "Asteraceae", "Argophyllaceae", "Fabales", "Polygalaceae"
};


// 사용자 입력
char target[LEN], target1[LEN], target2[LEN];
int target_idx;
int a, b, c;


int main(void)
{
	node nodes[NUM + 1];
	int i, len1, len2;


	// 트리 생성과정
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


	printf("생물을 입력하세요: ");
	scanf("%s", target);
	preorder(&nodes[1], target);
	a = target_idx;
	printf("비교를 원하는 두 생물을 입력하세요: ");
	scanf("%s %s", target1, target2);
	preorder(&nodes[1], target1);
	b = target_idx;
	preorder(&nodes[1], target2);
	c = target_idx;
	
	len1 = lca_basic(a, b);
	len2 = lca_basic(a, c);
	
	// len1, len2 대신에 이와 같은 ptr->data값을 가지는 문자열로 출력하는 코드 작성해야 함
	printf("%s와 %s는 %d에 속합니다.\n", target, target1, len1);
	printf("%s와 %s는 %d에 속합니다.\n", target, target2, len2);

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