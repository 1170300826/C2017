#include <stdio.h>
#include <math.h>
/*int saturating_add(int x, int y)
{
	int sum;
	int a1, a2, a3, a4, a5, a6, a7, a8, a9,b1;
	int Tmax = 2147483647;
	int Tmin = -2147483647-1;
	sum = x + y;
	
	a1 = ((x >> 31));
	a2 = ((y >> 31));
	a3 = (sum >> 31);
	//printf("%d %d %d\n",a1,a2,a3);
	a4 = ((!a1) && (!a2) && a3);  //正溢出时为1，否则为0
	a5 = (a1) && (a2) && (!a3);  //负溢出时为1，否则为0
	//return (a4 & TMax) + (a5 & TMin) +()
	a6 = !(a4 | a5);
	a7 = ~((~(a4 << 31)) >> 31);
	a8 = (a5 << 31);
	//a8 = ~((~(a5 << 31)) >> 31);
	a9 = ~((~(a6 << 31)) >> 31);
	b1 = (~(a6 << 31));
	printf("b1 = %x\n",b1);
	printf("b1>>31 = %x\n",b1>>31);
	printf("a9 = %x\n",a9);
	//printf("%x\n",x+y);
	return  (a7 & Tmax) + (a8 & Tmin) + (a9 & (x + y));
}*/
int saturating_add(int x, int y)
{
	int TMax = 2147483647;
	int TMin = (TMax-1);
	int flagf1,flag1,flag0,mf1,m1,m0;
	int  sum;
	sum = x + y;
	flag1 = ((!((x >> 31))) && !((y >> 31)) && (sum >> 31));	//正溢出 
	flagf1 = ((((x >> 31))) && ((y >> 31)) && !(sum >> 31));	//负溢出 
	flag0 = !(flagf1 || flag1);//不溢出 
	m1 = ~((~(flag1<<31))>>31);
	mf1 = ~((~(flagf1<<31))>>31);
	m0 = ~((~(flag0<<31))>>31);
	return (m1 & TMax) +(mf1 & TMin) + (m0 & sum);
} 
int main(int argc, char *argv[])
{
	int x1=(1<<30),y1=(1<<30)+1,sum;
	sum = saturating_add(x1,y1);
	printf("%d\n",sum);
} 


