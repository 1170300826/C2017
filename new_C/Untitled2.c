#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define N1 50
typedef struct node {
	char cacu;
	struct node *next;
}Node; 
Node* FindHead(Node *N)//返回栈顶
{
    Node* temp = N->next;
    return temp;
}
int Empty(Node *N)//栈顶是N->next 
{
	if(N->next == NULL)//栈顶不等于栈底 
	{
		return 1;
	}
	else
	    return 0;
}
Node* Top(Node *N)
{
	return N->next;
}
void Pop(Node *N)//弹出栈顶 
{
	Node *stk1;
	//stk = (Node *)malloc(sizeof(Node));
	if(Empty(N) == 1)
	{
		printf("Error!Empty stack\n");
	} 
	else
	{
		stk1 = N->next;
		N->next = stk1->next;
		N->next = NULL;
		free(stk1);
	}
} 
void Push(char p,Node *N)//压入栈顶 
{
	Node *stk= (Node *)malloc(sizeof(Node));
	stk->next = NULL;
	if(!Empty(N))
	{
		stk->cacu = N->next->cacu;
	}
	stk->next = N->next;
	N->next = stk;
	N->next->cacu=p;
}
int Isoperater(char a)
{
	char data[] = "+-*/%";
	int flag = 0;
	int i;
	for(i=0;i<5;i++)
	{
		if(data[i] == a)
		  flag ++;
		else if(a == '.')//如果是逗号，则返回2 
		{
			return 2; 
		}
	}
	return flag; 
} 
void Printop(Node *N)
{
	printf("%c",N->next->cacu);
}
int Ishigh(char a,char b)
{
	char ch1[] = "+-";
	char ch2[] = "*%/";
	int a1=0,b1=0,i,j,k;
	for(i=0;i<strlen(ch1);i++)
	{
		if(a == ch1[i])
		{
			a1 = 1;
		}
		if(b == ch1[i])
		{
			b1 = 1;
		}
	}
	for(i=0;i<strlen(ch2);i++)
	{
		if(a == ch2[i])
		{
			a1 = 2;
		}
		if( b == ch2[i])
		{
			b1 = 2;
		}
	}
	if(a1>b1)
	{
	  return 2;
	} 
	else if(a1 == b1)
	{
		return 1;
	}
	else 
	  return 0;	
}
/*double Caculate(Node N)
{
	
} */
void MitoBehind(Node *N,char *middle)//中缀转后缀 
{
	int i=0;
	Node *Ntop;
	printf("后缀表达式： "); 
	while(middle[i] != '\0')
	{
    	if(middle[i] == '(')//左括号 
    	{
    		Push(middle[i],N);
    		i++;
    		while(middle[i] == ' ')
			{
				printf("%c",middle[i]);
				i++;
			}
		}
		else if(middle[i] == ')')
		{
			do
			{
				Pop(N);
			}while(Top(N)->cacu != '(');
			Pop(N);
		}
    	else if(!Isoperater(middle[i]))//数字 
    	{
    		//Push(middle[i],N);//最高优先级入栈
			printf("%c",middle[i]);
			i++;
			while(middle[i] == ' ')
			{
				printf("%c",middle[i]);
				i++;
			}
		}
		else if(Isoperater(middle[i]))//符号
		{
			Ntop = Top(N);
			if(Empty(N))
			{
				Push(middle[i],N);
			}
			else if(Ishigh(middle[i],Ntop->cacu)==2)//如果优先级最高 
			{
				Push(middle[i],N);  
		    }
			else //直到栈顶优先级最高 
			{
					printf("%c",N->next->cacu);
					Pop(N);	
					while(1)
					{
						if(Ishigh(middle[i],Ntop->cacu)==1) 
						{
							printf("%c",N->next->cacu);
						    Pop(N);	
							Push(middle[i],N);
							break;
						}
						if(Ishigh(middle[i],Ntop->cacu)==2)
						{
							break;//?
						}
						printf("%c",N->next->cacu);
						Pop(N);	
					}
					
			}
		    i++;
			while(middle[i] == ' ')
			{
				printf("%c",middle[i]);
				i++;
			}
		}
	}	
	while(N->next != NULL)
	{
		printf("%c",N->next->cacu);
		Pop(N);
	}
}
int main()
{
  char middle[N1];
  //char p='y';
  Node *N;
  N = (Node *)malloc(sizeof(Node));
  N->next =NULL;
  while(1)
  {
  	printf("please input 中缀表达式:");
  	gets(middle);
  	MitoBehind(N,middle);
	printf("\n you continue:");
  }	//printf("后缀表达式是：%s\n",middle);
  free(N);
}  

