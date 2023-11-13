#pragma once
#include<iostream>
using namespace std;
#define thr  1
#define child  0
struct thrTree
{
	char data;
	bool ltag;
	bool rtag;
	thrTree* lchild;
	thrTree* rchild;
	thrTree()
	{
		ltag = child;
		rtag = child;
	}
};
thrTree* creatTree();
void print_thrTree(thrTree* head);
void visit(thrTree* head);
void in_thrTree(thrTree* head);
thrTree* find_x(thrTree* head, char x);
thrTree* lastright(thrTree* head);
char find_next(thrTree* head, char x);
char find_before(thrTree* head, char x);
void make_thrtree(thrTree* head);