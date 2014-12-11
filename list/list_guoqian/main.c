#include <stdio.h>
#include <malloc.h>
#include "LinkList.h"

struct LinkListData
{
	LinkListNode header;
	int value;
};

int main(void)
{
	int i;
	LinkList* list = LinkList_Create();

	struct LinkListData v1 = {
		.value = 11,
	};
	struct LinkListData v2 = {
		.value = 22,
	};
	struct LinkListData v3 = {
		.value = 33,
	};
	struct LinkListData v4 = {
		.value = 44,
	};
	struct LinkListData v5 = {
		.value = 55,
	};

	LinkList_Insert(list, (LinkListNode*)&v1, 0);
	LinkList_Insert(list, (LinkListNode*)&v2, 0);
	LinkList_Insert(list, (LinkListNode*)&v3, 0);
	LinkList_Insert(list, (LinkListNode*)&v4, 0);
	LinkList_Insert(list, (LinkListNode*)&v5, 0);
	
	LinkList_Delet(list, 1);

	struct LinkListData* p = NULL;

	for(i = 0; i < LinkList_Length(list); i++)
	{
 		p = (struct LinkListData*)LinkList_Get(list, i);
		printf("%d\n",p->value);
	}

	LinkList_Clear(list);
	LinkList_Destroy(list);

	return 0;
}
