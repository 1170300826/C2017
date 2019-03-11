#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
typedef struct Node{
    char Date;
    struct Node *Next;
} LinkStack;
LinkStack *CreateStack()
{
    LinkStack *S;
    S = (LinkStack*)malloc(sizeof(struct Node));
    S->Next = NULL;
    return S;
}
int IsEmpty(LinkStack *S)
{
    return(S->Next == NULL);
}
void Push(LinkStack *S, char item)
{
    LinkStack *TmpCell;
    TmpCell = (LinkStack*)malloc(sizeof(struct Node));
    TmpCell->Date = item;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}
char Pop(LinkStack *S)
{
    LinkStack *FirstCell;
    char TopElem;
    if(IsEmpty(S)){
        printf("Stack is empty\n");
        return NULL;
    }
    else{
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        TopElem = FirstCell->Date;
        free(FirstCell);
        return TopElem;
    }
}
#endif // STACK_H_INCLUDED

