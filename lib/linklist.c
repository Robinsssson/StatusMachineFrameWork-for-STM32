#include "linklist.h"

linklist *linklist_create(void)
{
    MALLOC(linklist, list, NULL)
    MALLOC(linknode, _head, list)
    MALLOC(linknode, _tail, list)
    list->head       = _head;
    list->tail       = _tail;
    list->head->prev = NULL;
    list->tail->next = NULL;
    list->head->next = list->tail;
    list->tail->prev = list->head;
    list->len        = 0;
    return list;
}

int linklist_pushback(linklist *list, node n)
{
    MEMBER_CHECK(list, -1)
    MALLOC(linknode, L, -1)
    L->val           = n;
    linknode *p      = list->tail->prev; // tail->prev -- tail
    p->next          = L;                // tail->prev->next = L
    list->tail->prev = L;                //
    L->prev          = p;
    L->next          = list->tail;
    list->len++;
    return 0;
}

int linklist_pushfront(linklist *list, node n)
{
    MEMBER_CHECK(list, -1)
    MALLOC(linknode, L, -1)
    L->val           = n;
    linknode *p      = list->head->next;
    p->prev          = L;
    list->head->next = L;
    L->next          = p;
    L->prev          = list->head;
    list->len++;
    return 0;
}

int linklist_insert(linklist *list, node n, int pos)
{
    if (pos >= list->len)
        return linklist_pushback(list, n);
    if (pos < 0)
        return linklist_pushfront(list, n);
    MEMBER_CHECK(list, -1)
    MALLOC(linknode, L, -1)
    L->val = n;
    linknode *p, *q;
    if (pos <= list->len / 2) // 0 1[]2 3 4 5  insert(n, 2)  2 < 3
    {
        p = list->head;
        for (int i = 0; i < pos; i++) {
            p = p->next;
        }
        q       = p->next;
        q->prev = L;
        p->next = L;
        L->next = q;
        L->prev = p;
    }
    else { // 0 1 2 3 []4 5 len = 6 pos = 4
        p = list->tail;
        for (int i = 0; i < (list->len - pos); i++) {
            p = p->prev;
        }
        q       = p->prev;
        q->next = L;
        p->prev = L;
        L->next = p;
        L->prev = q;
    }
    list->len++;
    return 0;
}

int linklist_delete(linklist *list, int pos)
{
    if(pos < 0 || pos >= list->len)
        return -2;
    MEMBER_CHECK(list, -1);
    linknode *p, *m, *n;
    if (pos <= list->len / 2) {
        p = list->head->next;
        for (int i = 0; i < pos; i++) {
            p = p->next;
        }
    }
    else {
        p = list->tail;
        for (int i = 0; i < (list->len - pos); i++) {
            p = p->prev;
        }
    }
    m = p->prev;
    n = p->next;
    m->next = n;
    n->prev = m;
    free(p);
    list->len --;
    return 0;
}

linklist *linklist_destory(linklist *list)
{
    MEMBER_CHECK(list, list)
    linknode *p, *q;
    p = list->head;
    while (p != list->tail) {
        q = p->next;
        free(p);
        p = q;
    }
    free(p);
    free(list);
    return NULL;
}