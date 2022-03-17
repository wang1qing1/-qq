#define _CRT_SECURE_NO_WARNINGS 1
#define SEQ_INIT_SUZE 9//��ʼ����
#define SEQ_INC_SIZE 2  //
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int ElemType;
typedef struct
{
	ElemType* data ;
	int capacity;//������
	int cursize;//Ԫ�ظ�����
}Seqlist;
int re_capacity(Seqlist*plist)//����������
{
	assert(plist);
	return plist->capacity;
}
int re_cursize(Seqlist* plist)//�����ִ�Ԫ�أ�
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
void Init(Seqlist* plist)//�ṹ���ʼ����
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
void Depo_data(Seqlist* plist)//˳���������ݣ�
{
	assert(plist);
	for (int i = 0; i < 8; i++)
	{
		plist->data[i] = i;
		plist->cursize++;
	}
}
void Insert_data(Seqlist* plist)//����һ�����ݣ�
{
	assert(plist);
	int n, num;//n����λ�ã�num������ӵ����ݣ�
	printf("���������λ�� n���������� num\n");
	scanf("%d %d", &n, &num);
	for (int i = plist->cursize-1; i >= n; i--)
	{
		plist->data[i + 1] = plist->data[i];
	}
	plist->data[n] = num;
	plist->cursize++;
	if (add_capacity(plist))//�ж��Ƿ���Ҫ���ݣ�
	{
		ElemType* data = (ElemType*)realloc(plist->data, plist->capacity * SEQ_INC_SIZE);
		plist->capacity *= SEQ_INC_SIZE;
	}
}
void Insert_data_head(Seqlist* plist)//���в��룻
{
	assert(plist);
	int num = 0;
	printf("�����в���һ�����ݣ�������һ�����ݣ�\n");
	scanf("%d", &num);
	for (int i = plist->cursize-1; i >= 0; i--)
	{
		plist->data[i + 1] = plist->data[i];
	}
	plist->data[0] = num;
	plist->cursize++;
	if (add_capacity(plist))//�ж��Ƿ���Ҫ���ݣ�
	{
		ElemType* data1 = (ElemType*)realloc(plist->data, plist->capacity * SEQ_INC_SIZE);
		plist->data = data1;
		plist->capacity *= SEQ_INC_SIZE;
	}
}
void Insert_data_back(Seqlist* plist)//ĩβ���룻
{
	assert(plist);
	int num = 0;
	printf("��β�в���һ�����ݣ�������һ�����ݣ�\n");
	scanf("%d", &num);
	plist->data[plist->cursize] = num;
	plist->cursize++;
	if (add_capacity(plist))//�ж��Ƿ���Ҫ���ݣ�
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
	printf("�ִ�Ԫ������%d\n", plist->cursize);
	printf("˳���������%d\n", plist->capacity);
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