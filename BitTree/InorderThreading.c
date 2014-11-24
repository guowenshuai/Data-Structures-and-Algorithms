/*
 * 将二叉树按中序线索化的算法
 *
 */
 
#include <stdio.h>
#include <malloc.h>

typedef char DataType;
typedef enum {Link, Thread} PointerTag;
typedef struct node {
	DataType data;
	PointerTag ltag, rtag;
	struct node *lchild, *rchild;
} BiThrNode;
typedef BiThrNode *BiThrTree;

BiThrTree InorderThrfind (BiThrTree p, DataType data);
BiThrTree InorderThrfindjd (BiThrTree p);
void TraverserInOrderThreading (BiThrTree p);
void InorderThreading (BiThrTree p);

BiThrNode *pre = NULL; //全局的指针  前趋
/*将二叉树 按中序线索化的算法*/
void InorderThreading (BiThrTree p) {
	
	if (p) {
		InorderThreading (p->lchild);
		p->ltag = (p->lchild) ? Link : Thread;
		p->rtag = (p->rchild) ? Link : Thread; 
		
		if (pre) {
			
			if (p->ltag == Thread)
				p->lchild = pre;
			if (pre->rtag == Thread)
				pre->rchild = p;
		}
		pre = p;
		InorderThreading (p->rchild);
	}	
	return;
}

/*遍历中序线索二叉树*/
void TraverserInOrderThreading (BiThrTree p) {

	if (p) {
		while (p->ltag == 0)
			p = p->lchild;
		printf("find the head:\n");
		
		while (p) {
			printf("%c\n",p->data);
			p = InorderThrfindjd (p);	//找到该节点的 后继节点
		}
	}

}

 /* 中序线索二叉树 查找后继节点 ———— 设计思想从跟节点开始*/
BiThrTree InorderThrfind (BiThrTree p, DataType data) {
	/*找到线索二叉树的起始节点*/
	if (p) {
		while (p->ltag == 0) 
			p = p->lchild;
	}	
	/* 找到data节点 */
	while (p->data != data) 
		p = p->rchild;
	
	/* 查找该节点的后继 */
	if (p->rtag == 1)
		return p->rchild;
	else {
		p = p->rchild;
		while (p->ltag == 0)
			p = p->lchild;		
		return p;
	}
		
	
	
}
	
BiThrTree InorderThrfindjd (BiThrTree p) {	
	/* 查找该节点的后继 */
	if (p->rtag == 1)
		return p->rchild;
	else {
		p = p->rchild;
		while (p->ltag == 0)
			p = p->lchild;		
		return p;
	}

}


 /* 中序创建二叉树 */
void CreateBiTree (BiThrTree *T) {
	DataType ch;
	scanf ("%c%*c",&ch);
	if (ch == '#') 
		*T = NULL;
	else {
		(*T) = (BiThrTree) malloc(sizeof(BiThrNode));
		if(!(*T))
			return;
		(*T)->data = ch;
		CreateBiTree (&(*T)->lchild);
		CreateBiTree (&(*T)->rchild);
	}
	return;
}
 /*前序遍历二叉树*/
void PreOrderTraverse (BiThrTree T) {
	if (T == NULL)
		return;
	printf ("%c\n",T->data);
	PreOrderTraverse (T->lchild);
	PreOrderTraverse (T->rchild);
	return;
}


int main (void)	{
	BiThrNode *T = NULL;
	CreateBiTree (&T);
	PreOrderTraverse (T);
	InorderThreading (T);
	TraverserInOrderThreading(T);

	BiThrTree ret = NULL;
	char data = 'E';
	ret = InorderThrfind(T, data);	
	printf("ret->data:%c\n",ret->data);
}
