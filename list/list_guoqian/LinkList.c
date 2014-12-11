#include <stdio.h>
#include <malloc.h>
#include "LinkList.h"

typedef struct LinkListhead
{
	LinkListNode header;
	int length;
} Listhead;

LinkList* LinkList_Create()
{
	Listhead* ret = (Listhead*)malloc(sizeof(Listhead));

	if ( ret != NULL )
	{
		ret->length = 0;
		ret->header.next = NULL;
	}

	return ret;
}

void LinkList_Destroy(LinkList* list)
{
	free(list);
}

void LinkList_Clear(LinkList* list)
{
	
	Listhead* hlist = (Listhead*)list;
	
	if( hlist != NULL )
	{
		hlist->length = 0;
		hlist->header.next = NULL;
	}
}

int LinkList_Length(LinkList* list)
{
	Listhead* hlist = (Listhead*)list;
	int ret = -1;

	if( hlist != NULL)
	{
		ret = hlist->length;
	}
	
	return ret;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	Listhead* hlist = (Listhead*)list;
	int ret = (hlist != NULL) && (pos >= 0) && (node != NULL);
	int i;

	if( ret )
	{
		LinkListNode* current = (LinkListNode*)hlist;

		for(i = 0; (i < pos) && (current->next != NULL); i++)
		{
			current = current->next;	
		}

		node->next = current->next;
		current->next = node;

		hlist->length++;
	}

	return ret;
}

LinkListNode* LinkList_Get(LinkList* list, int pos)
{
	Listhead* hlist = (Listhead*)list;
	LinkListNode* ret = NULL;
	int i;

	if( (pos < hlist->length) && (hlist != NULL) && (pos >= 0) )
	{
		LinkListNode* current = (LinkListNode*)hlist;

		for(i = 0; (i < pos) && (current->next != NULL); i++)
		{
			current = current->next;
		}

		ret = current->next;
	}

	return ret;
}

LinkListNode* LinkList_Delet(LinkList* list, int pos)
{
	Listhead* hlist = (Listhead*)list;
	LinkListNode* ret = NULL;
	int i; 

	if( (pos < hlist->length) && (hlist != NULL) && (pos >= 0))
	{
		LinkListNode* current = (LinkListNode*)hlist;

		for(i = 0; (i < pos) && (current->next != NULL); i++)
		{
			current = current->next;
		}
		
		ret = current->next;
		current->next = ret->next;
	}

	hlist->length--;
	return ret;
}
