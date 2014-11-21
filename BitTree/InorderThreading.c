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

BiThrNode *pre = NULL; //全局的指针  前趋
/*中序线索二叉树的建立*/
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
			p = p->rchild;
		}
	}

}


 /* 创建 */
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

}
