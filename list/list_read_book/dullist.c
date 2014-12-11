#include <stdio.h>
#include <malloc.h>

#define false 0
#define true 1

typedef char DataType;

typedef struct DulNode{
	DataType data;
	struct DulNode *prior;
	struct DulNode *next;
}DulNode, *DulLinkList;

/*新建双向链表-尾插法*/
DulLinkList create_DulList_tail(){
	DulLinkList head, r;
	DulNode *new;
	DataType ch;
	head = (DulLinkList )malloc(sizeof(DulNode));
	head->next = NULL;
	head->prior = NULL;
	r = head;
	printf("请输入字符串，以$结尾\n");
	ch = getchar();
	while(ch != '$'){
		new = (DulNode *)malloc(sizeof(DulNode));
		new->data = ch;
		r->next = new;
		new->prior = r;
		r = new;
		ch = getchar();	
	}
	r->next = NULL;
	return head;	
}

/*打印链表内容*/
void Printlist(DulLinkList L){
	DulNode *p;
	p = L;
	printf("the contents of list\n");
	while(p->next != NULL){
		p = p->next;
		printf("%4c\n",p->data);
	}
	printf("that is all\n");
}

/*查找*/
DulNode * GetElem(DulLinkList L, int i){
	DulNode *p = L;
	if(i == 0)
		return L;
	int j = 0;
	while((j!=i) && (p->next!=NULL)){
		p = p->next;
		j++;
	}
	
	return p;
}
/*循环链表的插入,插入到第i个节点*/
int DulInsert(DulLinkList L, DataType ch, int i){
	DulNode *p,*q=NULL;
	q = GetElem(L,i-1);
	if(q == NULL)
		return false;
	p = (DulNode *)malloc(sizeof(DulNode));
	p->data = ch;
	
/*	p->prior = q->prior;
	p->next = q;
	q->prior->next = p;
	q->prior = p;
*/	
	if(q->next == NULL){
		p->next = q->next;
		q->next = p; 
		p->prior = q;
	}
	else{
		q->next->prior = p;
		p->prior = q;
		p->next = q->next;
		q->next = p;
	}
	return true;
}



int main(){
	DulLinkList head;
	head = create_DulList_tail();
	Printlist(head);

	int i,flag;
	DataType ch;
	ch = getchar();
	while(ch != '$')
	{
		
		printf("输入想要插入的元素，输入$符号退出：");
			ch = getchar();
				if(ch == '$')
					break;
		printf("插入元素的节点位置：");
			scanf("%d",&i);
		flag = DulInsert(head, ch, i);
			if(flag) 
				printf("insert success\n");
			else
			{
				printf("insert default\n");
			}	
		Printlist(head);
		ch = getchar();	
	}		
		
	return 0;	
	

}















