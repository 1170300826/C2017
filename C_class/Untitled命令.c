#include<unistd.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
if(argc==1 || argc>2) {
printf("��������Ҫ�༭���ļ�����:./edit fillen");
}
if(argc==2) {
printf("�༭ %sn",argv[1]);
}
exit(0);
}
