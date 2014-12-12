#include <stdio.h>
#include <malloc.h>
#include "StaticList.h"

int main(void)
{
	int node1 = 1;
	int node2 = 2;
	int node3 = 3;
	int i;
	StaticList *list = StaticList_Create(5);

	int ret = StaticList_Insert(list, &node1, 0);
	StaticList_Insert(list, &node2, 0);
	StaticList_Insert(list, &node3, 0);

	if(ret == 0){
		printf(" insert errot\n");
	}
	for( i = 0; i < StaticList_Length(list); i++)
	{
		printf("get element:%d\n",*(int *)(StaticList_Get(list,i)));
		
	}

	printf("delete element:%d\n",*(int*)(StaticList_Delete(list,0)));

	for( i = 0; i < StaticList_Length(list); i++)
	{
		printf("get element:%d\n",*(int *)(StaticList_Get(list,i)));
	}	
	
	StaticList_Clear(list);
	StaticList_Destroy(list);
	

	return 0;
}

