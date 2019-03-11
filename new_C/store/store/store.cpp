#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3
struct Electric
{
	char name[N];
	char brand[N];
	float price;//
	char num[N];
	struct Electric *next;
};
typedef struct Electric *elepointer;
typedef struct Electric Electric;
elepointer Read_list(elepointer l)//从文件读入数据  
{
   FILE *fp;
   Electric *p,*q;
   char m[20],m[20];
   int n,n1;
   p=(Electric *)malloc(sizeof(Electric));
   p=NULL;
   l=NULL;
   l=p;
   q=(Electric *)malloc(sizeof(Electric));
   q->next=NULL;
   if((fp=fopen("D:\\list1.txt","rb"))==NULL)
    {
      printf("cannot open file\n");
    }
   else
      {
       if(fscanf("%d %d %s %s",n,m,) !=EOF)
       {
	   }
     }
       }
   }
} 
void Begin_list(elepointer l)//开始营业 
{
	int inum,i,j,k;
	elepointer p,s;
	float f;
	printf("How many datas do you want to input?\n");
	scanf("%d",&inum);
	printf("input your datas:");
	for(i=0;i<inum;i++)//将数据存入链表s中 
	{
		s = (Electric *)malloc(sizeof(Electric));
		printf("input the No.%d name:",i+1);
		scanf("%s",&s->name); 
		/*for(j = strlen(s->name)+2;j<N;j++)
		{
			l->name[j]=1;
		}*/
		printf("input the No.%d brand:",i+1);
		scanf("%s",&s->brand); 
		/*for(j = strlen(l->brand)+1;j<N;j++)
		{
			l->brand[j]= 1;
		}*/ 
		printf("input the No.%d price:",i+1);
		scanf("%s",&s->price); 
		printf("input the No.%d num:",i+1);
		scanf("%s",&s->num); 
		l->next = s;
		l = s->next;
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
		if(fwrite(p,sizeof(Electric),1,f) != 1) 
		printf("writing error\n");
		p = p->next;
    }
    printf("Saved\n");
    fclose(f);
}
void Push_list(elepointer l)//进货 
{
	int i,j=0,k,pnum;
	printf("Which goods do you want to insert?\n");
	scanf("%d",&pnum);//输入进货的数量 
	printf("please input the information of product\n");
	elepointer p,s,q;
	p = l;
	q= l->next; 
	while(q!= NULL)//为什么q不等于l 
	{
		q= q->next;
		j++;
	}
	if(pnum<1 || pnum>j)
	{
		printf("error\n");
	}
	else
	{
		for(j=1;j<pnum;j++)//将数据存入链表s中 
		{ 
		    p = p->next;
	    }
		s = (elepointer)malloc( sizeof(Electric));
		printf("input the  name:\n");
		scanf("%s",&s->name); 
		for(j = strlen(s->name)+2;j<N;j++)
		{
			s->name[j]= 1;
		}
		printf("input the  brand:\n");
		scanf("%s",&s->brand); 
		for(j = strlen(s->brand)+1;j<N;j++)
		{
			s->brand[j]= 1;
		}
		printf("input the  price:\n");
		scanf("%s",&s->price); 
		printf("input the  num:\n");
		scanf("%s",&s->num); 
		s ->next = p->next;
		p->next = s;//插入S在p与p->next之间 
		printf("\n");
	}	
}
void Pop_list(elepointer l)//取货 
{
	int i,j=0,k,onum;
	printf("Which goods do you want to take?\n");
	scanf("%d",&onum);
	elepointer p,s;
	p = l;
	s= l->next;
	while(p != NULL)
	{
		p = p->next;
		j++;
	}
	if(onum<1 || onum >j)
	{
		printf("error\n");
	}
	else
	{
		for(j=1;j<onum;j++)
		{
			p = p->next; 
		}
		s = p->next;
		p->next = s->next ;
		free(s) ;
	}	 
}
void Search_list(elepointer l)//查询信息 
{
	int i,j=0,k;
	printf("Which goods do you want to search?\n");
	scanf("%d",&i);
	elepointer p,s;
	p = l;
	s= l->next;
	while(s != NULL)
	{
		s = s->next;
		j++;
	}
	printf("1\n");
	if(i<1 || i>j)
	{
		printf("error\n");
	}
	else
	{
		for(j = 1;j<i;j++)
		{
			p = p->next;
		}
		if(p == NULL)
		{ 
		  printf("error\n");;
		}
		else
		{
			printf("the name is %s,the brand is %s,the price is %f,the num is %d\n",p->name,p->brand,p->price,p->num);
		}	
	}
}
void Update_list(elepointer l)//更新信息 (待改) 
{
	int j=0,i,k,m=0;
   Electric *p;
   printf("Which line do you want to updata?\n");
   scanf("%d",&i);
   p=l->next;
   while(p!=NULL)
   {
       p=p->next;
       j++;
    }
   p=l;
   if(i<1||i>j)
      printf("error\n");
   else
      {for (j=1;j<=i;j++)
          p=p->next;
    printf("the No.%d's name is:",i);
    scanf("%s",&p->name);
    while(p->name[m]!='\0')
            m++;
    for(k=m+1;k<=14;k++)
        p->name[k]=' ';
    printf("the No.%d's brand is:",i);
    scanf("%s",&p->brand);
        m=0;
    while(p->brand[m]!='\0')
            m++;
    for(k=m+1;k<=14;k++)
        p->brand[k]=' ';
    printf("the No.%d's price is:",i);
    scanf("%f",&p->price);
    printf("the No.%d's num is:",i);
    scanf("%d",&p->num);
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
	   printf("Num        JDname         JDbrand        prize          amount\n");
	   while(p!=NULL)
	   {
	      /*if(i<10)
		 printf("No.%d       ",i);
	      else*/
		printf("No.%d      ",i);
	    for(j=0;j<3;j++)
		   printf("%c",p->name[j]);
		printf(" ");
	    for(j=0;j<3;j++)
		   printf("%c",p->brand[j]);
		printf(" ");
		printf("%s",p->price);
		printf(" ");
		printf("%s",p->num);
		printf(" ");
	    printf("\n");
	    p=p->next;
	    i++;
	   }
   }
}
int Menu(void)
{
	int choice;
	printf("The module of a store\n");
	printf("1.输入信息（创建表）\n2.营业开始\n3.进货\n4.提货\n");
	printf("5.查询信息\n6.更新信息\n7.营业结束\n8.加载文件\n9.显示\n10.退出\n");
	scanf("%d",&choice);
	return choice;
} 
int main()
{
	int choice;
	//choice = Menu();
	elepointer l;
	l = (elepointer)malloc(sizeof(Electric));
	while(choice != 10)
	{
		switch(choice)
		{
			case 1:
				Begin_list(l);
				break;
			case 2:
				//clrscr();
				Read_list(l);
				break;
			case 3:
				//clrscr();
				Push_list(l);
				break;
			case 4:
				//clrscr();
				Pop_list(l);
				break;
			case 5:
				Search_list(l);
				break;
			case 6:	
				Update_list(l);
				break;
			case 7:
				Wtofile(l);
				break;
			case 8:
				l = Read_list(l);
				break;
			case 9:
				Print_list(l);
				break;
			case 10:
				break;
		}
	    choice = Menu();
	}

}
