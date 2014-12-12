#include <stdio.h>
#include <malloc.h>
#include "StaticList.h"

#define AVAILABLE -1

typedef struct ListNode_struct
{
	unsigned int data;
	int next;
} TStaticListNode;

typedef struct List_struct
{
	int capacity;
	TStaticListNode header;
	TStaticListNode node[];
} TStaticList;

StaticList* StaticList_Create(int capacity)
{
	TStaticList* ret = NULL;
	int i;

	if( capacity >= 0 )
	{
		ret = (TStaticList*)malloc(sizeof(TStaticList) + sizeof(TStaticListNode) * capacity);

		if( ret != NULL)
		{
			ret->capacity = capacity;
			ret->header.data = 0;
			ret->header.next = 0;
		}

		for( i = 0; i <= capacity; i++ )
		{
			ret->node[i].next = AVAILABLE;
		}
	}
	return ret;
}

void StaticList_Destroy(StaticList* list)
{
	free(list);
}

void StaticList_Clear(StaticList* list)
{
	TStaticList* slist = (TStaticList*)list;
	int i;

	if( slist != NULL )
	{
		slist->header.data = 0;
		slist->header.next = 0;
		
		for(i = 0; i <= slist->capacity; i++)
		{
			slist->node[i].next = AVAILABLE;
		}
	}
}

int StaticList_Length(StaticList* list)
{
	TStaticList* slist = (TStaticList*)list;
	int ret = 0;

	if( slist != NULL )
	{
		ret = slist->header.data;
	}

	return ret;
}

int StaticList_Insert(StaticList* list, StaticListNode* node, int pos)
{
	TStaticList* slist = (TStaticList*)list;
	int ret = ((slist->header.data + 1) < slist->capacity) && ( slist != NULL ) && ( node != NULL ) && ( pos <= slist->header.data );
	int i = 0;
	int index = 0;
	int current = 0;

	if( ret )
	{
		for( i = 1; i < slist->capacity; i++)	//获取第一个可用的静态链表数组
		{
			if( slist->node[i].next == AVAILABLE )
			{	index = i;
				break;
			}
		}

		slist->node[index].data = (unsigned int)node;	//赋值
	
		slist->node[0] = slist->header;
		
		for( i = 0; i < pos && slist->node[current].next != 0; i++)	//找到静态链表的pos处
		{
			current = slist->node[current].next;
		}

		slist->node[index].next = slist->node[current].next;
		slist->node[current].next = index;

		slist->node[0].data++;
		slist->header = slist->node[0];
	}
	return ret;
}

StaticListNode* StaticList_Get(StaticList *list, int pos)
{
	TStaticList* slist = (TStaticList*)list;
	StaticListNode* ret = NULL;
	int i = 0;
	int current = 0;
	
	if( ( slist != NULL ) && ( pos < slist->header.data ))
	{
		slist->node[0] = slist->header;
		for( i = 0; (i < pos) && (slist->node[current].next != 0); i++)
		{
			current = slist->node[current].next;
		}
		ret = (StaticListNode*)slist->node[(slist->node[current].next)].data;

	}
	return ret;
}

StaticListNode* StaticList_Delete(StaticList* list, int pos)
{
	TStaticList* slist = (TStaticList*)list;
	StaticListNode* ret = NULL;
	int i;
	int current = 0;

	if( ( slist != NULL) && (pos < slist->header.data) )
	{
		slist->node[0] = slist->header;
		for( i = 0; (i < pos) && (slist->node[current].next != 0); i++)
		{
			current = slist->node[current].next;
		}

		ret = (StaticListNode*)slist->node[(slist->node[current].next)].data;
		slist->node[current].next = slist->node[(slist->node[current].next)].next;

		slist->node[0].data--;
		slist->header = slist->node[0];

	}
	return ret;	
}
