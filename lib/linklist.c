#include "linklist.h"

linklist *linklist_create(void) 
{
    MALLOC(linklist, list)
    list->head->prev = NULL;
    list->head->val = NULL;
    list->tail->next = NULL;
    list->tail->val = NULL;
    list->head->next = list->tail;
    list->tail->prev = list->head;
    return list;
}

void linklist_pushback(linklist *list, node n)
{
    ASSERT(list)
    MALLOC(linknode, L)
    *L->val = n;
    linknode *p = list->tail->prev;
    p->next = L;
    list->tail->prev = L;
    
}