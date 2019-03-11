#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define N 50
typedef struct node {
	char cacu[N];
	int top;
}Stack; 
void Pop(Stack *S)//����ջ�� 
{
	int a = S->top;
    if(-1== a)
	{ 
        printf("ջΪ�գ�\n");
    }
	S->top = a-1;
} 
void Push(char p,Stack *S)//ѹ��ջ�� 
{
	if( N == S->top)
	{
        printf("ջ����\n");
    }
    //ջ��ָ���Ԫ����ֵ
	S->top++; 
	S->cacu[S->top] = p;
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
/*double Caculate(Stack S)
{
	
} */
void MitoBehind(Stack *S,char *middle)//��׺ת��׺ 
{
	int i=0;
	Stack *Stop;
	printf("��׺���ʽ�� "); 
	while(middle[i] != '\0')
	{
    	if(middle[i] == '(')//������ 
    	{
    		Push(middle[i],S);
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
				Pop(S);
			}while(S->top->cacu != '(');
			Pop(S);
		}
    	else if(!Isoperater(middle[i]))//���� 
    	{
    		//Push(middle[i],S);//������ȼ���ջ
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
			Stop = Top(S);
			if(Empty(S))
			{
				Push(middle[i],S);
			}
			else if(Ishigh(middle[i],S->cacu[S->top])==2)//������ȼ���� 
			{
				Push(middle[i],S);  
		    }
			else //ֱ��ջ�����ȼ���� 
			{
					printf("%c",S->cacu[S->top]);
					Pop(S);	
					while(1)
					{
						if(Ishigh(middle[i],S->cacu[S->top])==1) 
						{
							printf("%c",S->cacu[S->top]);
						    Pop(S);	
							Push(middle[i],S);
							break;
						}
						if(Ishigh(middle[i],S->cacu[S->top])==2)
						{
							break;
						}
						printf("%c",S->cacu[S->top]);
						Pop(S);	
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
	while(S->top != N)
	{
		printf("%c",S->cacu[S->top]);
		Pop(S);
	}
}
int main()
{
  char middle[N];
  //char p='y';
  Stack *S;
  S = (Stack *)malloc(sizeof(Stack));
  S->top =-1;
  while(1)
  {
  	printf("please input ��׺���ʽ:");
  	gets(middle);
  	MitoBehind(S,middle);
	printf("\n you continue:");
  }	//printf("��׺���ʽ�ǣ�%s\n",middle);
  free(S);
}  

