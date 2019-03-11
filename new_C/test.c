#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#define N 50
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10
typedef struct stack{
    int data[MAXSIZE];
    int top;//ջ��ָ��
}pstack;
//1. ��ʼ��
void initial(Stack *S,int n){
    if(n>MAXSIZE || n<1){
        printf("���볤������\n");
    }
    int i;
    for(i=0;i<n;i++){
        S->data[i]=0;
    }
    S->top=n-1;
}
//3. ѹջ����
void push(Stack *S,int e){
	int a,b;
	a = MAXSIZE-1;
    /*if( a == S->top)
	{
        printf("ջ����\n");
    }*/
    //ջ��ָ���Ԫ����ֵ
    b = S->top;
    S->top = b+1;
    S->data[S->top]=e;
}
//4. ��ջ
void pop(Stack *S,int *e){
//��ջ��Ԫ�س�ջ������e
    int a = S->top;
    if(-1==a)
	{ 
        printf("ջΪ�գ�\n");
    }
    *e=S->data[S->top];
    S->top = a -1;
}
int IsOperator(char ch)//�ж�ch�Ƿ�Ϊ������ 
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
//�ú���ʵ�ֵĹ����У�δ�����������ʱ��ѹ����������վ�������ո񣬴��������ʱ����������� 
int PostInStack(const char *string, pStack operand)//���ؼ����� 
{ 
    int i=0;// i as xiabiao 
    while(string[i]!='\0') 
    { 
        /*ʵ�ֶ�λ���ļ���洢��ʶ�������������������*/
        if(!IsOperator(string[i])) //���������������ô��char������ת��Ϊint��һ����
        { 
                int sum=string[i]-'0'; 
                ++i;// pointer move ahead 
                while(!IsOperator(string[i]))//�����λ�� 
                { 
	                sum=sum*10+string[i]-'0'; 
	                ++i; 
                } 
                push(operand,sum); //ת����Ͼ�ѹ������ջ
                while(string[i]==' ') //������������Ŀո�
                { 
                    ++i; 
                }//remove space 
        } 
        else//�ǲ������žͽ�������
        { 
           int a,b,res; 
           pop(operand,&a); 
           pop(operand,&b); 
           switch(string[i]) 
           //�����������װһ��switch��������������gcc�������ԭ����Ҳ����
           { 
                 case'+':res=a+b;break; 
                 case'/':res=b/a;break; 
                 case'-':res=b-a;break; 
                 case'*':res=a*b;break; 
           } 
           push(operand,res); //������Ϻ����ջ��
           i++; 
           while(string[i]==' ') 
           { 
               ++i; 
           } 
        } 
    } 
    int result=GetTop(operand,&result); //ɨ�������ջ��
    return result; 
} 
int Input(char **string) //��ΪOJ�Ͼ�̬�����ڴ�����޷��������⣬ ֻ���ֶ�����
{ 
    *string = (char *)malloc(sizeof(char)* 1000); 
    gets(*string); 
    return true; 
} 
int main(void) 
{ 
    Stack Operand, Operator; 
    int result; 
    initial(&Operand);//��ʼ��������ջ 
    char *string; 
    Input(&string); 
    /*printf("%s\n", string); 
    system("pause");*/
    result = PostInStack(string, &Operand);//�������ֱ����ջ 
    printf("%d\n", result); 
    //system("pause"); 
    return 0; 
} 

