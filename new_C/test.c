#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#define N 50
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10
typedef struct stack{
    int data[MAXSIZE];
    int top;//栈顶指针
}pstack;
//1. 初始化
void initial(Stack *S,int n){
    if(n>MAXSIZE || n<1){
        printf("输入长度有误！\n");
    }
    int i;
    for(i=0;i<n;i++){
        S->data[i]=0;
    }
    S->top=n-1;
}
//3. 压栈操作
void push(Stack *S,int e){
	int a,b;
	a = MAXSIZE-1;
    /*if( a == S->top)
	{
        printf("栈已满\n");
    }*/
    //栈顶指向的元素有值
    b = S->top;
    S->top = b+1;
    S->data[S->top]=e;
}
//4. 出栈
void pop(Stack *S,int *e){
//将栈顶元素出栈，传给e
    int a = S->top;
    if(-1==a)
	{ 
        printf("栈为空！\n");
    }
    *e=S->data[S->top];
    S->top = a -1;
}
int IsOperator(char ch)//判断ch是否为操作符 
{ 
    switch (ch) 
    { 
    case '+':return 1; break; 
    case '-':return 1; break; 
    case '*':return 1; break; 
    case '/':return 1; break; 
    case ' ':return 1; break; 
    //case '@':return 1; break; 
    } 
    return false; 
} 
//该函数实现的功能有，未发现有运算符时，压数字入数字站，跳过空格，存在运算符时提出俩数运算 
int PostInStack(const char *string, pStack operand)//返回计算结果 
{ 
    int i=0;// i as xiabiao 
    while(string[i]!='\0') 
    { 
        /*实现多位数的计算存储和识别运算符与非运算符技术*/
        if(!IsOperator(string[i])) //若不是运算符，那么将char串数字转化为int的一个数
        { 
                int sum=string[i]-'0'; 
                ++i;// pointer move ahead 
                while(!IsOperator(string[i]))//处理多位数 
                { 
	                sum=sum*10+string[i]-'0'; 
	                ++i; 
                } 
                push(operand,sum); //转化完毕就压入数字栈
                while(string[i]==' ') //跳过题中随机的空格
                { 
                    ++i; 
                }//remove space 
        } 
        else//是操作符号就进行运算
        { 
           int a,b,res; 
           pop(operand,&a); 
           pop(operand,&b); 
           switch(string[i]) 
           //本来这里想封装一下switch做个函数，无奈gcc编译错误，原因我也不懂
           { 
                 case'+':res=a+b;break; 
                 case'/':res=b/a;break; 
                 case'-':res=b-a;break; 
                 case'*':res=a*b;break; 
           } 
           push(operand,res); //运算完毕后存入栈顶
           i++; 
           while(string[i]==' ') 
           { 
               ++i; 
           } 
        } 
    } 
    int result=GetTop(operand,&result); //扫完后结果在栈顶
    return result; 
} 
int Input(char **string) //因为OJ上静态变量内存分配无法满足题意， 只得手动分配
{ 
    *string = (char *)malloc(sizeof(char)* 1000); 
    gets(*string); 
    return true; 
} 
int main(void) 
{ 
    Stack Operand, Operator; 
    int result; 
    initial(&Operand);//初始化操作数栈 
    char *string; 
    Input(&string); 
    /*printf("%s\n", string); 
    system("pause");*/
    result = PostInStack(string, &Operand);//后序遍历直接入栈 
    printf("%d\n", result); 
    //system("pause"); 
    return 0; 
} 

