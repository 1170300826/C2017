#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
void DrawMap(int map[10][12]);
void checkkb();
int a=0,b=0;
int count = 0;//分数0
int gmap[10][12]={
	{0,0,0,1,1,1,0,0,0,0,0,0},
	{0,0,0,1,3,1,0,0,0,0,0,0},
	{0,0,0,1,0,1,1,1,1,1,1,1},
	{1,1,1,1,4,0,4,0,0,0,3,1},
	{1,3,0,0,4,2,1,1,1,1,1,1},
	{1,1,1,1,1,4,1,0,0,0,0,0},
	{0,0,0,0,1,0,1,0,0,0,0,0},
	{0,0,0,0,1,0,1,0,0,0,0,0},
	{0,0,0,0,1,3,1,0,0,0,0,0},
	{0,0,0,0,1,1,1,0,0,0,0,0}};//1代表墙   2代表人  3代表目标位置  4代表箱子
int main(){

	//设置窗口大小
	system("mode con cols=80 lines=25");
	//设置窗口标题
	SetConsoleTitleA("推箱子");
	while(1){
		system("cls");//清屏
		printf("    推箱子游戏\n");
		checkkb();
		DrawMap(gmap);

		printf("分数:%d\n",count);
		printf("坐标:<%d,%d>\n",a+1,b+1);

		_sleep(50);
	}
	return 0;
}
void DrawMap(int map[10][12]){
    int i,j;
	for( i=0;i<10;i++){
		for( j=0;j<12;j++){
			switch(map[i][j]){
			case 0:
				printf("  ");//画道路
				break;
			case 1:
				printf("█");//画墙
				break;
			case 3:
				printf("&&");//画目的地
				break;
			case 2:
				printf("♂");//画小人
				a=i;b=j;
				break;
			case 4:
				printf("□");//画箱子
				break;
			case 5:
				printf("★");//箱子和目的地重合
				break;

			}
		}
		printf("\n");
	}
}

void checkkb(){
if(kbhit())
    {
	char c = getch();
	switch(c){
	case 72://上
		switch(gmap[a-1][b]){
		case 0://路
		gmap[a][b]=0;
		gmap[a-1][b]=2;
		break;
		case 4://箱子
			if(gmap[a-2][b]==3){//是目的地
				gmap[a][b]=0;
				gmap[a-2][b]=5;
				gmap[a-1][b]=2;
				count++;
				break;
			}
			if(gmap[a-2][b]!=1){//不是墙
				gmap[a][b]=0;
				gmap[a-2][b]=4;
				gmap[a-1][b]=2;
			}


		break;

		}

		break;
	case 80://下
		switch(gmap[a+1][b]){
		case 0://路
		gmap[a][b]=0;
		gmap[a+1][b]=2;
		break;
		case 4://箱子
			if(gmap[a+2][b]==3){//是目的地
				gmap[a][b]=0;
				gmap[a+2][b]=5;
				gmap[a+1][b]=2;
				count++;
				break;
			}
			if(gmap[a+2][b]!=1){//不是墙
				gmap[a][b]=0;
				gmap[a+2][b]=4;
				gmap[a+1][b]=2;
			}


		break;

		}
		break;
	case 75://左
        switch(gmap[a][b-1]){
		case 0://路
		gmap[a][b]=0;
		gmap[a][b-1]=2;
		break;
		case 4://箱子
			if(gmap[a][b-2]==3){//是目的地
				gmap[a][b]=0;
				gmap[a][b-2]=5;
				gmap[a][b-1]=2;
				count++;
				break;
			}
			if(gmap[a][b-2]!=1){//不是墙
				gmap[a][b]=0;
				gmap[a][b-2]=4;
				gmap[a][b-1]=2;
			}

		break;

		}
		break;
	case 77://右
		switch(gmap[a][b+1]){
		case 0://路
		gmap[a][b]=0;
		gmap[a][b+1]=2;
		break;
		case 4://箱子
			if(gmap[a][b+2]==3){//是目的地
				gmap[a][b]=0;
				gmap[a][b+2]=5;
				gmap[a][b+1]=2;
				count++;
				break;
			}
			if(gmap[a][b+2]!=1){//不是墙
				gmap[a][b]=0;
				gmap[a][b+2]=4;
				gmap[a][b+1]=2;
			}

		break;

		}
		break;
	}
}
}

