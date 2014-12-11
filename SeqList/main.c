#include <stdio.h>
#include "SeqList.h"

int main (void)
{	
		SeqList* list;
		int capacity = 10;
		int array[10] = {1,2,3,4,5,6,7,8,9,10};
		int i = 0;

		list = SeqList_Create(capacity);
		printf("list was empty,length=%d\n",SeqList_Length(list));
		for (i=0; i<10; i++)
		{
				SeqList_Insert(list, &array[i], 0);
				printf("Insert node,length=%d\n",SeqList_Length(list));
		}
		SeqListNode* delnode = SeqList_Delete(list, 4);
		printf("--------del node elem=%d\n",*(int*)delnode);
		SeqList_print(list);
		SeqList_clear(list);
		printf("list was empty,length=%d\n",SeqList_Length(list));
		SeqList_Destory(list);
}
