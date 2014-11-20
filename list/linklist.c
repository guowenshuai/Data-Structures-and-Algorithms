#include<stdio.h>
#include<malloc.h>

#define false 0
#define true 1
typedef char DataType;
typedef struct node{
	DataType data;
	struct node *next;
}ListNode;
typedef ListNode * LinkList;

/*单链表-初始化*/
/*LinkList InitList(LinkList L){
	L = (LinkList)malloc(sizeof(ListNode));
	L->next = NULL;
	return L;
}*/

	/*循环链表-初始化*/
	LinkList InitList(LinkList L){
		L = (LinkList)malloc(sizeof(ListNode));
		L->next = L;
		return L;
	}	

/*头插法建立链表*/
LinkList Create_list_front(){
	LinkList head;
	ListNode *new;
	char ch;
	head = (LinkList)malloc(sizeof(ListNode));
	head->next = NULL;
	ch = getchar();
	while(ch != '$'){
		new = (ListNode *)malloc(sizeof(ListNode));
		new->data = ch;
		new->next = head->next;
		head->next = new;
		ch = getchar();
	}	
	return head;
}

/*尾插法建立链表*/
LinkList Create_list_tail(){
	LinkList head,r;
	ListNode *new;
	DataType ch;
	head = (LinkList)malloc(sizeof(ListNode));
	head->next = head;//循环单链表
//	head->next = NULL;//单链表
	
	r = head;
	ch = getchar();
	while(ch != '$'){
		new = (ListNode *)malloc(sizeof(ListNode));
		new->data = ch;
		r->next = new;
		r = new;
	//	printf("addr%p\n",r);
		ch = getchar();
	}
//	r->next = NULL;//单链表
	r->next = head;//循环单链表
	return head;
}

/*打印链表内容*/
void PrintList(LinkList L){
	ListNode *p;
	p = L;
	printf("the contents of th list:\n");
	//while(p->next != NULL)//单链表
	while(p->next != L)//循环单链表
	{
		p = p->next;	
		printf("%4c\n",p->data);
	}
	printf("that is all\n");
}

/*查找 按节点*/
ListNode * GetElem(LinkList L, int i){
	ListNode *p = L->next;
	int j = 1;
	if( 0 == i)
		return L;
	//while( (j!=i) && (p!=NULL) )//单链表
	while( (j!=i) && (p!=L) )//循环单链表
	{
		p = p->next;
		j++;
	}
	return p;
}
/*查找 按值*/
ListNode * PriceElem(LinkList L, DataType ch){
	ListNode *p = L->next;
	while( p!=NULL && p->data!=ch ){
		p = p->next;
	}
	
	return p;
}

/*插入 在第i个节点之前*/
int ListInsert(LinkList L, DataType e, int i){
	ListNode *p = NULL,*s;
	p = GetElem(L,i-1);
	if(p == NULL) 
		return false;
	s = (ListNode *)malloc(sizeof(ListNode));
	s->data	= e;
	s->next = p->next;
	p->next = s;
	return true;
}

/*删除第i个节点*/
int ListDelete(LinkList L, int i){
	ListNode *p = NULL,*q = NULL;
	p = GetElem(L,i-1);
	if(p==NULL || p->next==NULL) return false;
	q = p->next;
	p->next = q->next;
	free(q);
	return true;
}



int main(){
	printf("输入字符串创建链表，以‘$’为结束符\n");
	LinkList head;
	ListNode *p;
	int i,flag;
	DataType ch;
	//head = Create_list_front();
	head = Create_list_tail();
	PrintList(head);
/*链表插入的使用*/
/*	ch = getchar();//问题阿！！！！！！！！！！！
	while(1)
	{	
		printf("要添加的字符,输入'$'号结束:");
			ch = getchar();
			if(ch=='$')
				break;
		printf("要插入的节点处:");
			scanf("%d",&i);
		flag = ListInsert(head,ch,i);
		if(flag) printf("insert success\n");
		PrintList(head);
		ch = getchar();//问题阿！！！！！！！！！！1
	}	*/
	/*链表的删除*/
	while(1){
		printf("要删除的节点:");
		scanf("%d",&i);
		flag = ListDelete(head,i);
		if(flag) printf("delete success.\n");
			else printf("delete fault.\n");
		PrintList(head);
	
	}

/*	
	p = GetElem(head,i);
	printf("%c\n",p->data);		*/
	return 0;	
	
}
