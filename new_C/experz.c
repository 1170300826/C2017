#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50 
#define N1 50 
//栈帧1，用于储存中缀表达式的字符 
typedef struct node{//栈顶指针
    char DATA[10];
    int TOP;
}Node;
//栈帧2，用于储存表达式的运算结果 
typedef struct stack{//栈顶指针
    double data[N1];
    int top;
}stack;
//压栈操作
void push1(stack *M,double e)
{
	int b;  
    b = M->top;
    M->top = b+1;
    M->data[M->top]=e;
}
//出栈
void pop1(stack *M,double *e)
{
    int a = M->top;
    *e=M->data[M->top];
    M->top = a - 1;
}
int Ishigh(char a,char b)//比较两个运算符之间的优先级 
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
//判断是否为操作符 
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
//计算后缀表达式的值 
void Caculate(stack *M,char *final)
{
	int i=0,j=0,k;
	double p,q,r1,m1,m2,m3;
	double sum;
	while(final[i] != '\0')//字符数组为空时停止 
	{
		if(!Isoperater(final[i]))//不是操作符 
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
						while((final[i] >='0'&&final[i] <='9'))//负数小数点后的数字 
						{
							sum = sum*10+'0'-final[i];
							i++;
							j++;//小数点后有j位数字 
						}
						for(k=0;k<j;k++)
						{
							sum=sum/10;
						}
						j = 0;
					}
					else//不是小数 
					{
						while((final[i] >='0'&&final[i] <='9'))//小数点后的数字 
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
						while((final[i] >='0'&&final[i] <='9'))//小数点后的数字 
						{
							sum = sum*10+final[i] - '0';
							i++;
							j++;//小数点后有j位数字 
						}
						for(k=0;k<j;k++)
						{
							sum=sum/10;
						}
						j = 0;
					}
					else//不是小数 
					{
						while((final[i] >='0'&&final[i] <='9'))//小数点后的数字 
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
			else if(final[i] == '%') //不考虑小数求余数 
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
	printf("后缀表达式的值是:%.2lf\n",M->data[M->top]);//返回栈顶元素 
} 
//压栈操作
int push(Node *S,char e){
    if(9==S->TOP){
        printf("栈已满\n");
        return -1;
    }
    ++(S->TOP);
    S->DATA[S->TOP]=e;
    return 1;
}
//弹栈操作 
int pop(Node *S,char *e){
    if(-1== S->TOP)
	{
        printf("栈为空！\n");
        return -1;
    }
    *e=S->DATA[S->TOP];
    --(S->TOP);
    return 1;
}
//中缀表达式mid转后缀表达式final,建一个栈存储符号
void Mtf_function(char *p1,char *mid,char *final)
{
    char e;
    Node *S;
    int i=0;
    S = (Node *)malloc(sizeof(Node)); 
    S->TOP = -1;
    S->DATA[N] = *p1;
    if(*mid == '-')//开头等于负号 
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
        else if(*mid == '(') //如果是左括号，则直接压栈 
    	{
    		push(S,*(mid++));
    		if(*mid == '-')//左括号后的负数 
			{
				*(final++)='$';
				 mid++; 
			} 
    		while(*(mid) == ' ')
			{
				*(final++)=*(mid++);;
			}
		}
		else if(*mid == ')')//如果是右括号时一直弹出栈顶元素，直到遇到左括号时结束
		{
			while(1)
			{
				pop(S,&e);//弹出栈顶 
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
            while(*mid == ' ')//如果等于空格 
			{
				*(final++)=*(mid++);
			}
        }
		else if(Isoperater(*mid))//运算符 
		{
            
            if(S->TOP==-1 )//当符号栈为空或时，直接入栈
			{   
                push(S,*(mid++));
            }
            else if(Ishigh(*mid,S->DATA[S->TOP]) == 2)//如果输入元素优先级最高，高于栈顶元素 
            {
            	push(S,*(mid++));
			}
			else//如果输入元素优先级低于栈顶元素，不断弹出栈顶直到输入元素优先级高于栈顶元素
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
   while(S->TOP!=-1)//将栈中的元素依次出栈
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
		printf("请输入中缀表达式：（请使用英文括号，输入字符间用空格隔开如：( 2 + 3 ) * 1)\n");
        gets(DATA);
        Mtf_function(p1,DATA,final);
        printf("后缀表达式是：");
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
