int Insert(LinkList& first,int i,DataType x)
{
    int j,k=1;
    if(i==1||!first)
    {
        LinkNode *newNode = new LinkNode;
        if(!newNode)
        {
            printf("Error!\n");
            exit(1);
        }
        newNode->link = first;
        first = newNode;
        newNode->data = x;
    }
    else
        {
            LinkNode *p = first;
            while(p!=NULL&&k<i-1)
            {
                p=p->link;
                k++;
            }
            if(p==NULL&& first)
            {
                printf("ÎÞÐ§£¡\n");
               return 0;
            }
            else{newNode->link=p->link;
            p->link = newNode;
            newNode->data = x;}

        }
}
int Remove(LinkList &first,int i;DataType &x)
{
    int k=1;
    LinkNode *q;
    if(!first || i==1)
    {
        q= first;
        first = first->link;
        x = q->data;
        delete q;
    }
    else
    {
        LinkNOde *p = first;

        while(p!=NULL&&k<i-1)
        {
            p = p->link;
            k++;
        }
        if(p == NULL|| p->link == NULL)
        {
            printf("无效插入\n");
            return 0;
        }
        else
        {
            q=p->link;
        p->link = q->link;
        x=q->data;
        delete q;
        }
    }
    return 1;
}
