void initList(ListLink &first)
{
   first = new LinkNode;
    if(first ==NULL )
    {
        printf("Error!\n");
        exit(0);
    }
    first->link = NULL;
}
void clearList(ListLink &first)
{
    LinkNode *q;
    while(first->link!=NULL)
    {
        q = first->link;
        first->link = q->link;
        delete q;
    }
}
int Length(LinkList &first)
{
    LinkNode *p = first->link;
    int count = 0;
    while(p != NULL)
    {
        p = p->link;
        count++;
    }
    return count;
}
int isEmpty(LinkList &first)
{
    return(first->link == NULL);
}
LinkNode *Search(LinkList &first,DataType x)
{
    LinkNode *p=first->link;
    while(p != NULL&&p->data !=x)
    {
        p = p->link;
    }
    return p;
}
LinkNode *Locate(LinkList &first,int i)
{
    int k=0;
    if(i<0)
    {
        return NULL;
    }
    else
    {
        LinkNode *p=first;
        while(p!= NULL&&k<i)
        {
            p=p->link;
            k++;
        }
        return p;
    }
}
