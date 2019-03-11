#include <stdio.h>
#include <stdlib.h>
int main()
{
 /*申明初始化器的种子，注意是unsigned int 型的*/
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
