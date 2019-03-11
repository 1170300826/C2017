#include <stdio.h>
#include <stdlib.h>
#include <math.h>
unsigned len = 0;
#define TMax len-1
#define TMin -TMax-1
/*run this program using the console pauser or add your own getch, system("pause") or input loop */
//2.57
void show_short()
{
	printf("short:%d\n",sizeof(short));
}
void show_long()
{
	printf("long:%d\n",sizeof(long));
}
void show_double()
{
	printf("double:%d\n",sizeof(double));
}
//2.61
y = !((x&0xFF000000FF)>>24)||!(~((x&0xFF000000FF)<<24)) 
//2.65
int odd_ones(unsigned x)
{
	unsigned y1,y2,y3,y4,y5;
	y1 = x <<4;
	x = (x>>4) ^ (y1>>4);//16位 
	y2 = x <<3;
	x = (x>>3) ^ (y2>>3);//8
	y3 = x <<2;
	x = (x>>2) ^ (y2>>2);//4
	y4 = x <<1;
	x = (x>>1) ^ (y3>>1);//2
	y4 = x <<0;
	x = (x>>0) ^ (y3>>0);//1
	return x;
}
//2.69
unsigned rotate_left(unsigned x,int n)
{
	int i,j,k;
	unsigned x1,x2,x3;	
	x1 = x<<n;
	x2 = x>>(32-n);
	x3 = x1 | x2;
	return x3;	
}
//2.73
int saturating_add(int x,int y)
{
	unsigned len = 0;
	return x+y;
	if(x + y>len-1)
	{
		return TMax;
	}
	else if(x+y <(-(len-1)-1))
	{
		return TMin;
	}
}
//2.77 yes
void Caculate(int x)
{
	int x1,x2,x3,x4;
	x1 = (x<<4) + x;
	printf("x1=%d ",x1);
	x2 = -((x<<3) - x);
	printf("x2=%d ",x2);
	x3 = (x<<6) - (x<<2);
	printf("x3=%d ",x3);
	x4 = -((x<<7)- (x<<4));
	printf("x4=%d\n",x4);
}
//2.81
void dectobin(unsigned int n)
{
	unsigned int result=0,k=1,i,temp;
	int j = 0,a[32];
	temp = n;
	while(temp){
	    j++;
		i = temp%2;	
		a[j] = i;	
		temp = temp/2;
		
	}
	for(k=j;k>=1;k--)
	{
	   printf("%u", a[k]);
	}
	//printf("\n");
}
void Byte_moduleA(int k)
{
	unsigned len = 0,num;
	num = ((1>>(sizeof(int)<<3 -k))-1)<<k;
	printf("A:");
	dectobin(num);		
}
void Byte_moduleB(int j,int k)
{
	unsigned len = 0,a,b,num2,num3;
	b=len-1;
	int i,j1;
	printf("B:");
	num = ((1>>k)-1)<<j;
	dectobin(num3);		
}
//2.85
A.E=127,M=
V = 2^E * M
//2.93
typedef unsigned float_bits;
void ten_totwo(unsigned a)
{
	unsigned b,k,i;
	unsigned c[32];
    k=0;
    while(a!=0)
	{ 
	    k++; 
        c[k]=a%2;
        a=a/2;	
    };
    for (i=32;i>=1;i--)
	{
		if(i>k)
		{
			printf("0");
		}
		else 
		{ 
		  printf("%u",c[i]);
		}
    } 
    printf("\n");
}
float_bits float_absval(float_bits f)
{
	int E,Bias=127;
	float_bits M;
	float_bits sign = f>>31;
	float_bits exp = f>>23 & 0xFF;
	float_bits frac = f & 0x7FFFFF;
	if (exp == 255)//当f是NaN 
	{
    	return f;
	}
	if(sign == 0)
	{
	    return f;
	}
	else if(sign = 1)
	{
		f=f-pow(2,31);
		return f;	
	}
 } 
 void test()//缺少测试函数 
 {
 	else if(exp == 0)//非规格化 
	{
		printf("1\n");
		E=1-Bias;
		M = frac >> 23;
		return M<<E;
	}
	else if(exp>0)//规格化 
	{
		//printf("2\n");
		E = exp-Bias;
		//printf("%u\n",exp);
		//printf("%u\n",E);
		M =1+(frac>>23);
		//printf("%u\n",M);
		return M<<E;
	}
 }
 //2.97
float_bits float_i2f(int i)
{
	int j;
	float_bits exp,f,f1,V;
	if(i < 0)
	{
		i = -i;
		for(j=0;;j++)
		{
			if((i >>j) <1)
			{
				break;
			}
		}
		exp = (j-1) + 127;//阶码 
		f = (i<<(25-j))-(1<<24);//尾数,24位	
		if(f<<31 == 1)
		{
			f1 = f>>2;
			f = f1<<1;//f是23位 
		}
		else
		{
			f = f>>1;
		}
		V = (exp<<23) + f + (2<<30);	
    }
	else 
	{
		for(j=0;;j++)
		{
			if((i >>j) <1)
			{
				break;
			}
		}
		exp = (j-1) + 127;//阶码 
		f = (i<<(25-j))-(1<<24);//尾数,24位	
		if(f<<31 == 1)
		{
			f1 = f>>2;
			f = f1<<1;//f是23位 
		}
		else
		{
			f = f>>1;
		}
		V = (exp<<23) + f;	
	}
	return V; 
}
float_bits test(int i)
{
	float a;
	a = (float) i;
	float_bits x = *((float_bits *)&a);
	return x;
 } 
int main(int argc, char *argv[])
{
	show_short();
	show_long();
	show_double();
	return 0;
}
