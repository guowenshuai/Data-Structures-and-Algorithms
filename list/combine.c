#include <stdio.h>
/*连接两个带有尾指针的循环单链表，并设置尾指针为A*/

LinkList merge1_list(LinkList A, LinkList B){/*方法1：去掉A的头指针*/
	ListNode *p, *q;
	p = A->next;
	q = p->next;
	A-next = B->next;
	B->next = q;
	free(p);
	return A;

}

LinkList merge2_list(LinkList A, LinkList B){/*方法2：去掉B的头指针*/
	ListNode *p, *q;
	p = A->next;
	q = B->next;
	B->next = p->next;
	p->next = q;
	free(q);
	return A;

}
