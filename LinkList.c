#include"LinkList.h"
void InitLinkList(pList *pplist)//初始化
{
	assert(pplist != NULL);
	*pplist = NULL;
}
void DistroyLinkList(pList *pplist)//销毁链表
{
	//1.assert
	pNode cur = NULL;
	assert(pplist != NULL);
	cur = *pplist; //定义一个指向pList 的结点指针
	while (cur != NULL)
	{
		pNode del = cur;//定义一个删除结点
		cur = cur->next;
		free(del);
		del = NULL;
	}
	*pplist = NULL;
	printf("链表销毁成功\n");
}
pNode BuyNode(DataType d)//建立新结点
{
	pNode NewNode = (pNode)malloc(sizeof(Node));//开辟一个节点大小的空间
	if (NewNode == NULL)
	{
		perror("malloc::BuyNode");
		exit(EXIT_FAILURE);
	}
	NewNode->data = d;//给新结点赋值
	NewNode->next = NULL;
	return NewNode;
}
void PushBack(pList* pplist, DataType d)//尾部插入
{
	//1.assert
	assert(pplist != NULL);
	//2.建立新结点
	pNode NewNode = BuyNode(d);
	if (NewNode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	//3.插入元素
	if (*pplist == NULL)//ppl如果为空链表
	{
		*pplist = NewNode;
	}
	else//ppl不为空链表
	{
		pNode cur = *pplist;//建立一个新的结点指向ppl
		while (cur->next != NULL)//去寻找最后的结点
		{
			cur = cur->next;
		}
		cur->next = NewNode;
	}
}
void PopBack(pList*pplist)//尾部删除,分三种情况：无结点，一个结点，一个以上的结点
{
	//1.assert
	assert(pplist != NULL);
	//2.判断有无结点
	if (*pplist == NULL)//无结点
	{
		return;
	}
	if ((*pplist)->next==NULL)//一个结点
	{
		free(pplist);
		pplist = NULL;
		return;
	}
	else//一个以上的结点
	{
		pNode cur = *pplist;
		//第一种写法
		//while (cur->next->next != NULL)//找到cur指向的cur->next的再下一个cur,当cur为空时就找到了最后一个值
		//{
		//	cur = cur->next;
		//}
		//free(cur->next);//释放掉最后一个cur
		//cur->next = NULL;

		//第二种写法
		pNode prev = NULL;
		while (cur->next != NULL)
		{
			prev = cur;
			cur = cur->next;
		}
		free(cur->next);
	}
}
void PushFront(pList *pplist, DataType d)//头部插入
{
	pNode  NewNode = NULL;//创建一个新结点，
    NewNode = BuyNode(d);
	assert(pplist != NULL);
	NewNode->next = *pplist;//先保存*pplist,要不然会弄丢pplist
	*pplist = NewNode;
}
void PopFront(pList *pplist)//头部删除
{
	assert(pplist != NULL);
	if (*pplist == NULL)
	{
		return;
	}
	else
	{
		pNode del = *pplist;
		*pplist = (del->next);
		free(del);
		del = NULL;

	}
}
pNode Find(pList plist, DataType d)//查找指定元素
{
	pNode cur = plist;
	while (cur != NULL)
	{
		if (cur->data == d)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void Insert(pList *pplist, pNode pos, DataType d)//指定位置插入元素
{
	pNode NewNode = NULL;
	assert(pplist != NULL);
	assert(*pplist != NULL);
	assert(pos != NULL);
	if (pos == *pplist)//没有结点的时候， pos为地址，所以要拿地址作比较
	{
		NewNode = BuyNode(d);
		NewNode->next = *pplist;
		*pplist = NewNode;

	}
	else//有结点的时候
	{
		pNode cur = *pplist;
		while (cur&&cur->next != pos)//当cur 为空，或者cur->next!=pos时停止循环
		{
			cur = cur->next;
		}
		if (cur != NULL)//找到了pos
		{
			NewNode = BuyNode(d);
			NewNode->next = pos;
			cur->next = NewNode;
		}
	}
}
void Erase(pList *pplist, pNode pos)//指定位置删除
{
	assert(pplist != NULL);
	assert(*pplist != NULL);
	assert(pos != NULL);
	if (*pplist==NULL)//没有数据的情况
	{
		return;
	}
	if (*pplist == pos)//在第一个位置删除
	{
		//头删
		pNode del = pos;
		*pplist = (*pplist)->next;
		free(del);
		del = NULL;
	}
	else//后边位置删除
	{
		pNode cur = *pplist;
		while (cur&&cur->next != pos)
		{
			cur = cur->next;
		}
		if (cur != NULL)
		{
			cur->next = pos->next;
			free(pos);
			pos = NULL;
		}
	}
}
void Remove(pList *pplist, DataType d)//删除指定数据
{
	assert(pplist != NULL);
	pNode cur = NULL;;
	pNode prev = NULL;
	cur = *pplist;

	while (cur)
	{
		if (cur->data == d)
		{
			//第一个个结点
			if (*pplist == cur)
			{
				PopFront(pplist);
			}
			else//非第一个结点
			{
				prev->next = cur->next;
				free(cur);
				cur = NULL;
			}
			return;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
//void Remove(pList *pplist, DataType d)
//{
//	pNode pos = NULL;
//	assert(pplist != NULL);
//	pos = Find(*pplist, d);
//	if (pos != NULL)
//	{
//		Erase(pplist, pos);
//	}
//
//}
void RemoveAll(pList *pplist, DataType d)//删除指定数据
{
	assert(pplist != NULL);
	pNode cur = NULL;;
	pNode prev = NULL;
	cur = *pplist;

	while (cur)
	{
		if (cur->data == d)
		{
			//第一个个结点
			if (*pplist == cur)
			{
				PopFront(pplist);
				cur = *pplist;//接着往下找要删除的元素
			}
			else//非第一个结点
			{
				prev->next = cur->next;
				free(cur);
				cur = prev;//因为cur销毁了，所以给cur重新赋值
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
void Print(pList plist)//打印链表,这里不用assert,当plist为空时，说明它为空链表
{
	pNode cur = plist;
	while (cur)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}
int GetListLength(pList plist)//求链表的长度
{
	pNode cur = plist;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}





//面试题

void PrintTailToHead_R(pList plist)//逆序打印链表
{
	if (plist == NULL)
		return;
	PrintTailToHead_R(plist->next);
	printf("%d ", plist->data);
}

void PrintTailToHead(pList plist)//逆序打印链表
{
	pNode cur = NULL;
	pNode tail = NULL;
	if (plist == NULL)
	{
		return;
	}
	if (plist->next == NULL)//只有一个结点
	{
		printf("%d ", plist->data);
	}
	while (plist!=tail)//当尾结点不等于plist 时继续循环
	{
		cur = plist;
		while (cur->next !=tail)//当他们相等时打印结点数据
		{
			cur = cur->next;
		}
		tail = cur;
		printf("%d ", cur->data);
	}
}
void DelNodeNotTail(pNode pos)//   替换删除法，删除pos的下一个位置
{
	pNode del = NULL;
	assert(pos != NULL);
	assert(pos->next != NULL);
	del = pos->next;
	//移动数据
	pos->data = pos->next->data;
	//删除结点
	pos->next = del->next;
	free(del);
	del = NULL;
}
//方法一：交换数据
//void InsertNode(pNode pos, DataType d)//在一个无头单链表的一个结点插入一个结点
//{
//	assert(pos != NULL);
//	pNode NewNode = NULL;
//	DataType tmp = 0;
//	NewNode = BuyNode(d);
//	NewNode->next = pos->next;//把pos 后边的值挂在newNode上
//	pos->next = NewNode;
//	//交换数据
//	tmp = pos->data;
//	pos->data = NewNode->data;
//	NewNode->data = tmp;
//}


//方法二：在newNode上直接加上pos的值，再把pos的值赋为d
void InsertNode(pNode pos, DataType d)//在一个无头单链表的一个结点插入一个结点
{
	assert(pos != NULL);
	pNode NewNode = NULL;
	DataType tmp = 0;
	NewNode = BuyNode(pos->data);
	NewNode->next = pos->next;//把pos 后边的值挂在newNode上
	pos->next = NewNode;
	pos->data = d;


}

void JosephusCycle(pList *pplist, int k)//约瑟夫环
{
	pNode cur = *pplist;
	while (cur != cur->next)
	{
		pNode del = NULL;
		int count = k;
		while (--count)
		{
			cur = cur->next;
		}
		printf(" 删除 %d \n", cur->data);
		cur->data = cur->next->data;
		del = cur->next;
		cur->next = del->next;
		free(del);
		del = NULL;
	}
	printf("幸存者 %d ", cur->data);
}

void ReverseList(pList *pplist)//反转或逆置链表

{
	assert(pplist != NULL);
	pNode n1, n2, n3;//三个结点的方法
	if (*pplist == NULL)
	{
		return;
	}
	if ((*pplist)->next==NULL)
	{
		return;
	}
	n1 = *pplist;
	n2 = n1->next;
	n3 = n2->next;
	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3 != NULL)
			n3 = n3->next;
	}
	(*pplist)->next = NULL;
	*pplist = n1;
}

//方法二：在原来的链表上用头插法
//void ReverseList(pList *pplist)//反转或逆置链表
//{
//	assert(pplist != NULL);
//	
//	pNode head = NULL;
//	pNode cur = NULL;
//	pNode tmp = NULL;
//	if (*pplist == NULL || (*pplist)->next == NULL)
//		return;
//	cur = *pplist;
//	tmp = cur->next;
//	while (cur!=NULL)
//	{
//		//头插
//		cur->next = head;
//		head = cur;
//		cur = tmp;
//		if (tmp!=NULL)
//			tmp = tmp->next;
//	}
//	*pplist = head;
//}

void BubbleSort(pList plist)//冒泡排序
{
	pNode tail = NULL;
	if (plist == NULL || plist->next == NULL)//链表为空或者只有一个结点
	{
		return;
	}
	while (plist != tail)//循环趟数
	{
		int flag = 0;
		pNode cur = plist;
		pNode next = cur->next;
		while (next != tail) //比较次数
		{
			if (cur->data > next->data)//比较大小
			{
				DataType tmp = cur->data;
				cur->data = next->data;
				next->data = tmp;
				flag = 1;
			}
			cur =next;
			next = cur->next;
		}
		tail = cur;
		if (flag == 0)//如果flag为0说明已经有序
			return;
	}
}

pList Merge(pList p1, pList p2)//两个链表的合并，合并后有序
{
	pList NewList = NULL;
	pNode tail = NULL;
	//两条链表相同
	if (p1 == p2)
		return;
	//一条链表为NULL
	if (p1 ==NULL)
		return p2;
	if (p2 == NULL)
		return p1;
	//判断Newlist的第一个结点
	if (p1->data < p2->data)//把p1和p2进行比较，把小数据放前边
	{
		NewList = p1;
		p1 = p1->next;
	}
	else
	{
		NewList = p2;
		p2 = p2->next;
	}
	tail = NewList;
	while ((p1 != NULL)&&(p2 != NULL))
	{
		if (p1->data < p2->data)
		{
			tail->next = p1;
			p1 = p1->next;
		}
		else
		{
			tail->next = p2;
			p2 = p2->next;
		}
		tail = tail->next;
	}
	//追加剩余元素
	if (p1 == NULL)
	{
		tail->next = p2;
	}
	else
	{
		tail->next = p1;
	}
	return NewList;
}
//

pList Merge_R(pList p1, pList p2)//两个链表的合并，合并后有序
{
	pList NewList = NULL;
	//两条链表相同
	if (p1 == p2)
		return;
	//一条链表为NULL
	if (p1 == NULL)
		return p2;
	if (p2 == NULL)
		return p1;
	//判断Newlist的第一个结点
	if (p1->data < p2->data)
	{
		NewList = p1;
		NewList->next=Merge_R(p1->next,p2);
	}
	else
	{
		NewList = p2;
		NewList->next = Merge_R(p1, p2->next);
	}
	return NewList;
}
pNode FindMidNode(pList plist)//遍历一次查找中间结点
{
	pList fast = plist;
	pList slow = plist;
	if (fast->next->next == NULL)
		return fast->data;
	
	while ((fast->next != NULL)&&(fast!=NULL))
		{
			fast = fast->next->next;
			slow = slow->next;
		}
	return slow;
}
 
pNode FindLastKNode(pList plist, int k)//查找单链表的倒数第K个结点
{
	pNode fast = plist;
	pNode slow = plist;
	if (plist == NULL)
		return;
	//先让第一个指针先走K步
	while (k--)
	{
		if (fast == NULL)
		{
			return NULL;
		}
		fast = fast->next;
	}
	//剩下的fast和slow一起走
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//11. 判断单链表是否带环？若带环，求环的长度？求环的入口点？并计算每个算法的时间复杂度&空间复杂度。
pNode IsCircle(pList plist)//判断一个链表是否带环
{
	pNode fast = plist;
	pNode slow = plist;
	if (plist == NULL)//空链表
	{
		return plist;
	}
	while ((fast != NULL) && (fast->next != NULL))
	{
		fast = fast->next->next;//快指针走两步，
		slow = slow->next;//慢指针走一步
		if (fast->data == slow->data)//相遇了，返回一个slow 或者fast 都可以
		{
			return slow;
		}
	}
	return NULL;
}
int GetCircleLength(pNode meet)//计算环的长度
{
	assert(meet);
	pNode cur = meet->next;
	int len = 1;
	while (cur != meet)//当cur和meet 不相等时，继续向后找相遇点。
	{
		len++;
		cur = cur->next;
	}
	return len;
}

pNode GetCircleEntryNode(pList plist, pNode meet)//找环的相遇点
{
	assert(meet);
	pNode cur = plist;//让cur去找那个相遇点
	if (plist == NULL)
		return NULL;
	while (cur != meet)
	{
		cur = cur->next;//从起始位置去找meet
		meet = meet->next;//meet在环上
	}
	return meet;

}
////////////////////////////////////////////////////////////////////////////////////////////
//12. 判断两个链表是否相交，若相交，求交点。（假设链表不带环） 
int CheckCross(pList p1, pList p2)//检查是否相交,如果相交最后的那个节点是 一样的，二七他们的地址也相同，Y型
{
	pNode end1 = p1;
	pNode end2 = p2;
	if (p1 == NULL || p2 == NULL)
		return;
	while (end1->next != NULL)//让p1走到最后
	{
		end1 = end1->next;
	}
	while (end2->next != NULL)//让p2走到最后
	{
		end2 = end2->next;
	}
	return end1 == end2 ? 1 : 0;//判断尾地址是否相同。如果相等则相交，如果不相等则不相交
}

pNode GetCrossNode(pList p1, pList p2)//求 两个链表的交点
{
	if (p1 == NULL || p2 == NULL)
		return;
	int len1 = 0;//定义两个保存cur1和cur2长度的的值
	int len2 = 0;
	pNode cur1 = p1;//定义两个指向链表头结点的地址
	pNode cur2 = p2;
	int gap = 0;//保存两个链表的差值
	while (cur1)//求两个链表的长度
	{
		len1++;
		cur1 = cur1->next;
	}
	while (cur2)
	{
		len2++;
		cur2 = cur2->next;
	}
	gap = abs(len1 - len2);//求差值
	if (len1 < len2)//把较长的链表放在cur1
	{
		cur1 = p2;
		cur2 = p1;
	}
	while (gap--)//让较长的链表先走gap步
	{
		cur1 = cur1->next;
	}
	while (cur1!=cur2)//剩下的让两个链表同时走，当他们相等时就找到交点了
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}



///////////////////////////////////////////////////////////////////////////////////////////////////
//13. 判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】 








//////////////////////////////////////////////////////////////////////////////////////////////////
//14. 复杂链表的复制。 
//一个链表的每个节点，有一个指向next指针指向下一个节点， 
//还有一个random指针指向这个链表中的一个随机节点或者NULL， 
//现在要求实现复制这个链表，返回复制后的新链表。 

pNode BuyComplexNode(DataType x)
{
	ComplexNode* p = (ComplexNode*)malloc(sizeof(ComplexNode));
	p->data = x;
	p->next = NULL;
	p->random = NULL;
	return p;
}
void PrintComplexList(ComplexNode* plist)//打印复杂链表
{
	ComplexNode * cur = plist;
	while (cur)
	{
		printf("%d ", cur->data);
		if (cur->random != NULL)
			printf("(%d)-->", cur->random->data);
		else
			printf("(NULL)-->");
		cur = cur->next;
	}
	printf("over\n");

}
//ComplexNode* CopyComplexList(ComplexNode* plist)//创建一个复杂节点
//{
//	//在当前节点的后边插入一个当前节点的数据
//	
//	//调整插入random的指针
//	
//	//拆除链表
//
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//15. 求两个有序单链表交集(差集)。 
void UnionSet(pList p1, pList p2)//求两个链表的交集
{
	if (p1 == NULL || p2 == NULL)//判断是否为空
		return;
	while (p1&&p2)
	{
		if (p1->data < p2->data)//判断p1 和 p2谁的值小，小的向后走一步。大的不动
		{
			p1 = p1->next;
		}
		else if (p1->data>p2->data)
		{
			p2 = p2->next;
		}
		else//p1和p2相等，打印相应的值，并且p1和p2同时向后移动
		{
			printf("%d ", p1->data);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
}