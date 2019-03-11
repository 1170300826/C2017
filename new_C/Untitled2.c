#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define N1 50
typedef struct node {
	char cacu;
	struct node *next;
}Node; 
Node* FindHead(Node *N)//����ջ��
{
    Node* temp = N->next;
    return temp;
}
int Empty(Node *N)//ջ����N->next 
{
	if(N->next == NULL)//ջ��������ջ�� 
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
void Pop(Node *N)//����ջ�� 
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
void Push(char p,Node *N)//ѹ��ջ�� 
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
		else if(a == '.')//����Ƕ��ţ��򷵻�2 
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
void MitoBehind(Node *N,char *middle)//��׺ת��׺ 
{
	int i=0;
	Node *Ntop;
	printf("��׺���ʽ�� "); 
	while(middle[i] != '\0')
	{
    	if(middle[i] == '(')//������ 
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
    	else if(!Isoperater(middle[i]))//���� 
    	{
    		//Push(middle[i],N);//������ȼ���ջ
			printf("%c",middle[i]);
			i++;
			while(middle[i] == ' ')
			{
				printf("%c",middle[i]);
				i++;
			}
		}
		else if(Isoperater(middle[i]))//����
		{
			Ntop = Top(N);
			if(Empty(N))
			{
				Push(middle[i],N);
			}
			else if(Ishigh(middle[i],Ntop->cacu)==2)//������ȼ���� 
			{
				Push(middle[i],N);  
		    }
			else //ֱ��ջ�����ȼ���� 
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
  	printf("please input ��׺���ʽ:");
  	gets(middle);
  	MitoBehind(N,middle);
	printf("\n you continue:");
  }	//printf("��׺���ʽ�ǣ�%s\n",middle);
  free(N);
}  

