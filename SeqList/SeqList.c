#include <stdio.h>
#include <malloc.h>
#include "SeqList.h"

typedef unsigned int TSeqListNode;

typedef struct _SeqList
{
		int capacity;//the space of form
		int length;
		TSeqListNode* node;
} TSeqList;

SeqList* SeqList_Create(int capacity)
{
		TSeqList* ret = NULL;
		if (capacity > 0)
		{
				ret = (TSeqList*)malloc(sizeof(TSeqList) + sizeof(TSeqListNode*)*capacity);
		}
		if (NULL != ret)
		{
				ret->capacity = capacity;
				ret->length = 0;
				ret->node = (TSeqListNode*)(ret + 1); //ret is a type TSeqlist*
		}
		return ret;
}

void SeqList_Destory(SeqList* list)
{
		free(list);
}

void SeqList_clear(SeqList* list)
{
		TSeqList* slist = (TSeqList *)list;

		if (NULL != slist)
		{
				slist->length = 0;
		}
}

int SeqList_Length(SeqList* list)
{
		TSeqList* slist = (TSeqList *)list;
		int ret = -1;
		if (NULL != slist)
		{
				ret = slist->length;
		}
		return ret;
}

int SeqList_Capacity(SeqList* list)
{
		TSeqList* slist = (TSeqList *)list;
		int ret = -1;
		if (NULL != slist)
		{
				ret = slist->capacity;
		}
		return ret;
}

int SeqList_Insert(SeqList* list, 
				SeqListNode* node, int pos)
{
		TSeqList* slist = (TSeqList *)list;
		int ret = -1;
		int i = 0;

		ret = ret && (slist != NULL) && (pos >= 0);
		ret = ret && (slist->length + 1 <= slist->capacity);

		if (ret)
		{
				if (pos >= slist->length)
						pos = slist->length;

				for (i=slist->length; i>pos; i--)
				{
						slist->node[i] = slist->node[i-1];
				}//i = pos-1;

				slist->node[pos] = (TSeqListNode)node;
				slist->length++;
		}
		return ret;
}

SeqListNode* SeqList_Get(SeqList* list, int pos)
{
		TSeqList* slist = (TSeqList*)list;
		SeqListNode* ret = NULL;

		if ( (slist != NULL) && (pos >=0) && (pos < slist->length) )
		{
				ret = (SeqListNode*)slist->node[pos];
		}

		return ret;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
		TSeqList* slist = (TSeqList*)list;
		SeqListNode* ret = SeqList_Get(list, pos);
		int i = 0;

		if ( (slist != NULL) && (pos >= 0) && (pos < slist->length) )
		{
				for (i=pos; i<slist->length-1; i++)
				{
						slist->node[i] = slist->node[i+1];
				}
		}
		slist->length--;
		return ret;
}

void SeqList_print(SeqList* list)
{
		TSeqList* slist = (TSeqList*)list;
		SeqListNode* node;
		int i = 0;

		if ( (slist != NULL) && (slist->length > 0))
		{
				for (i=0; i<slist->length; i++)
				{
						node = SeqList_Get(list, i);
						printf("%d\n",*(int*)node);
				}
		}
}
