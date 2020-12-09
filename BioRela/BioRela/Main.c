#include <stdio.h>
#include <string.h>


#define NUM 31  // 트리의 노드 갯수
#define LEN 100


// 노드 구조체 선언하기
typedef struct node* treeptr;
typedef struct node {
	int data;
	char name[LEN];
	treeptr leftChild, rightChild;
} node;

int target_idx;

// 기초적인 트리 순회 함수
void preorder(treeptr ptr, char * target);  // 전위순회

void inorder(treeptr ptr, char * target);  // 중위순회
void postorder(treeptr ptr, char * target);  // 후위순회
int lca_basic(int a, int b);  // LCA 함수(완전이진트리에서만 작동가능)
void search(char* starget);


// 생명체
char species[NUM][LEN] = {
	"Magnoliopsida", "Asterales", "Fabales_big", "Asteraceae", "Argophyllaceae", "Fabales", "Polygalaceae", "Helianthus", "Cosmos", "Argophyllum", "Corokia", "Phaseolus", "Pisum", "Polygala", "FORM",
	"Helianthus_annuus", "Helianthus_debilis", "Cosmos_bipinnatus", "Cosmos_sulphureus", "ArgoPhyllum_verae", "Argophyllum_laxum", "Corkia_cotoneaster", "Corokia_virgata", "Phaseolus_vulgarts", "Pisum_sativum", "Pisum_fulvura", "Polygala_sibirica", "Polygala_japonica", "FORM", "FORM"
};


// 사용자 입력
char target[LEN], target1[LEN], target2[LEN], order[LEN];
extern int target_idx;


int a, b, c;


int main(void)
{
	node nodes[NUM + 1];
	int i, len1, len2, count = 0;


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
		printf("#%d\n\n", ++count);
        printf("노드를 입력하세요: ________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		scanf("%s", target);
		if (!strcmp(target, "q"))
		{
			puts("bye");
			break;
		}
		while (!strcmp(target, "search"))
		{
			printf("Search: ________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			scanf("%s", order);
			search(order);
			printf("\n노드를 입력하세요: ________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			scanf("%s", target);
			if (!strcmp(target, "q"))
			{
				puts("bye");
				break;
			}
		}
		preorder(&nodes[1], target);
		a = target_idx;
		printf("%s와 비교를 원하는 두 노드을 입력하세요:\n", target);
		printf("1. ________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		scanf("%s", target1);
		if (!strcmp(target1, "q"))
		{
			puts("bye");
			break;
		}
		while (!strcmp(target1, "search"))
		{
			printf("Search: ________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			scanf("%s", order);
			search(order);
			printf("1. ________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			scanf("%s", target1);
			if (!strcmp(target, "q"))
			{
				puts("bye");
				break;
			}
		}
		printf("2. ________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		scanf("%s", target2);
		if (!strcmp(target, "q"))
		{
			puts("bye");
			break;
		}
		while (!strcmp(target2, "search"))
		{
			printf("Search: ________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			scanf("%s", order);
			search(order);
			printf("2. ________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			scanf("%s", target2);
			if (!strcmp(target, "q"))
			{
				puts("bye");
				break;
			}
		}
		preorder(&nodes[1], target1);
		b = target_idx;
		preorder(&nodes[1], target2);
		c = target_idx;

		len1 = lca_basic(a, b);
		len2 = lca_basic(a, c);

		printf("\n%s와 %s의 LCA는 %s입니다.\n", target, target1, nodes[len1].name);
		printf("\n%s와 %s의 LCA는 %s입니다.\n", target, target2, nodes[len2].name);
		printf("\n\n\n");
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

void search(char* starget)
{
	int i, exist = 0;
	printf("<%s와 유사한 단어>\n", starget);
	for (i = 1; i <= NUM; i++)
		if (strstr(species[i], starget))
		{
			printf("%s\n", species[i]);
			exist = 1;
		}
	if (!exist)
		printf("검색결과가 없습니다...\n");
}

