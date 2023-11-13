#include"thrtree.h"
thrTree* pre = NULL;
//创建一个为线索化的二叉树
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
//打印头节点
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
//处理当前节点，分为处理当前节点的前驱与pre节点的后继
void visit(thrTree* head)
{
	//如果无左子树，则将其改为前驱
	//处理当前节点的前驱与处理pre的后驱，最后处理剩余后驱
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
//线索化二叉树
void in_thrTree(thrTree* head)
{
	if (head)
	{
		in_thrTree(head->lchild);
		visit(head);
		in_thrTree(head->rchild);
		//递归之后pre==head;
	}
	return;
}
//返回目标节点
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
//返回最右的节点
thrTree* lastright(thrTree* head)
{
	while (head->rtag == 0)
	{
		head = head->rchild;
	}
	return head;
}
//返回目标的前驱节点
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
//返回目标的后继节点
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
		//递归之后处理最后的pre
		pre->rtag = thr;
		pre->rchild = NULL;
	}
	return;
}