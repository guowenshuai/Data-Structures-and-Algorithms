#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef void LinkList;
typedef struct _struct_ListNode LinkListNode;
struct _struct_ListNode
{
	LinkListNode* next;
};

LinkList* LinkList_Create();

void LinkList_Destroy(LinkList* list);

void LinkList_Clear(LinkList* list);

int LinkList_Length(LinkList* list);

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

LinkListNode* LinkList_Get(LinkList* list, int pos);

LinkListNode* LinkList_Delet(LinkList* list, int pos);

#endif
