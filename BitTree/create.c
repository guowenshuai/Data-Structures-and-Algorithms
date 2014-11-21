 /* 创建二叉树 */
#include <stdio.h>
#include <malloc.h>

typedef char TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;

} BiTNode;
typedef BiTNode * BiTree;

/*
 *    创建二叉树
 *每个节点的空指针引出一个虚节点，当输入为‘#’时即判断为空
 *如果要操作指针，传入的参数要是二级指针
 */
void CreateBiTree (BiTree *T) {

	TElemType ch;
		/*	scanf()函数从缓冲区读入数据流		 当scanf函数以%c格式接收单个字符时,
		 *								     空格、回车、Tab键将不再作为分隔符,它们以ASCII码形式存储到对应参数地址所在内存空间。
		 *	方法一、百分号(%)与格式符之间的星号(*)表示读指定类型的数据但不保存
		 *	方法二、空白字符会使scanf()函数在读操作中略去输入中的一个或多个空白字符。
		 *	方法三、在scanf ("%c",&ch); 后加getchar();吸收掉stdin中的回车符
		 */
//	scanf (" %c",&ch);
	scanf ("%c%*c",&ch);
	getchar();
	if(ch == '#') {
		(*T) = NULL;
		printf("NULL=====\n");
	}
	else 
	{
		(*T) = (BiTNode *)malloc(sizeof(BiTNode));
		if( !(*T) ) 
			return;
		(*T)->data = ch;
		printf("left in\n");
		CreateBiTree (&(*T)->lchild);
		printf("left out right in\n");
		CreateBiTree (&(*T)->rchild);
		printf("right out\n");
	}
	
}

/* 二叉树的前序遍历 */
void PreOrderTraverse (BiTree T) {
	
	if ( NULL == T)
		return;
	printf ("%c\n",T->data);
	PreOrderTraverse (T->lchild);
	PreOrderTraverse (T->rchild);
}

/* 二叉树的中序遍历 */
void InOrderTraverse (BiTree T) {
	
	if ( NULL == T)
		return;
	InOrderTraverse (T->lchild);
	printf ("%c\n",T->data);
	InOrderTraverse (T->rchild);
}

/* 二叉树的后序遍历 */
void PostOrderTraverse (BiTree T) {
	
		if ( NULL == T)
			return;
		PostOrderTraverse (T->lchild);
		PostOrderTraverse (T->rchild);
		printf ("%c\n",T->data);
}


int main(void) {
	
	BiTNode *T=NULL;
	CreateBiTree (&T);
	printf("前序遍历\n");
	PreOrderTraverse (T);
	printf("中序遍历\n");
	InOrderTraverse (T);
	printf("后序遍历\n");
	PostOrderTraverse (T);
	return 0;
}
