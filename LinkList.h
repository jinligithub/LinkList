#ifndef _LinkList_H__
#define _LinkList_H__

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


typedef int DataType;//给类型重命名
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node,List,*pNode,*pList;//定义结点node和维护链表list

void InitLinkList(pList* pplist);//初始化链表
void DistroyLinkList(pList *pplist);//销毁链表
pNode BuyNode(DataType d);//建立新结点
void PushBack(pList* pplist, DataType d);//尾部插入
void PopBack(pList*pplist);//尾部删除
void PushFront(pList *pplist, DataType d);//头部插入
void PopFront(pList *pplist);//头部删除
pNode Find(pList plist, DataType d);//查找指定元素
void Insert(pList *pplist, pNode pos, DataType d);//指定位置插入元素
void Print(pList plist);//打印链表
void Erase(pList *pplist,pNode pos);//指定位置删除
void Remove(pList *pplist, DataType d);//删除指定数据
void RemoveAll(pList *pplist, DataType d);//删除指定数据
int GetListLength(pList plist);//求链表的长度
void Print(pList plist);//打印链表,这里不用assert,当plist为空时，说明它为空链表


//面试题
void PrintTailToHead_R(pList plist);//逆序打印链表
void PrintTailToHead(pList plist);//逆序打印链表
void DelNodeNotTail(pNode pos);//删除一个无头单链表的非尾结点
void InsertNode(pNode pos,DataType d);//在一个无头单链表的一个结点插入一个结点
void JosephusCycle(pList *pplist, int k);//约瑟夫环
void Remove(pList *pplist, DataType d);//删除指定数据
void ReverseList(pList *pplist);//反转或逆置链表
void BubbleSort(pList plist);//冒泡排序
pList Merge(pList p1, pList p2);//两个链表的合并，合并后有序
pList Merge_R(pList p1, pList p2);//两个链表的合并，合并后有序
pNode FindMidNode(pList plist);//遍历一次查找中间结点
pNode FindLastKNode(pList plist,int k);//查找单链表夫人倒数第K个结点
pNode IsCircle(pList plist);//判断一个链表是否带环
int GetCircleLength(pNode meet);//计算环的长度
pNode GetCircleEntryNode(pList plist, pNode meet);//找环的相遇点
int CheckCross(pList p1, pList p2);//检查是否相交
pNode GetCrossNode(pList p1, pList p2);//求 两个链表的交点
//////////////////////////////////////////////////////////////////////////////////////////////////
//14. 复杂链表的复制。 
//一个链表的每个节点，有一个指向next指针指向下一个节点， 
//还有一个random指针指向这个链表中的一个随机节点或者NULL， 
//现在要求实现复制这个链表，返回复制后的新链表。 
typedef struct ComplexNode
{
	DataType data;
	ComplexNode* next;
	ComplexNode* random;
}ComplexNode;

ComplexNode* BuyComplexNode(DataType x);//创建一个复杂节点
void PrintComplexList(ComplexNode* plist);//打印复杂链表

ComplexNode* CopyComplexList(ComplexNode* plist);//创建一个复杂节点




//////////////////////////////////////////////////////////////////////////////////////////////////////
void UnionSet(pList p1, pList p2);//求两个链表的交集

#endif 