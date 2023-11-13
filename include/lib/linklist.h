#ifndef __LINKLIST__H__
#define __LINKLIST__H__
#include <stdlib.h>
#include <assert.h>

#define ASSERT(val) assert(val != NULL);
#define MALLOC(type, val)                     \
    type *val = (type *)malloc(sizeof(type)); \
    ASSERT(val)

typedef int data_t;
typedef struct __Node {
    data_t data;
} node;

typedef struct __NodeList {
    node *val;
    struct __NodeList *prev;
    struct __NodeList *next;

} linknode;

typedef struct __LinkList {
    linknode *head;
    linknode *tail;
} linklist;

linklist *linklist_create(void);
void linklist_pushback(linklist *list, node n);
linklist *linklist_destory(linklist *list);

#endif //!__LINKLIST__H__