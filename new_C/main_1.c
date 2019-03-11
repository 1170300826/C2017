#include <stdio.h>
#include <stdlib.h>
#define N 50
typedef struct{
	char data;
	struct node *lchild;
	struct node *rchild;
}node;
typedef node *BTREE;
/*typedef struct{
	char array;
	struct queue *left; 
	struct queue *right; 
}queue;
//typedef queue queue;
typedef struct{
	queue *front;
	queue *rear;
}QUE;
typedef QUE QUE;
void MakeNull(QUE *Q)
{
	Q->front = (queue *)malloc(sizeof(queue));
	Q->front->left = NULL;
	Q->front->right = NULL;
	Q->rear = Q->front;
}
int Empty(QUE *Q)
{
	if(Q->front == Q->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void EnQueue(char x,QUE *Q��int flag)//ѹջ ,flag��1��ѹ�����ӣ�����ѹ���Һ��� 
{
	if(flag)
	{
		Q->rear->left = (queue *)malloc(sizeof(queue));
		Q->rear = Q->rear->left;
		Q->rear = Q->rear->left;
		Q->rear->array = x;
		Q->rear->left = NULL;	
	} 
	else
	{
		Q->rear->right = (queue *)malloc(sizeof(queue));
		Q->rear = Q->rear->right;
		Q->rear = Q->rear->right;
		Q->rear->array = x;
		Q->rear->right = NULL;
	}
}
void DeQueue(QUE *Q)//��ջ 
{
	queue *tmp;
	tmp = (queue *)malloc(sizeof(queue));
	if(Empty(Q))
	{
		printf("queue is empty\n");
	}
	else
	{
		tmp = Q->front->left;
		Q->front->next = tmp->next;
		free(tmp);
		if(Q->front->next == NULL)
		{
			Q->rear = Q->front;
		}
	}
}
BTREE CreateBT()//���������� 
{
    BTREE p;
	p = (node *)malloc(sizeof(node));
	p->lchild = NULL;
	p->rchild = NULL; 
	char v1,v2;
	v1 = getchar();
	v2 = getchar();
	if(v1 == ',')//����һ�����Ƕ��ţ����ڶ��������ڽڵ㣬�ٶ�ȡһ��������Ϊ10���ݹ����������ҽڵ�
	{
		p->data = v2;
		v1 = getchar();
		if(v1 == '(')
		{
			p->lchild = CreateBT();
			p->rchild = CreateBT();
		}
	}
	else//����һ������0������һ�������ڽڵ㣬���������ҽڵ�
	{
		p->data = v1;
		if(v2 == '(')
		{
			//printf("���ӣ�");
			p->lchild = CreateBT();
			//printf("�Һ��ӣ�");
			p->rchild = CreateBT();	
		}	
	}
	return p;
}
/*1>//�����Ϊ�գ���ֱ�ӷ��ش� 
2>//�������Ϊ�գ�������������� 
2.1//���һ��������Һ��Ӷ���Ϊ�գ���pop�ýڵ㣬�������Һ�������У� 
2.1//�������һ����㣬����Ϊ�գ��Һ��Ӳ�Ϊ�գ������һ��������ȫ�������� 
2.2//�������һ����㣬���Ӳ�Ϊ�գ��Һ���Ϊ�գ��������Һ��Ӷ�Ϊ�գ���ýڵ�֮��Ķ����еĽ�㶼ΪҶ�ӽڵ㣻����������ȫ������������Ͳ�����ȫ��������
*//*
int Leaf(BTREE p1)
{
	if(p1->lchild == NULL&&p1->rchild == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int Judge_tree(BTREE p)//�ж��Ƿ�Ϊ��ȫ������ 
{
	int flag = 1,tag = 0;
	QUE *q1,*top;
	BTREE lc,rc;
	lc = (node *)(malloc)(sizeof(node));
	rc = (node *)(malloc)(sizeof(node));
	q1 = (QUE *)(malloc)(sizeof(QUE));
	top = (QUE *)(malloc)(sizeof(QUE));
	MakeNUll(q1);
	if(p == NULL)//1>�����Ϊ�գ���ֱ�ӷ��ش� 
	{
		return 0;
	}
	EnQueue(p->data,q1); 
	while(!Empty(q1))//��ջq1��Ϊ�� 
	{
		if(p->rchild)
		{
			if(p->lchild)//���һ��������Һ��Ӷ���Ϊ�գ���pop�ýڵ㣬�������Һ�������У� 
			{
				DeQueue(q1);
				lc = p->lchild;
				rc = p->rchild;
				EnQueue(lc->data,q1); 
				EnQueue(rc->data,q1); 
			}
			else
			{
				return 0;
			}
		}
		else//���Һ��Ӷ�Ϊ�գ���ýڵ�֮��Ķ����еĽ�㶼ΪҶ�ӽڵ㣻����������ȫ������������Ͳ�����ȫ������
		{
			while(!Empty(q1))
			{
				top = q1->front;//ջ����ֵ
				if(top->lchild == NULL&& top->rchild == NULL)//����ṹ��ֻ�ܼ�¼���ӵ�ֵ�����ܼ�¼���׵����Ӻ��Һ��� 
				{
				    DeQueue(q1);
				}
				else
				{
					flag = 0;//�����ڷ�Ҷ�ӽڵ㣬���Ƕ����� 
				}
		    }
			return flag;	
		}
	}
	free(top);
	free(q1);
	free(lc);
	free(rc);
}*/
BTREE CreateBT()//���������� 
{
    BTREE p;
	p = (node *)malloc(sizeof(node));
	p->lchild = NULL;
	p->rchild = NULL; 
	char v1,v2;
	v1 = getchar();
	v2 = getchar();
	if(v1 == ',')//����һ�����Ƕ��ţ����ڶ��������ڽڵ㣬�ٶ�ȡһ��������Ϊ10���ݹ����������ҽڵ�
	{
		p->data = v2;
		v1 = getchar();
		if(v1 == '(')
		{
			p->lchild = CreateBT();
			p->rchild = CreateBT();
		}
	}
	else//����һ������0������һ�������ڽڵ㣬���������ҽڵ�
	{
		p->data = v1;
		if(v2 == '(')
		{
			//printf("���ӣ�");
			p->lchild = CreateBT();
			//printf("�Һ��ӣ�");
			p->rchild = CreateBT();	
		}	
	}
	return p;
}
int Compnode(node * b)
{
	node *Qu[N],*p; //����һ�����У����ڲ�α���
	int front=0,rear=0; //��ͷ����βָ��
	int cm=1;
	int bj=1;
	if(b!=NULL)
	{
		rear++;
		Qu[rear]=b; //����
		while(front!=rear)
		{	
			front++;
			p=Qu[front];
			if(p->lchild==NULL) //*p�ڵ�û������
			{
				bj=0;
				
				if(p->rchild!=NULL) //û�����ӵ����Һ���
				
				cm=0; //������ȫ������
		    }
			else //*p�ڵ���������
			{
				if(bj==1) //����Ϊֹ�����нڵ��������
				{
					rear++; //���ӽ���
					Qu[rear] = p->lchild;
					if(p->rchild==NULL) //*p�����ӵ�û���Һ���
					{
						bj=0;
					}
					else
					{
					rear++; //�Һ��ӽ���
					Qu[rear]=p->rchild;
				
			        }
			    }
				else //bj=0:����Ϊֹ�����нڵ�ȱ����
				  { 
				     cm=0; //����ʱ*p�ڵ������ӣ�Υ��
		          }					
		    }
			return cm;	
		}	
	}
	else
	{
	  return 1; //�ѿ��������������ȫ������
    }
}
int main()
{
	BTREE p;
	p = (node *)malloc(sizeof(node));
	p = CreateBT();
	if(Compnode(p))
	{
		printf("��\n");
	}
	free(p);
}
