#ifndef __LINKLIST__H__
#define __LINKLIST__H__
#include <stdlib.h>

#define MEMBER_CHECK(val, r) \
    if (val == NULL)         \
        return r;
#define MALLOC(type, val, r)                  \
    type *val = (type *)malloc(sizeof(type)); \
    MEMBER_CHECK(val, r)

typedef int data_t;
typedef struct __Node {
    data_t data;
} node;

typedef struct __NodeList {
    struct __NodeList *prev;
    struct __NodeList *next;
    node val;
} linknode;

typedef struct __LinkList {
    linknode *head;
    linknode *tail;
} linklist;

linknode *_nullptr;

linklist *linklist_create(void);
int linklist_pushback(linklist *list, node n);
linklist *linklist_destory(linklist *list);

#endif //!__LINKLIST__H__