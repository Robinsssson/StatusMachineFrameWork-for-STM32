#include <stdio.h>
#include "../include/pch.h"
#include "linklist.h"

void print(linklist* l)
{
    linknode* p = l->head->next;
    while(p->next != NULL)
    {
        printf("%d ", p->val.data);
        p = p->next;
    }
}
int main()
{
    linklist* l = linklist_create();
    node n1 = {1};
    node n2 = {2};
    node n3 = {3};
    node n4 = {4};
    linklist_pushback(l, n1);
    linklist_pushback(l, n2);
    linklist_pushback(l, n3);
    linklist_pushback(l, n4);
    print(l);
    return 0;
}