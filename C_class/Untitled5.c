#include <stdio.h>
#include <stdlib.h>
int main()
{
 /*������ʼ���������ӣ�ע����unsigned int �͵�*/
int k;
srand((unsigned int) time(NULL));
printf("Random Numbers are:\n");
for(k = 1; k <= 10; k++)
{
printf("%i",rand());
printf("\n");
}
return 0;
}
