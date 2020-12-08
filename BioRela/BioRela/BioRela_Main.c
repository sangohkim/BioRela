/*
<트리 생성하기>
Basic Branch에서는 완전이진트리로 구현한다.
*/

#include <stdio.h>
#include <string.h>

#include "BioRela_header.h"

extern char speices[NUM][LEN];


// 기초적인 트리 순회 방법
//void preorder(treeptr ptr, char * target);  // 전위순회

//void inorder(treeptr ptr, char * target);  // 중위순회
//void postorder(treeptr ptr, char * target);  // 후위순회
//int lca_basic(int a, int b);  // LCA 함수(완전이진트리에서만 작동가능)


// 생명체 예시
/*
char species[NUM][LEN] = {
    "Magnoliopsida", "Asterales", "Fabales_big", "Asteraceae", "Argophyllaceae", "Fabales", "Polygalaceae", "Helianthus", "Cosmos", "Argophyllum", "Corokia", "Phaseolus", "Pisum", "Polygala", "FORM"
};
*/


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

	while (1)
	{
		printf("***********************************************************************************\n");
		printf("생물을 입력하세요: ");
		scanf("%s", target);
		if (!strcmp(target, "q"))
		{
			puts("bye");
			break;
		}
		preorder(&nodes[1], target);
		a = target_idx;
		printf("비교를 원하는 두 생물을 입력하세요: ");
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

		// len1, len2 대신에 이와 같은 ptr->data값을 가지는 문자열로 출력하는 코드 작성해야 함
		printf("%s와 %s의 LCA는 %d에 속합니다.\n", target, target1, len1);
		printf("%s와 %s의 LCA는 %d에 속합니다.\n", target, target2, len2);
		if (len1 / 2 < len2 / 2)
			printf("%s와 %s의 유연관계가 %s와 %s보다 더 가깝습니다.\n", target, target1, target, target2);
		else if (len1 / 2 > len2 / 2)
			printf("%s와 %s의 유연관계가 %s와 %s보다 더 가깝습니다.\n", target, target2, target, target1);
		else
			printf("%s와 %s의 LCA가 %s로 동일합니다.\n", target1, target2, target);
		printf("***********************************************************************************\n\n");
	}


	return 0;
}