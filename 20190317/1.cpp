//
// Created by 邓萌达 on 2019-03-21.
//

#include<stdio.h>
//#include<stdlib.h>

typedef int elemtype;

typedef struct node {
    elemtype data;
    struct node *next;
} list, *plist;


plist list_create_front(elemtype *p, int n) {
    int i;
    plist pnode, phead;
    phead = (plist) malloc(sizeof(list));
    phead->next = NULL;
    for (i = n - 1; i >= 0; --i) {
        pnode = (plist) malloc(sizeof(list));
        pnode->data = p[i];
        pnode->next = phead->next;
        phead->next = pnode;
    }
    return phead;
}

plist list_create_back(elemtype *p, int n) {
    int i;
    plist pnode, phead, ptail;
    phead = (plist) malloc(sizeof(list));
    phead->next = NULL;
    ptail = phead;
    for (i = n - 1; i >= 0; --i) {
        pnode = (plist) malloc(sizeof(list));
        pnode->data = p[i];
        pnode->next = NULL;
        ptail->next = pnode;
        ptail = pnode;
    }
    return phead;
}

int length(plist phead) {
    phead = phead->next;
    int len = 0;
    while (phead != NULL) {
        len++;
        phead = phead->next;
    }
    return len;
}

plist get_node(plist p, int inx) {
    int i = 0;
    while (p && (i < inx)) {
        p = p->next;
        i++;
    }
    return p;
}

void remove(plist p, int inx) {
    plist l, q;
    l = get_node(p, inx - 1);
    if (l) {
        q = l->next;
        l->next = q->next;
        if (q)
            free(q);
    }
}

void insert(plist p, int inx, elemtype e) {
    int i = 0;
    plist pnode, q;
    pnode = (plist) malloc(sizeof(list));
    pnode->data = e;
    q = get_node(p, inx);
    pnode->next = q->next;
    q->next = pnode;
    return p;
}

plist merge(plist pa, plist pb) {
    plist ga, gb, ptail;
    ga = pa;
    gb = pb;
    ptail = pa;
    while (ga && gb) {
        if (ga->data < gb->data) {
            ptail->next = ga;
            ptail = ga;
            ga = ga->next;
        } else {
            ptail->next = gb;
            ptail = gb;
            gb = gb->next;
        }
    }
    while (ga) {
        ptail->next = ga;
        ga = ga->next;
    }
    while (gb) {
        tail->next = gb;
        gb = gb->next;
    }
    free(pb);
    return pa;
}

int main() {
    int p[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, q[10] = {12, 5, 3, 9, 11, 32, 61, 80, 14, 20};
    plist p, m;
    int len, i;
    list_create_back(p, 10);
    for (i = 0; i < 10; i++)
        printf("p = %4d\n", p[i]);
    len = length(p);
    printf("len = %d\n", len);

    insert(p, 5, 55);
    for (i = 0; i < 10 + 1; i++)
        printf("p = %4d\n", p[i]);
    remove(p, 6);
    for (i = 0; i < 10; i++)
        printf("p = %4d\n", p[i]);

    m = merge(p, q);
    for (i = 0; i < 10; i++)
        printf("p = %4d\n", m[i]);

    return 0;
}