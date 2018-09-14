#ifndef _LinkList_H__
#define _LinkList_H__

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


typedef int DataType;//������������
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node,List,*pNode,*pList;//������node��ά������list

void InitLinkList(pList* pplist);//��ʼ������
void DistroyLinkList(pList *pplist);//��������
pNode BuyNode(DataType d);//�����½��
void PushBack(pList* pplist, DataType d);//β������
void PopBack(pList*pplist);//β��ɾ��
void PushFront(pList *pplist, DataType d);//ͷ������
void PopFront(pList *pplist);//ͷ��ɾ��
pNode Find(pList plist, DataType d);//����ָ��Ԫ��
void Insert(pList *pplist, pNode pos, DataType d);//ָ��λ�ò���Ԫ��
void Print(pList plist);//��ӡ����
void Erase(pList *pplist,pNode pos);//ָ��λ��ɾ��
void Remove(pList *pplist, DataType d);//ɾ��ָ������
void RemoveAll(pList *pplist, DataType d);//ɾ��ָ������
int GetListLength(pList plist);//������ĳ���
void Print(pList plist);//��ӡ����,���ﲻ��assert,��plistΪ��ʱ��˵����Ϊ������


//������
void PrintTailToHead_R(pList plist);//�����ӡ����
void PrintTailToHead(pList plist);//�����ӡ����
void DelNodeNotTail(pNode pos);//ɾ��һ����ͷ������ķ�β���
void InsertNode(pNode pos,DataType d);//��һ����ͷ�������һ��������һ�����
void JosephusCycle(pList *pplist, int k);//Լɪ��
void Remove(pList *pplist, DataType d);//ɾ��ָ������
void ReverseList(pList *pplist);//��ת����������
void BubbleSort(pList plist);//ð������
pList Merge(pList p1, pList p2);//��������ĺϲ����ϲ�������
pList Merge_R(pList p1, pList p2);//��������ĺϲ����ϲ�������
pNode FindMidNode(pList plist);//����һ�β����м���
pNode FindLastKNode(pList plist,int k);//���ҵ�������˵�����K�����
pNode IsCircle(pList plist);//�ж�һ�������Ƿ����
int GetCircleLength(pNode meet);//���㻷�ĳ���
pNode GetCircleEntryNode(pList plist, pNode meet);//�һ���������
int CheckCross(pList p1, pList p2);//����Ƿ��ཻ
pNode GetCrossNode(pList p1, pList p2);//�� ��������Ľ���
//////////////////////////////////////////////////////////////////////////////////////////////////
//14. ��������ĸ��ơ� 
//һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬 
//����һ��randomָ��ָ����������е�һ������ڵ����NULL�� 
//����Ҫ��ʵ�ָ�������������ظ��ƺ�������� 
typedef struct ComplexNode
{
	DataType data;
	ComplexNode* next;
	ComplexNode* random;
}ComplexNode;

ComplexNode* BuyComplexNode(DataType x);//����һ�����ӽڵ�
void PrintComplexList(ComplexNode* plist);//��ӡ��������

ComplexNode* CopyComplexList(ComplexNode* plist);//����һ�����ӽڵ�




//////////////////////////////////////////////////////////////////////////////////////////////////////
void UnionSet(pList p1, pList p2);//����������Ľ���

#endif 