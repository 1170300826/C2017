#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50 
#define N1 50 
//ջ֡1�����ڴ�����׺���ʽ���ַ� 
typedef struct node{//ջ��ָ��
    char DATA[10];
    int TOP;
}Node;
//ջ֡2�����ڴ�����ʽ�������� 
typedef struct stack{//ջ��ָ��
    double data[N1];
    int top;
}stack;
//ѹջ����
void push1(stack *M,double e)
{
	int b;  
    b = M->top;
    M->top = b+1;
    M->data[M->top]=e;
}
//��ջ
void pop1(stack *M,double *e)
{
    int a = M->top;
    *e=M->data[M->top];
    M->top = a - 1;
}
int Ishigh(char a,char b)//�Ƚ����������֮������ȼ� 
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
//�ж��Ƿ�Ϊ������ 
int Isoperater(char a)
{
	char DATA1[] = "+-*/%";
	int flag = 0;
	int i;
	for(i=0;i<5;i++)
	{
		if(DATA1[i] == a)
		  flag ++;
	}
	return flag; 
} 
//�����׺���ʽ��ֵ 
void Caculate(stack *M,char *final)
{
	int i=0,j=0,k;
	double p,q,r1,m1,m2,m3;
	double sum;
	while(final[i] != '\0')//�ַ�����Ϊ��ʱֹͣ 
	{
		if(!Isoperater(final[i]))//���ǲ����� 
		{ 
		    if(final[i] == '$') 
		    {
		    	i++;
				sum = '0'-final[i];
				i++;
				while((final[i] >='0'&&final[i] <='9') || (final[i] == '.'))
				{
					if(final[i] == '.')
					{
						i++;
						while((final[i] >='0'&&final[i] <='9'))//����С���������� 
						{
							sum = sum*10+'0'-final[i];
							i++;
							j++;//С�������jλ���� 
						}
						for(k=0;k<j;k++)
						{
							sum=sum/10;
						}
						j = 0;
					}
					else//����С�� 
					{
						while((final[i] >='0'&&final[i] <='9'))//С���������� 
						{
							sum = sum*10+'0'-final[i];
							i++;
						}
					}
				}
			}
			else{
				sum = final[i] - '0';
					i++;
				while((final[i] >='0'&&final[i] <='9') || (final[i] == '.'))
				{
					if(final[i] == '.')
					{
						i++;
						while((final[i] >='0'&&final[i] <='9'))//С���������� 
						{
							sum = sum*10+final[i] - '0';
							i++;
							j++;//С�������jλ���� 
						}
						for(k=0;k<j;k++)
						{
							sum=sum/10;
						}
						j = 0;
					}
					else//����С�� 
					{
						while((final[i] >='0'&&final[i] <='9'))//С���������� 
						{
							sum = sum*10+final[i] - '0';
							i++;
						}
					}
				}
			}
			push1(M,sum);
			while(final[i] == ' ')
			{
				i++;
			}
		}
		else 
		{
			pop1(M,&p);
			pop1(M,&q);
			m1=q;
			m2=p;
			if(final[i] == '+') 
			{
				r1 = m1+m2;
				push1(M,r1);
				i++;
			}
			else if(final[i] == '-') 
			{
				r1 = m1-m2;
				push1(M,r1);
				i++;
			}
			else if(final[i] == '*') 
			{
				r1 = m1*m2;
				push1(M,r1);
				i++;
			}
			else if(final[i] == '/') 
			{
				r1 = m1/m2;
				push1(M,r1);
				i++;
			}
			else if(final[i] == '%') //������С�������� 
			{
				r1 = (int)m1%(int)m2;
				push1(M,r1);
				i++;
			}
			while(final[i] == ' ')
			{
				i++;
			}
		}
	}
	printf("��׺���ʽ��ֵ��:%.2lf\n",M->data[M->top]);//����ջ��Ԫ�� 
} 
//ѹջ����
int push(Node *S,char e){
    if(9==S->TOP){
        printf("ջ����\n");
        return -1;
    }
    ++(S->TOP);
    S->DATA[S->TOP]=e;
    return 1;
}
//��ջ���� 
int pop(Node *S,char *e){
    if(-1== S->TOP)
	{
        printf("ջΪ�գ�\n");
        return -1;
    }
    *e=S->DATA[S->TOP];
    --(S->TOP);
    return 1;
}
//��׺���ʽmidת��׺���ʽfinal,��һ��ջ�洢����
void Mtf_function(char *p1,char *mid,char *final)
{
    char e;
    Node *S;
    int i=0;
    S = (Node *)malloc(sizeof(Node)); 
    S->TOP = -1;
    S->DATA[N] = *p1;
    if(*mid == '-')//��ͷ���ڸ��� 
    {
    	*(final++)='$';
    	mid++; 
	}
    while(*mid != '\0')
	{
		if(*(mid) == ' ')  
        {
        	while(*(mid) == ' ')
			{
				*(final++)=*(mid++);
			}
		}
        else if(*mid == '(') //����������ţ���ֱ��ѹջ 
    	{
    		push(S,*(mid++));
    		if(*mid == '-')//�����ź�ĸ��� 
			{
				*(final++)='$';
				 mid++; 
			} 
    		while(*(mid) == ' ')
			{
				*(final++)=*(mid++);;
			}
		}
		else if(*mid == ')')//�����������ʱһֱ����ջ��Ԫ�أ�ֱ������������ʱ����
		{
			while(1)
			{
				pop(S,&e);//����ջ�� 
				if(e == '(')
				{
					break;
				}
                *(final++)=e;
			}
            mid++;
        }
        else if(!Isoperater(*mid))
		{
			e= *mid;
			*final = e;
            mid++;
            final++;
            while(*mid == ' ')//������ڿո� 
			{
				*(final++)=*(mid++);
			}
        }
		else if(Isoperater(*mid))//����� 
		{
            
            if(S->TOP==-1 )//������ջΪ�ջ�ʱ��ֱ����ջ
			{   
                push(S,*(mid++));
            }
            else if(Ishigh(*mid,S->DATA[S->TOP]) == 2)//�������Ԫ�����ȼ���ߣ�����ջ��Ԫ�� 
            {
            	push(S,*(mid++));
			}
			else//�������Ԫ�����ȼ�����ջ��Ԫ�أ����ϵ���ջ��ֱ������Ԫ�����ȼ�����ջ��Ԫ��
			{
			    pop(S,&e);
                *(final++)=e;
				while(1)
				{
					if(Ishigh(*mid,S->DATA[S->TOP])==1) 
					{
						pop(S,&e);
                        *(final++)=e;
						push(S,*(mid++));
						break;
					}
					if(Ishigh(*mid,S->DATA[S->TOP])==2)
					{
						push(S,*(mid++));
						break;
					}
					pop(S,&e);
                    *(final++)=e;
				}
			}
   }
   } 
   while(S->TOP!=-1)//��ջ�е�Ԫ�����γ�ջ
	{
        pop(S,&e);
        *(final++)=e;
    }
    *final='\0';
}
int main()
{
    char DATA[N];
    char final[N]="",p1[N]="";
    stack *M;
    int i;
	M = (stack *)malloc(sizeof(stack)); 
	M->top = -1;
    while(1)
	{
		printf("��������׺���ʽ������ʹ��Ӣ�����ţ������ַ����ÿո�����磺( 2 + 3 ) * 1)\n");
        gets(DATA);
        Mtf_function(p1,DATA,final);
        printf("��׺���ʽ�ǣ�");
	    while(final[i] != '\0')
	    {
	    	if(final[i] == '$')
	    	{
	    		printf("%c",'-');;
			}
			else{
				printf("%c",final[i]);
			}
			i++;
		} 
		printf("\n");
		Caculate(M,final);
		i=0;
	} 
    return 0;
}
