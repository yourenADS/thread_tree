#include"thrtree.h"
int main()
{
	thrTree* head = NULL;
	printf("���������������(��:ABD0G000CE00F00)\n");
	head = creatTree();
	make_thrtree(head);
	print_thrTree(head);
	cout << endl;
	char a;
	cin >> a;
	cout << find_before(head,a)<<a << find_next(head, a)<< endl;
	return 0;
}