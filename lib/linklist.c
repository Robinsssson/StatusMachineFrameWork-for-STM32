#include "linklist.h"

linklist *linklist_create(void) 
{
    MALLOC(linklist, list, NULL)
    MALLOC(linknode, _head, list)
    MALLOC(linknode, _tail, list)
    list->head = _head;
    list->tail = _tail;
    list->head->prev = NULL;
    list->tail->next = NULL;
    list->head->next = list->tail;
    list->tail->prev = list->head;
    return list;
}

int linklist_pushback(linklist *list, node n)
{
    MEMBER_CHECK(list, -1)
    MALLOC(linknode, L, -1)
    L->val = n;
    linknode *p = list->tail->prev;
    p->next = L;
    list->tail->prev = L;
    L->prev = p;
    L->next = list->tail;
    return 0;
}

linklist* linklist_destory(linklist* list)
{
    linknode *p = list->head;

    return NULL;
}