#include"thrtree.h"
thrTree* pre = NULL;
//����һ��Ϊ�������Ķ�����
thrTree* creatTree()
{
	char temp;
	cin >> temp;
	thrTree* head;
	if (temp == '0')
	{
		return NULL;
	}
	else
	{
		head = new thrTree;
		head->data = temp;
		head->lchild = creatTree();
		head->rchild = creatTree();
	}
	return head;
}
//��ӡͷ�ڵ�
void print_thrTree(thrTree* head)
{
	if (head == NULL)
	{
		return;
	}
	if (head->ltag == child)
		print_thrTree(head->lchild);
	cout << head->data << " ";
	if (head->rtag == child)
		print_thrTree(head->rchild);
	return;
}
//����ǰ�ڵ㣬��Ϊ����ǰ�ڵ��ǰ����pre�ڵ�ĺ��
void visit(thrTree* head)
{
	//������������������Ϊǰ��
	//����ǰ�ڵ��ǰ���봦��pre�ĺ����������ʣ�����
	if (head->lchild == NULL)
	{
		head->ltag = thr;
		head->lchild = pre;
	}
	if (pre != NULL && pre->rchild == NULL)
	{
		pre->rtag = thr;
		pre->rchild = head;
	}
	pre = head;
	return;
}
//������������
void in_thrTree(thrTree* head)
{
	if (head)
	{
		in_thrTree(head->lchild);
		visit(head);
		in_thrTree(head->rchild);
		//�ݹ�֮��pre==head;
	}
	return;
}
//����Ŀ��ڵ�
thrTree* find_x(thrTree* head, char x)
{
	thrTree* left = NULL, * right = NULL;
	if (head && head->data == x) {
		return head;
	}
	if (head == NULL || (head->rtag == thr && head->ltag == thr))
	{
		return NULL;
	}
	else
	{
		if (head->ltag == 0)
		{
			left = find_x(head->lchild, x);
		}
		if (head->rtag == 0)
		{
			right = find_x(head->rchild, x);
		}
	}
	return right == NULL ? left : right;
}
//�������ҵĽڵ�
thrTree* lastright(thrTree* head)
{
	while (head->rtag == 0)
	{
		head = head->rchild;
	}
	return head;
}
//����Ŀ���ǰ���ڵ�
char find_before(thrTree* head, char x)
{
	thrTree* target = find_x(head, x);
	if (target == NULL)
	{
		return '0';
	}
	if (target->ltag = thr)
	{
		if (target->lchild)
			return target->lchild->data;
		else
		{
			return '0';
		}
	}
	else
	{
		return lastright(target->lchild)->data;
	}
}
//����Ŀ��ĺ�̽ڵ�
char find_next(thrTree* head, char x)
{
	thrTree* target = find_x(head,x);
	if (target == NULL)
	{
		return '0';
	}
	if (target->rtag == thr)
	{
		if (target->rchild)
		{
			return target->rchild->data;
		}
		else
		{
			return '0';
		}
	}
	else
	{
		thrTree* temp = target->rchild;
		while (temp->ltag == 0)
		{
			temp = temp->lchild;
		}
		return temp->data;
	}
}
void make_thrtree(thrTree* head)
{
	if (head)
	{
		in_thrTree(head);
		//�ݹ�֮��������pre
		pre->rtag = thr;
		pre->rchild = NULL;
	}
	return;
}