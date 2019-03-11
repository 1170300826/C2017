#include <stdio.h>

void insertRear(LinkNode *first)
{

    if(first == NULL)
    {
        return;
    }
    printf("%d\n",first->data);
    write(first->link);
}
void Touch(LinkNode *first,LinkNode *& s,DataType endTag)
{
    DataType a;
    scanf("%d",&a);
    if(a == endTag)
    {
        s-link=NULL;
    }

    else
        {
    s=new LinkNode;
    s->data = a;
    insertRear(first,last->link,endTag);
        }

}
