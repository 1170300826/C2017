#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50
struct Electric
{
	char name[N];
	char brand[N];
	float price;
    int num;
	struct Electric *next;
};
typedef struct Electric *elepointer;
typedef struct Electric Electric;
void Begin_list(elepointer l)//开始营业 
{
	int inum,i,j,k;
	elepointer p,s;
	float f;
	printf("How many datas do you want to input?\n");
	scanf("%d",&inum);
	printf("input your datas(从小到大输入):");
	for(i=0;i<inum;i++)//将数据存入链表s中 
	{
		s = (Electric *)malloc(sizeof(Electric));
		printf("input the No.%d name:",i+1);
		scanf("%s",s->name); 
		printf("input the No.%d brand:",i+1);
		scanf("%s",s->brand); 
		printf("input the No.%d price:",i+1);
		scanf("%f",&s->price); 
		printf("input the No.%d num:",i+1);
		scanf("%d",&s->num); 
		l ->next = s;//将s插入l 
		l = s;
		l->next = NULL;	
	}
}
void Print_list(elepointer l)
{
   elepointer p;
   int i=1,j;
   p=l->next;
   if(p==NULL)
      printf("error\n");
   else
   {
	   printf("Product name brand price num\n");
	   while(p!=NULL)
	   {
		printf("%s %s %.2f %d\n",p->name,p->brand,p->price,p->num);
	    p=p->next;
	    i++;
	   }
   }
}
void Wtofile(elepointer l)//将链表l存入文件中 
{
	FILE *f;
	elepointer p;
	p = l ->next;
	if((f = fopen("D:\\list1.txt","wb")) == NULL)
	{
		printf("Open Fail!\n");
		exit(1);
	}
	while(p!=NULL)
	{
		if(fprintf(f,"%s %s %f %d ",p->name,p->brand,p->price,p->num)<0) 
		{
		   printf("writing error\n");
		} 
		//fprintf(f,"\n");
		p = p->next;
    }
    printf("Saved\n");
    fclose(f);
}
elepointer Read_list(elepointer l)//从文件读入数据 
{
    FILE * fp=NULL;
    int n;
	float n1;
    char m[20],m1[20];
    fp=fopen("D:\\list1.txt","r"); 
    if(fp==NULL)
    {
		  printf("error\n");
		  return NULL;
	}
    elepointer p,q,s;
    p=(elepointer)malloc(sizeof(Electric));
    q=s=p;
    while(fscanf(fp,"%s %s %f %d",m,m1,&n1,&n)!=EOF)
    {
        s=(elepointer)malloc(sizeof(Electric));
        s->num = n;
        s->price=n1;
        strcpy(s->name,m); 
        strcpy(s->brand,m1);
        s->next=NULL;      
        q->next=s;
        q=s;           
    }
    fclose(fp);          
    return p;
} 
void Pop_list(elepointer l)//取货 
{
	int i,j=0,k,onum,nump,flag =0;
	char oname[N];
	printf("Which goods do you want to take?");
	scanf("%d",&onum);//输入取货的数量
	elepointer p,s,q;
	p = l;
	for(i=0;i<onum;i++)
	{
		printf("please input the name of NO.%d product:",i+1);
		scanf("%s",oname);	
		printf("please input the num of NO.%d product:",i+1);
		scanf("%d",&nump);
		while(p->next!=NULL)
		{
			//printf("1\n");
			if(strcmp(l->name,oname) == 0)
			{
				l->num -=nump;
				if(l->num<=0)  
				{
					if(l->num < 0)
					{
						printf("%s is not enough\n",oname);
					}
					s=l;
					l=s->next;
				}
			}
			if(strcmp((p->next)->name,oname) == 0) 
			{
				flag = 1;
				(p->next)->num -=nump; 
				if((p->next)->num <= 0)
				{
					if((p->next)->num < 0)
					{
						printf("%s is not enough\n",oname);
					}
					s = p->next;
					p->next = s->next;
				}
				break;
			}
			p = p->next;
		} 
		if(flag == 0)
		{
			printf("input error\n");
		}
		p=l; 		
	 } 
}
void Push_list(elepointer l)//进货 
{
	int i,j=0,k=0,pnum,sum;
	char pname[N];
	float price,price1,price2,price3,price4;
	elepointer p,s;
	p = l; 
	printf("How many goods do you want to insert?");
	scanf("%d",&sum);
	for(i=0;i<sum;i++)
	{
		s = (elepointer)malloc(sizeof(Electric));
		printf("the NO.%d name of the goods  you want to insert is:",i+1);
		scanf("%s",s->name);
		printf("the NO.%d amount of the goods  you want to insert is:",i+1);
		scanf("%d",&s->num);
		if( p == NULL)
		{
			printf("error\n");
		}
		while(p != NULL)//如果是旧的商品 
		{
			if(strcmp(p->name,s->name)==0)
			{
				p->num = p->num + (s->num);
				printf("%d\n",p->num); 
				k=1;
				break;
			}
			p = p->next;
		}
		p = l;
		if(k == 0)//新商品 
		{   
		    printf("the NO.%d brand of the goods  you want to take is:",i+1);
		    scanf("%s",s->brand);
		    printf("the NO.%d price of the goods  you want to take is:",i+1);
		    scanf("%f",&s->price);
			while( p != NULL)
			{
				//printf("1\n");
				price1 = s->price;
				price2 = p->price;
				price4 = l->price;
				if(price1>price2)//忽略头结点 
				{
					//printf("%f\n",p->price);
					s->next = p->next;
			        p->next = s;
					break;
				}
				else if(price1<price4)//头结点 
				{
					s = l;
					s->next = l;
					break;
				}
				p=p->next;
			}			
		}
		p=l;
	}	 
}
void Search_list(elepointer l)//查询信息 
{
	int i,j=0,k,flag=0;
	char aname[N];
	elepointer p;
	p = l; 
	printf("How many goods do you want to search?");
	scanf("%d",&i);
	for(k=0;k<i;k++)
	{
		printf("please input the name of NO.%d product:",k+1);
		scanf("%s",&aname);
		while(p != NULL)
		{
			if(strcmp(p->name,aname) == 0)
			{
				flag = 1;
				printf("Product %d: name brand price num\n",k+1);
			    printf(" %s, %s, %.2f, %d\n",p->name,p->brand,p->price,p->num);
			    break;
			}
			p=p->next;
		}
		if(flag == 0)
		{
			printf("input error\n");
		}
		p=l;	
	} 				
}
void Update_list(elepointer l)//更新信息 
{
	int i,j=0,k,n1,flag=0;
	float n;
	char m[N],m1[N],aname[N];
	elepointer p;
	p = l; 
	printf("How many goods do you want to update?");
	scanf("%d",&i);
	for(k=0;k<i;k++)
	{
		printf("please input the name of NO.%d product:",k+1);
		scanf("%s",&aname);
		while(p != NULL)
		{
			if(strcmp(p->name,aname) == 0)
			{
				flag = 1;
				printf("Product %d: name is ",k+1);
				scanf("%s",m);
				printf("Product %d: brand is ",k+1);
				scanf("%s",m1);
				printf("Product %d: price is ",k+1);
				scanf("%f",&n);
				printf("Product %d: num is ",k+1);
				scanf("%d",&n1);
			    strcpy(p->name,m);
			    strcpy(p->brand,m1);
			    p->price = n;
			    p->num = n1;
			    break;
			}
			p=p->next;
		}
		if(flag == 0)
		{
			printf("input error\n");
		}
		p=l;	
	} 				
}
void Fast_sort(elepointer l)
{
	elepointer p,q;
	char temp[N];
	float tp;
	int tc;
	p = l;
	for(p=l;p!=NULL;p=p->next)
	{
		for(q=p;q!=NULL;q=q->next)
		{
			if((p->price)>(q->price)) 
		   {
			strcpy(temp,(p->next)->name);
		    strcpy((p->next)->name,p->name);
		    strcpy(p->name,temp);
		    strcpy(temp,(p->next)->brand);
		    strcpy((p->next)->brand,p->brand);
		    strcpy(p->brand,temp);
		    tp = p->price;
		    p->price = (p->next)->price;
		    (p->next)->price = tp;
		    tc = p->num;
		    p->num = (p->next)->num;
		    (p->next)->num = tc;
	       }
		}
    } 
} 
int Menu(void)
{
	int choice;
	printf("                                       The module of a store\n\n\n");
	printf("1.输入信息（创建表）\n2.从文件读入信息（营业开始）\n3.进货\n4.提货\n");
	printf("5.查询信息\n6.更新信息\n7.向文件写入信息（营业结束）\n8.显示当前信息\n10.退出\n");
	scanf("%d",&choice);
	return choice;
} 
int main()
{
	int choice;
	elepointer l;
	choice = Menu();
	l = (elepointer)malloc(sizeof(Electric));
	while(choice != 10)
	{
		switch(choice)
		{
			case 1:
				system("cls");
				Begin_list(l);
				Fast_sort(l);
				break;
			case 2:
				system("cls");
				l = Read_list(l);
				break;
			case 3:
				system("cls");
				Push_list(l);
				break;
			case 4:
				system("cls");
				Pop_list(l);
				break;
			case 5:
				system("cls");
				Search_list(l);
				break;
			case 6:	
			    system("cls");
				Update_list(l);
				Fast_sort(l);
				break;
			case 7:
				system("cls");
				Wtofile(l);
				break;
			case 8:
				system("cls");
				Fast_sort(l);
				Print_list(l);
				break;
			default:
				break;
		}
	    choice = Menu();
	}
}

