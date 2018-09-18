#include"LinkList.h"
void InitLinkList(pList *pplist)//��ʼ��
{
	assert(pplist != NULL);
	*pplist = NULL;
}
void DistroyLinkList(pList *pplist)//��������
{
	//1.assert
	pNode cur = NULL;
	assert(pplist != NULL);
	cur = *pplist; //����һ��ָ��pList �Ľ��ָ��
	while (cur != NULL)
	{
		pNode del = cur;//����һ��ɾ�����
		cur = cur->next;
		free(del);
		del = NULL;
	}
	*pplist = NULL;
	printf("�������ٳɹ�\n");
}
pNode BuyNode(DataType d)//�����½��
{
	pNode NewNode = (pNode)malloc(sizeof(Node));//����һ���ڵ��С�Ŀռ�
	if (NewNode == NULL)
	{
		perror("malloc::BuyNode");
		exit(EXIT_FAILURE);
	}
	NewNode->data = d;//���½�㸳ֵ
	NewNode->next = NULL;
	return NewNode;
}
void PushBack(pList* pplist, DataType d)//β������
{
	//1.assert
	assert(pplist != NULL);
	//2.�����½��
	pNode NewNode = BuyNode(d);
	if (NewNode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	//3.����Ԫ��
	if (*pplist == NULL)//ppl���Ϊ������
	{
		*pplist = NewNode;
	}
	else//ppl��Ϊ������
	{
		pNode cur = *pplist;//����һ���µĽ��ָ��ppl
		while (cur->next != NULL)//ȥѰ�����Ľ��
		{
			cur = cur->next;
		}
		cur->next = NewNode;
	}
}
void PopBack(pList*pplist)//β��ɾ��,������������޽�㣬һ����㣬һ�����ϵĽ��
{
	//1.assert
	assert(pplist != NULL);
	//2.�ж����޽��
	if (*pplist == NULL)//�޽��
	{
		return;
	}
	if ((*pplist)->next==NULL)//һ�����
	{
		free(pplist);
		pplist = NULL;
		return;
	}
	else//һ�����ϵĽ��
	{
		pNode cur = *pplist;
		//��һ��д��
		//while (cur->next->next != NULL)//�ҵ�curָ���cur->next������һ��cur,��curΪ��ʱ���ҵ������һ��ֵ
		//{
		//	cur = cur->next;
		//}
		//free(cur->next);//�ͷŵ����һ��cur
		//cur->next = NULL;

		//�ڶ���д��
		pNode prev = NULL;
		while (cur->next != NULL)
		{
			prev = cur;
			cur = cur->next;
		}
		free(cur->next);
	}
}
void PushFront(pList *pplist, DataType d)//ͷ������
{
	pNode  NewNode = NULL;//����һ���½�㣬
    NewNode = BuyNode(d);
	assert(pplist != NULL);
	NewNode->next = *pplist;//�ȱ���*pplist,Ҫ��Ȼ��Ū��pplist
	*pplist = NewNode;
}
void PopFront(pList *pplist)//ͷ��ɾ��
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
pNode Find(pList plist, DataType d)//����ָ��Ԫ��
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
void Insert(pList *pplist, pNode pos, DataType d)//ָ��λ�ò���Ԫ��
{
	pNode NewNode = NULL;
	assert(pplist != NULL);
	assert(*pplist != NULL);
	assert(pos != NULL);
	if (pos == *pplist)//û�н���ʱ�� posΪ��ַ������Ҫ�õ�ַ���Ƚ�
	{
		NewNode = BuyNode(d);
		NewNode->next = *pplist;
		*pplist = NewNode;

	}
	else//�н���ʱ��
	{
		pNode cur = *pplist;
		while (cur&&cur->next != pos)//��cur Ϊ�գ�����cur->next!=posʱֹͣѭ��
		{
			cur = cur->next;
		}
		if (cur != NULL)//�ҵ���pos
		{
			NewNode = BuyNode(d);
			NewNode->next = pos;
			cur->next = NewNode;
		}
	}
}
void Erase(pList *pplist, pNode pos)//ָ��λ��ɾ��
{
	assert(pplist != NULL);
	assert(*pplist != NULL);
	assert(pos != NULL);
	if (*pplist==NULL)//û�����ݵ����
	{
		return;
	}
	if (*pplist == pos)//�ڵ�һ��λ��ɾ��
	{
		//ͷɾ
		pNode del = pos;
		*pplist = (*pplist)->next;
		free(del);
		del = NULL;
	}
	else//���λ��ɾ��
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
void Remove(pList *pplist, DataType d)//ɾ��ָ������
{
	assert(pplist != NULL);
	pNode cur = NULL;;
	pNode prev = NULL;
	cur = *pplist;

	while (cur)
	{
		if (cur->data == d)
		{
			//��һ�������
			if (*pplist == cur)
			{
				PopFront(pplist);
			}
			else//�ǵ�һ�����
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
void RemoveAll(pList *pplist, DataType d)//ɾ��ָ������
{
	assert(pplist != NULL);
	pNode cur = NULL;;
	pNode prev = NULL;
	cur = *pplist;

	while (cur)
	{
		if (cur->data == d)
		{
			//��һ�������
			if (*pplist == cur)
			{
				PopFront(pplist);
				cur = *pplist;//����������Ҫɾ����Ԫ��
			}
			else//�ǵ�һ�����
			{
				prev->next = cur->next;
				free(cur);
				cur = prev;//��Ϊcur�����ˣ����Ը�cur���¸�ֵ
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
void Print(pList plist)//��ӡ����,���ﲻ��assert,��plistΪ��ʱ��˵����Ϊ������
{
	pNode cur = plist;
	while (cur)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}
int GetListLength(pList plist)//������ĳ���
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





//������

void PrintTailToHead_R(pList plist)//�����ӡ����
{
	if (plist == NULL)
		return;
	PrintTailToHead_R(plist->next);
	printf("%d ", plist->data);
}

void PrintTailToHead(pList plist)//�����ӡ����
{
	pNode cur = NULL;
	pNode tail = NULL;
	if (plist == NULL)
	{
		return;
	}
	if (plist->next == NULL)//ֻ��һ�����
	{
		printf("%d ", plist->data);
	}
	while (plist!=tail)//��β��㲻����plist ʱ����ѭ��
	{
		cur = plist;
		while (cur->next !=tail)//���������ʱ��ӡ�������
		{
			cur = cur->next;
		}
		tail = cur;
		printf("%d ", cur->data);
	}
}
void DelNodeNotTail(pNode pos)//   �滻ɾ������ɾ��pos����һ��λ��
{
	pNode del = NULL;
	assert(pos != NULL);
	assert(pos->next != NULL);
	del = pos->next;
	//�ƶ�����
	pos->data = pos->next->data;
	//ɾ�����
	pos->next = del->next;
	free(del);
	del = NULL;
}
//����һ����������
//void InsertNode(pNode pos, DataType d)//��һ����ͷ�������һ��������һ�����
//{
//	assert(pos != NULL);
//	pNode NewNode = NULL;
//	DataType tmp = 0;
//	NewNode = BuyNode(d);
//	NewNode->next = pos->next;//��pos ��ߵ�ֵ����newNode��
//	pos->next = NewNode;
//	//��������
//	tmp = pos->data;
//	pos->data = NewNode->data;
//	NewNode->data = tmp;
//}


//����������newNode��ֱ�Ӽ���pos��ֵ���ٰ�pos��ֵ��Ϊd
void InsertNode(pNode pos, DataType d)//��һ����ͷ�������һ��������һ�����
{
	assert(pos != NULL);
	pNode NewNode = NULL;
	DataType tmp = 0;
	NewNode = BuyNode(pos->data);
	NewNode->next = pos->next;//��pos ��ߵ�ֵ����newNode��
	pos->next = NewNode;
	pos->data = d;


}

void JosephusCycle(pList *pplist, int k)//Լɪ��
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
		printf(" ɾ�� %d \n", cur->data);
		cur->data = cur->next->data;
		del = cur->next;
		cur->next = del->next;
		free(del);
		del = NULL;
	}
	printf("�Ҵ��� %d ", cur->data);
}

void ReverseList(pList *pplist)//��ת����������

{
	assert(pplist != NULL);
	pNode n1, n2, n3;//�������ķ���
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

//����������ԭ������������ͷ�巨
//void ReverseList(pList *pplist)//��ת����������
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
//		//ͷ��
//		cur->next = head;
//		head = cur;
//		cur = tmp;
//		if (tmp!=NULL)
//			tmp = tmp->next;
//	}
//	*pplist = head;
//}

void BubbleSort(pList plist)//ð������
{
	pNode tail = NULL;
	if (plist == NULL || plist->next == NULL)//����Ϊ�ջ���ֻ��һ�����
	{
		return;
	}
	while (plist != tail)//ѭ������
	{
		int flag = 0;
		pNode cur = plist;
		pNode next = cur->next;
		while (next != tail) //�Ƚϴ���
		{
			if (cur->data > next->data)//�Ƚϴ�С
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
		if (flag == 0)//���flagΪ0˵���Ѿ�����
			return;
	}
}

pList Merge(pList p1, pList p2)//��������ĺϲ����ϲ�������
{
	pList NewList = NULL;
	pNode tail = NULL;
	//����������ͬ
	if (p1 == p2)
		return;
	//һ������ΪNULL
	if (p1 ==NULL)
		return p2;
	if (p2 == NULL)
		return p1;
	//�ж�Newlist�ĵ�һ�����
	if (p1->data < p2->data)//��p1��p2���бȽϣ���С���ݷ�ǰ��
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
	//׷��ʣ��Ԫ��
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

pList Merge_R(pList p1, pList p2)//��������ĺϲ����ϲ�������
{
	pList NewList = NULL;
	//����������ͬ
	if (p1 == p2)
		return;
	//һ������ΪNULL
	if (p1 == NULL)
		return p2;
	if (p2 == NULL)
		return p1;
	//�ж�Newlist�ĵ�һ�����
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
pNode FindMidNode(pList plist)//����һ�β����м���
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
 
pNode FindLastKNode(pList plist, int k)//���ҵ�����ĵ�����K�����
{
	pNode fast = plist;
	pNode slow = plist;
	if (plist == NULL)
		return;
	//���õ�һ��ָ������K��
	while (k--)
	{
		if (fast == NULL)
		{
			return NULL;
		}
		fast = fast->next;
	}
	//ʣ�µ�fast��slowһ����
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//11. �жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������ÿ���㷨��ʱ�临�Ӷ�&�ռ临�Ӷȡ�
pNode IsCircle(pList plist)//�ж�һ�������Ƿ����
{
	pNode fast = plist;
	pNode slow = plist;
	if (plist == NULL)//������
	{
		return plist;
	}
	while ((fast != NULL) && (fast->next != NULL))
	{
		fast = fast->next->next;//��ָ����������
		slow = slow->next;//��ָ����һ��
		if (fast->data == slow->data)//�����ˣ�����һ��slow ����fast ������
		{
			return slow;
		}
	}
	return NULL;
}
int GetCircleLength(pNode meet)//���㻷�ĳ���
{
	assert(meet);
	pNode cur = meet->next;
	int len = 1;
	while (cur != meet)//��cur��meet �����ʱ����������������㡣
	{
		len++;
		cur = cur->next;
	}
	return len;
}

pNode GetCircleEntryNode(pList plist, pNode meet)//�һ���������
{
	assert(meet);
	pNode cur = plist;//��curȥ���Ǹ�������
	if (plist == NULL)
		return NULL;
	while (cur != meet)
	{
		cur = cur->next;//����ʼλ��ȥ��meet
		meet = meet->next;//meet�ڻ���
	}
	return meet;

}
////////////////////////////////////////////////////////////////////////////////////////////
//12. �ж����������Ƿ��ཻ�����ཻ���󽻵㡣���������������� 
int CheckCross(pList p1, pList p2)//����Ƿ��ཻ,����ཻ�����Ǹ��ڵ��� һ���ģ��������ǵĵ�ַҲ��ͬ��Y��
{
	pNode end1 = p1;
	pNode end2 = p2;
	if (p1 == NULL || p2 == NULL)
		return;
	while (end1->next != NULL)//��p1�ߵ����
	{
		end1 = end1->next;
	}
	while (end2->next != NULL)//��p2�ߵ����
	{
		end2 = end2->next;
	}
	return end1 == end2 ? 1 : 0;//�ж�β��ַ�Ƿ���ͬ�����������ཻ�������������ཻ
}

pNode GetCrossNode(pList p1, pList p2)//�� ��������Ľ���
{
	if (p1 == NULL || p2 == NULL)
		return;
	int len1 = 0;//������������cur1��cur2���ȵĵ�ֵ
	int len2 = 0;
	pNode cur1 = p1;//��������ָ������ͷ���ĵ�ַ
	pNode cur2 = p2;
	int gap = 0;//������������Ĳ�ֵ
	while (cur1)//����������ĳ���
	{
		len1++;
		cur1 = cur1->next;
	}
	while (cur2)
	{
		len2++;
		cur2 = cur2->next;
	}
	gap = abs(len1 - len2);//���ֵ
	if (len1 < len2)//�ѽϳ����������cur1
	{
		cur1 = p2;
		cur2 = p1;
	}
	while (gap--)//�ýϳ�����������gap��
	{
		cur1 = cur1->next;
	}
	while (cur1!=cur2)//ʣ�µ�����������ͬʱ�ߣ����������ʱ���ҵ�������
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}



///////////////////////////////////////////////////////////////////////////////////////////////////
//13. �ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿 








//////////////////////////////////////////////////////////////////////////////////////////////////
//14. ��������ĸ��ơ� 
//һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬 
//����һ��randomָ��ָ����������е�һ������ڵ����NULL�� 
//����Ҫ��ʵ�ָ�������������ظ��ƺ�������� 

pNode BuyComplexNode(DataType x)
{
	ComplexNode* p = (ComplexNode*)malloc(sizeof(ComplexNode));
	p->data = x;
	p->next = NULL;
	p->random = NULL;
	return p;
}
void PrintComplexList(ComplexNode* plist)//��ӡ��������
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
//ComplexNode* CopyComplexList(ComplexNode* plist)//����һ�����ӽڵ�
//{
//	//�ڵ�ǰ�ڵ�ĺ�߲���һ����ǰ�ڵ������
//	
//	//��������random��ָ��
//	
//	//�������
//
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//15. ����������������(�)�� 
void UnionSet(pList p1, pList p2)//����������Ľ���
{
	if (p1 == NULL || p2 == NULL)//�ж��Ƿ�Ϊ��
		return;
	while (p1&&p2)
	{
		if (p1->data < p2->data)//�ж�p1 �� p2˭��ֵС��С�������һ������Ĳ���
		{
			p1 = p1->next;
		}
		else if (p1->data>p2->data)
		{
			p2 = p2->next;
		}
		else//p1��p2��ȣ���ӡ��Ӧ��ֵ������p1��p2ͬʱ����ƶ�
		{
			printf("%d ", p1->data);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
}