#define _CRT_SECURE_NO_WARNINGS 1
#define SEQ_INIT_SUZE 9//初始容量
#define SEQ_INC_SIZE 2  //
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int ElemType;
typedef struct
{
	ElemType* data ;
	int capacity;//容量；
	int cursize;//元素个数；
}Seqlist;
int re_capacity(Seqlist*plist)//返回容量；
{
	assert(plist);
	return plist->capacity;
}
int re_cursize(Seqlist* plist)//返回现存元素；
{
	assert(plist);
	return plist->cursize;
}
int add_capacity(Seqlist*plist)
{
	assert(plist);
	if (re_capacity(plist) == re_cursize(plist))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void Init(Seqlist* plist)//结构体初始化；
{
	assert(plist);
	plist->capacity = SEQ_INIT_SUZE;
	plist->cursize = 0;
	plist->data = (ElemType*)malloc(sizeof(ElemType) * plist->capacity);
	if (plist->data == NULL)
	{
		exit(EXIT_FAILURE);
	}
}
void Depo_data(Seqlist* plist)//顺序表填充数据；
{
	assert(plist);
	for (int i = 0; i < 8; i++)
	{
		plist->data[i] = i;
		plist->cursize++;
	}
}
void Insert_data(Seqlist* plist)//插入一个数据；
{
	assert(plist);
	int n, num;//n——位置，num——添加的数据；
	printf("请输入插入位置 n，插入数据 num\n");
	scanf("%d %d", &n, &num);
	for (int i = plist->cursize-1; i >= n; i--)
	{
		plist->data[i + 1] = plist->data[i];
	}
	plist->data[n] = num;
	plist->cursize++;
	if (add_capacity(plist))//判断是否需要扩容；
	{
		ElemType* data = (ElemType*)realloc(plist->data, plist->capacity * SEQ_INC_SIZE);
		plist->capacity *= SEQ_INC_SIZE;
	}
}
void Insert_data_head(Seqlist* plist)//首行插入；
{
	assert(plist);
	int num = 0;
	printf("在首行插入一个数据，请输入一个数据：\n");
	scanf("%d", &num);
	for (int i = plist->cursize-1; i >= 0; i--)
	{
		plist->data[i + 1] = plist->data[i];
	}
	plist->data[0] = num;
	plist->cursize++;
	if (add_capacity(plist))//判断是否需要扩容；
	{
		ElemType* data1 = (ElemType*)realloc(plist->data, plist->capacity * SEQ_INC_SIZE);
		plist->data = data1;
		plist->capacity *= SEQ_INC_SIZE;
	}
}
void Insert_data_back(Seqlist* plist)//末尾插入；
{
	assert(plist);
	int num = 0;
	printf("在尾行插入一个数据，请输入一个数据：\n");
	scanf("%d", &num);
	plist->data[plist->cursize] = num;
	plist->cursize++;
	if (add_capacity(plist))//判断是否需要扩容；
	{
		ElemType* data1 = (ElemType*)realloc(plist->data, plist->capacity * SEQ_INC_SIZE);
		plist->data = data1;
		plist->capacity *= SEQ_INC_SIZE;
	}
}
void print(Seqlist* plist)
{
	assert(plist);
	for (int i = 0; i < plist->cursize; i++)
	{
		printf("%d ", plist->data[i]);
	}
	printf("\n");
	printf("现存元素数：%d\n", plist->cursize);
	printf("顺序表容量：%d\n", plist->capacity);
}
int main()
{
	Seqlist plist = { 0 };
	Init(&plist);
	Depo_data(&plist);
	Insert_data(&plist);
	Insert_data_head(&plist);
	Insert_data_back(&plist);
	print(&plist);
	return 0;
}