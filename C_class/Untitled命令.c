#include<unistd.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
if(argc==1 || argc>2) {
printf("请输入想要编辑的文件名如:./edit fillen");
}
if(argc==2) {
printf("编辑 %sn",argv[1]);
}
exit(0);
}
