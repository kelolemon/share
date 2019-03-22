void InitLinkList(pList* pplist)//初始化
{
    assert(pplist);
    *pplist = NULL;
}

pNode BuyNode(DataType d)//创建一个节点
{
    pNode newnode = (pNode)malloc(sizeof(Node));
    if (newnode == NULL)
    {
        printf("jjjjjj");
        perror("buy node::error");
        return NULL;
    }
    newnode->data = d;
    newnode->next = NULL;
    return newnode;
}

void PushBack(pList* pplist, DataType d)//后插
{
    assert(pplist != NULL);
    if (*pplist == NULL)
    {
        pNode newnode = BuyNode(d);
        if (newnode == NULL)
            return;
        *pplist = newnode;
    }
    else
    {
        pNode cur = *pplist;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = BuyNode(d);
    }
}

void PrintLinkList(pList plist)//打印单链表
{
    while (plist != NULL)
    {
        printf("%d->", plist->data);
        plist = plist->next;
    }
    printf("NULL\n");
}

void PopBack(pList* pplist)//后删
{
    assert(pplist);
    if (*pplist == NULL)
    {
        printf("单链表为空\n");
        return;
    }
    pNode p = *pplist;
    pNode cur = NULL;
    while (p->next)
    {
        cur = p;
        p = p->next;
    }
    if (cur == NULL)
    {
        free(p);
        *pplist = NULL;
    }
    else
    {
        cur->next = NULL;
        free(p);
    }
}

void DestroyLinkList(pList* pplist)//销毁
{
    assert(pplist);
    List *cur = *pplist;
    List *p = NULL;
    while (cur != NULL)
    {
        p = cur;
        cur = cur->next;
        free(p);
        p = NULL;
    }
    *pplist = NULL;
}

void PushFront(pList* pplist, DataType d)//头插
{
    assert(pplist);
    List* pNewNode = BuyNode(d);
    pNewNode->next = *pplist;
    *pplist = pNewNode;
    
}

void PopFront(pList* pplist)//头删
{
    List *pDel = NULL;
    assert(pplist);
    if (*pplist == NULL)
    {
        printf("单链表为空\n");
        return;
    }
    pDel = *pplist;
    *pplist = (*pplist)->next;
    free(pDel);
    
}

pNode Find(pList plist, DataType d)//找指定位置节点
{
    if (plist == NULL)
    {
        printf("单链表为空\n");
        return;
    }
    List *pCur = plist;
    while (pCur)
    {
        if (pCur->data == d)
            return pCur;
        else
            pCur = pCur->next;
    }
    return NULL;
}

void Insert(pList* pplist, pNode pos, DataType d)//指定位置之前插入
{
    assert(pplist);
    List *pCur = *pplist;
    if (pos == NULL)
    {
        printf("没有这个节点\n");
        return;
    }
    while (pCur->next != pos)
    {
        pCur = pCur->next;
    }
    pCur->next = BuyNode(d);
    pCur->next->next = pos;
    
}

void Erase(pList* pplist, pNode pos)//指定位置删除
{
    assert(pplist);
    if (pos == NULL)
    {
        printf("没有这个节点\n");
        return;
    }
    List *pCur = *pplist;
    while (pCur->next != pos)
    {
        pCur = pCur->next;
    }
    pCur->next = pos->next;
    free(pos);
    
}

void EraseNotTailNode(pNode pos)
{
    List *pDel = NULL;
    if (pos == NULL || pos->next == NULL)
        return;
    pDel = pos->next;
    pos->data = pDel->data;
    pos->next = pDel->next;
    free(pDel);
}

int GetListLength(pList plist)
{
    int num = 0;
    List *pCur = plist;
    while (pCur)
    {
        pCur = pCur->next;
        num++;
    }
    return num;
    
}

void PrintTailToHead(pList plist)//逆序打印单项链表
{
    if (plist != NULL)
    {
        PrintTailToHead(plist->next);
        printf("->%d", plist->data);
    }
    else
    {
        printf("NULL");
    }
}
