/* 堆栈练习——中缀表达式转后缀表达式 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 25

typedef struct node{
    char date;
    struct node *next;
} LinkStake;

typedef struct node2{
    float date;
    struct node *next;
} Stake;

typedef struct body{
    char date[MAX];
    int j;
} Body;

LinkStake *CreatStake();//建立空栈
int IsEmpty(LinkStake *s);//判断空栈
void Push(char fuhao, LinkStake *s, Body *p);//压栈
int Judge(bool flag, char c);//判断优先级

LinkStake *CreatStake()
{
    LinkStake *s;
    s=malloc(sizeof(struct node));
    s->next = NULL;
    return s;
}

int IsEmpty(LinkStake *s)
{
    return(s->next == NULL);
}

void Push(char fuhao, LinkStake *s, Body *p)
{
    while(s->next != NULL && Judge(false,fuhao)<Judge(true,s->next->date)){
            LinkStake *t;
            printf("%c", s->next->date);
            p->date[p->j] = s->next->date;
            p->j++;
            t = s->next;
            s->next = t->next;
            free(t);
    }
    if(IsEmpty(s)){
        LinkStake *tmp;
        tmp = malloc(sizeof(struct node));
        tmp->date = fuhao;
        tmp->next = s->next;
        s->next = tmp;
    }
    else if(Judge(false,fuhao)>Judge(true,s->next->date)){
            LinkStake *tmp;
            tmp = malloc(sizeof(struct node));
            tmp->date = fuhao;
            tmp->next = s->next;
            s->next = tmp;
        }
    else if(Judge(false,fuhao) == Judge(true,s->next->date)){
            LinkStake *t;
            t = s->next;
            s->next = t->next;
            free(t);
        }
}

int Judge(bool flag, char c)
{
    if(c == '+' || c == '-')
        if(flag) return 3;
        else return 2;
    else if(c == '*' || c == '/')
        if(flag) return 5;
        else return 4;
    else if(c == '(')
        if(flag) return 1;
        else return 6;
    else if(c == ')')
        if(flag) return 6;
        else return 1;
    else return 0;
}

void PushStake(float c, LinkStake* s)
{
    Stake *tmp;
    tmp = malloc(sizeof(struct node2));
    tmp->date = c;
    tmp->next = s->next;
    s->next = tmp;
}

float PopStake(LinkStake *s)
{
    Stake *t;
    float c;
    t = s->next;
    c = t->date;
    s->next = t->next;
    free(t);
    return c;
}

int main()
{
    int i = 0;
    LinkStake *head;
    Body *p = malloc(sizeof(struct body));
    char s[MAX];
    head = CreatStake();
    p->j = 0;
    char p='y';
	  Stack S,Stop;
	  int i,j,k;
	  S = (Stack)malloc(sizeof(node));
	  S ->next =NULL;
	  while( p == 'y')
	  {
    printf("请输入中缀表达式；\n");
    gets(s);
    printf("转换为后缀表达式: \n");
    while(s[i]){
        if(s[i]>='0' && s[i]<='9'){
            printf("%c", s[i]);
            p->date[p->j] = s[i];
            p->j++;
        }
        
        else 
        {
        	if(s[i]=='.')
        	{
        		printf("%c", s[i]);
			}
			Push(s[i],head,p);
		}
        i++;
    }
    while(head->next != NULL){
        printf("%c", head->next->date);
        p->date[p->j++] = head->next->date;
        p->j++;
        LinkStake *t;
        t = head->next;
        head->next = t->next;
        free(t);
    }
    printf("\n");
    printf("计算结果为：\n");

    Stake *stake;
    float sum = 0.0, a, b;
    stake = (Stake*)malloc(sizeof(struct node2));
    stake->next = NULL;
    for(i = 0; i < p->j; i++){
        if(p->date[i]>='0' && p->date[i]<='9')
            PushStake((float)(p->date[i]-'0'), stake);
        else if(p->date[i]=='+'){
            b = PopStake(stake);
            a = PopStake(stake);
            sum = a+b;
            PushStake(sum, stake);
        }
         else if(p->date[i]=='-'){
            b = PopStake(stake);
            a = PopStake(stake);
            sum = a-b;
            PushStake(sum, stake);
        }
         else if(p->date[i]=='*'){
            b = PopStake(stake);
            a = PopStake(stake);
            sum = a*b;
            PushStake(sum, stake);
        }
         else if(p->date[i]=='/'){
            b = PopStake(stake);
            a = PopStake(stake);
            sum = a/b;
            PushStake(sum, stake);
        }
    }
    printf("%.2f", sum);
    return 0;
}



