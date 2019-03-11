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
void EnQueue(char x,QUE *Q，int flag)//压栈 ,flag是1，压入左孩子，否则压入右孩子 
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
void DeQueue(QUE *Q)//出栈 
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
BTREE CreateBT()//建立二叉树 
{
    BTREE p;
	p = (node *)malloc(sizeof(node));
	p->lchild = NULL;
	p->rchild = NULL; 
	char v1,v2;
	v1 = getchar();
	v2 = getchar();
	if(v1 == ',')//若第一个数是逗号，将第二个数存在节点，再读取一个数，若为10，递归依次找左右节点
	{
		p->data = v2;
		v1 = getchar();
		if(v1 == '(')
		{
			p->lchild = CreateBT();
			p->rchild = CreateBT();
		}
	}
	else//若第一个数非0，将第一个数存在节点，依次找左右节点
	{
		p->data = v1;
		if(v2 == '(')
		{
			//printf("左孩子：");
			p->lchild = CreateBT();
			//printf("右孩子：");
			p->rchild = CreateBT();	
		}	
	}
	return p;
}
/*1>//如果树为空，则直接返回错 
2>//如果树不为空：层序遍历二叉树 
2.1//如果一个结点左右孩子都不为空，则pop该节点，将其左右孩子入队列； 
2.1//如果遇到一个结点，左孩子为空，右孩子不为空，则该树一定不是完全二叉树； 
2.2//如果遇到一个结点，左孩子不为空，右孩子为空；或者左右孩子都为空；则该节点之后的队列中的结点都为叶子节点；该树才是完全二叉树，否则就不是完全二叉树；
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
int Judge_tree(BTREE p)//判断是否为完全二叉树 
{
	int flag = 1,tag = 0;
	QUE *q1,*top;
	BTREE lc,rc;
	lc = (node *)(malloc)(sizeof(node));
	rc = (node *)(malloc)(sizeof(node));
	q1 = (QUE *)(malloc)(sizeof(QUE));
	top = (QUE *)(malloc)(sizeof(QUE));
	MakeNUll(q1);
	if(p == NULL)//1>如果树为空，则直接返回错 
	{
		return 0;
	}
	EnQueue(p->data,q1); 
	while(!Empty(q1))//若栈q1不为空 
	{
		if(p->rchild)
		{
			if(p->lchild)//如果一个结点左右孩子都不为空，则pop该节点，将其左右孩子入队列； 
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
		else//左右孩子都为空；则该节点之后的队列中的结点都为叶子节点；该树才是完全二叉树，否则就不是完全二叉树
		{
			while(!Empty(q1))
			{
				top = q1->front;//栈顶的值
				if(top->lchild == NULL&& top->rchild == NULL)//数组结构体只能记录孩子的值，不能记录父亲的左孩子和右孩子 
				{
				    DeQueue(q1);
				}
				else
				{
					flag = 0;//若存在非叶子节点，不是二叉树 
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
BTREE CreateBT()//建立二叉树 
{
    BTREE p;
	p = (node *)malloc(sizeof(node));
	p->lchild = NULL;
	p->rchild = NULL; 
	char v1,v2;
	v1 = getchar();
	v2 = getchar();
	if(v1 == ',')//若第一个数是逗号，将第二个数存在节点，再读取一个数，若为10，递归依次找左右节点
	{
		p->data = v2;
		v1 = getchar();
		if(v1 == '(')
		{
			p->lchild = CreateBT();
			p->rchild = CreateBT();
		}
	}
	else//若第一个数非0，将第一个数存在节点，依次找左右节点
	{
		p->data = v1;
		if(v2 == '(')
		{
			//printf("左孩子：");
			p->lchild = CreateBT();
			//printf("右孩子：");
			p->rchild = CreateBT();	
		}	
	}
	return p;
}
int Compnode(node * b)
{
	node *Qu[N],*p; //定义一个队列，用于层次遍历
	int front=0,rear=0; //队头、队尾指针
	int cm=1;
	int bj=1;
	if(b!=NULL)
	{
		rear++;
		Qu[rear]=b; //进队
		while(front!=rear)
		{	
			front++;
			p=Qu[front];
			if(p->lchild==NULL) //*p节点没有左孩子
			{
				bj=0;
				
				if(p->rchild!=NULL) //没有左孩子但有右孩子
				
				cm=0; //则不是完全二叉树
		    }
			else //*p节点有左子树
			{
				if(bj==1) //迄今为止，所有节点均有左孩子
				{
					rear++; //左孩子进队
					Qu[rear] = p->lchild;
					if(p->rchild==NULL) //*p有左孩子但没有右孩子
					{
						bj=0;
					}
					else
					{
					rear++; //右孩子进队
					Qu[rear]=p->rchild;
				
			        }
			    }
				else //bj=0:迄今为止，已有节点缺孩子
				  { 
				     cm=0; //而此时*p节点有左孩子，违反
		          }					
		    }
			return cm;	
		}	
	}
	else
	{
	  return 1; //把空树当成特殊的完全二叉树
    }
}
int main()
{
	BTREE p;
	p = (node *)malloc(sizeof(node));
	p = CreateBT();
	if(Compnode(p))
	{
		printf("是\n");
	}
	free(p);
}
