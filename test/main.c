#include <stdio.h>
#include "../include/pch.h"
#include "linklist.h"

#define TEST(num) node n##num = {num}; 
#define T 6
void print(linklist *l)
{
    linknode *p = l->head->next;
    while (p->next != NULL) {
        printf("%d ", p->val.data);
        p = p->next;
    }
}
int main()
{
    linklist *l = linklist_create();

    TEST(1)
    TEST(2)
    TEST(3)
    TEST(4)
    TEST(5)
    TEST(6)
    TEST(7)
    TEST(8)
    TEST(9)
    TEST(100)
    linklist_pushback(l, n1);
    linklist_pushback(l, n2);
    linklist_pushback(l, n3);
    linklist_pushback(l, n4);
    linklist_pushback(l, n5);
    linklist_pushback(l, n6);
    linklist_pushback(l, n7);
    linklist_pushback(l, n8);
    linklist_pushback(l, n9);
    linklist_delete(l, 5);
    // linklist_insert(l, n100, T);

    print(l);
    l = linklist_destory(l);

    return 0;
}