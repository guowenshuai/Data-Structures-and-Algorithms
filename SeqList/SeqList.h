#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef void SeqList;
typedef void SeqListNode; 
 /* create a order form */
SeqList* SeqList_Create(int capacity); 
 /* destory */
void SeqList_Destory(SeqList* list);

void SeqList_clear(SeqList* list);
 /* get the length(how many elements in the order form) */
int SeqList_Length(SeqList* list);
 /* the max space */
int SeqList_Capacity(SeqList* list);
 /* insert a element */
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);
 /* get a element */
SeqListNode* SeqList_Get(SeqList* list, int pos);
 /* delete a element */
SeqListNode* SeqList_Delete(SeqList* list, int pos);
 /* print the order form */
void SeqList_print(SeqList* list);
#endif 
