#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define LISTSIZE 100
#define INCREMENT 10
#define OVERFLOW -1

typedef int Elemtype;
typedef struct
{
	Elemtype * elem;//元素存储首地址
	int length;//表元素的长度
	int listsize;	//大小
}Seqlist;

void Initlist(Seqlist *L){//初始化顺序表
	L->elem = (Elemtype *)malloc(LISTSIZE*sizeof(Elemtype));//申请存储空间
	if(!L->elem) exit(OVERFLOW);
	L->length = 0;
	L->listsize = LISTSIZE;	
	
}

//insert
void ListInsert(Seqlist *L, Elemtype e, int i){//链表 、 元素 、 节点
	Elemtype *newbase;
	int j;
	if(i<1 || i>L->length)//此长度的判断，节点范围
	{
		exit -1;
	}
	if(L->length > L->listsize){
		newbase = (Elemtype *)malloc(sizeof(Elemtype)*LISTSIZE+INCREMENT);
		if(!newbase) exit(OVERFLOW);
		L->elem = newbase;
		L->listsize +=INCREMENT;
	}
	for(j=L->length-1; j>=i-1; j--){
		L->elem[j+1] = L->elem[j];
	}
	L->elem[i-1] = e;
	L->length++;

}

void PrintList(Seqlist *L){
	int i;
	if(L->length == 0)
		printf("no elem\n");
	else for(i=0; i<L->length; i++)
		printf("%2d\n",L->elem[i]);
}

int main(){
	Seqlist list;	
	Initlist(&list);
		ListInsert(&list,10,1);
		PrintList(&list);
	return 0;
}
