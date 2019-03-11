#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <conio.h>
//行和列
#define ROW 10
#define COL 11
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/**
*


*
*/
//地图
char map[ROW][COL] = {
    "##########",//0
    "###     ##",//1
    "###     ##",//2
    "##AX  # ##",//3
    "###  ##   ",//4
    "#####    #",//5
    "##       #",//6
    "#     ####",//7
    "###       ",//8
    "##########" //9
    //A:人  ， X：箱子
    } ;
//打印地图
void showMap();
//接收小人的方向
char enterDirection();

//小人向上移动的方法
void moveToUp();
//小人向下移动的方法
void moveToDown();
//小人向右移动的方法
void moveToRight();
//小人向左移动的方法
void moveToLeft();

//当前小人的坐标
int currentPersonRow = 3;
int currentPersonCol = 2;
//当前箱子的坐标
int currentBoxRow = 3;
int currentBoxCol = 3;



int main(int argc, char *argv[]) {
    //system("clear");
    printf("点击回车键开始游戏 ^_^\n\n");
    //1代表运行   0停止
    int flag = 1;
    while(flag==1){
    //显示地图
    showMap();
    //接收小人的方向
    char dir = enterDirection();
    switch(dir){
        //小人向上移动
        case 'w':
        case 'W':
            moveToUp();
        break;

        //小人向下移动
        case 's':
        case 'S':
            moveToDown();
        break;
        //小人向右移动
        case 'd':
        case 'D':
            moveToRight();
        break;
        //小人向左移动
        case 'a':
        case 'A':
            moveToLeft();
        break;
        //停止运行
        case 'q':
        case 'Q':
            printf("你的智商真低！T_T\n");
            flag = 0;
        break;
    }
    showMap();
    if(currentBoxRow==8&&currentBoxCol==9){
        printf("你的智商真高^_^!!!");
        flag = 0;
        }

}

}
/*
方法的实现
*/


//打印地图
void showMap(){
    int i;
    for(i = 0;i < ROW; i++){
        printf("%s\n",map[i]);
    }
    printf("\n\n\n\n\n");
    printf("W:上，S：下， A：左， D：右。Q：退出");
    printf("\n\n\n\n\n");
}
//接收小人的方向
char enterDirection(){
    //清除SCANF中的缓冲区
    rewind(stdin);
    char dir;
    dir = getch();
    //scanf("%c",&dir);
    return dir;
}
//小人向上移动的方法
void moveToUp(){
    //小人的下一个坐标
    int nextPersonCol = currentPersonCol;
    int nextPersonRow = currentPersonRow - 1;
    //箱子的下一个坐标
    int nextBoxRow = currentBoxRow - 1;
    int nextBoxCol = currentBoxCol;

    //如果小人的下一个坐标是路
    if(map[nextPersonRow][nextPersonCol]==' '){
    map[nextPersonRow][nextPersonCol] = 'A';
    map[currentPersonRow][currentPersonCol] = ' ';
    currentPersonRow = nextPersonRow;
    currentPersonCol = nextPersonCol;
    }
    //如果小人的下一个坐标是墙
    if(map[nextPersonRow][nextPersonCol]=='#'){
        //什么也不做
    }
    //如果小人的下一个坐标是箱子
    if(map[nextPersonRow][nextPersonCol]=='X'){
        if(map[nextBoxRow][nextBoxCol] == ' '){

        map[nextPersonRow][nextPersonCol] = 'A';
        map[currentPersonRow][currentPersonCol] = ' ';

        map[nextBoxRow][nextBoxCol] = 'X';
        map[currentBoxRow][currentBoxCol] = 'A';


        currentPersonRow = nextPersonRow;
        currentPersonCol = nextPersonCol;
        currentBoxRow = nextBoxRow;
        currentBoxCol = nextBoxCol;
    }
 }
}
//小人向下移动的方法
void moveToDown(){
        //小人的下一个坐标
    int nextPersonCol = currentPersonCol;
    int nextPersonRow = currentPersonRow + 1;
    //箱子的下一个坐标
    int nextBoxRow = currentBoxRow + 1;
    int nextBoxCol = currentBoxCol;

    //如果小人的下一个坐标是路
    if(map[nextPersonRow][nextPersonCol]==' '){
    map[nextPersonRow][nextPersonCol] = 'A';
    map[currentPersonRow][currentPersonCol] = ' ';
    currentPersonRow = nextPersonRow;
    currentPersonCol = nextPersonCol;
    }
    //如果小人的下一个坐标是墙
    if(map[nextPersonRow][nextPersonCol]=='#'){
        //什么也不做
    }
    //如果小人的下一个坐标是箱子
    if(map[nextPersonRow][nextPersonCol]=='X'){
        if(map[nextBoxRow][nextBoxCol] == ' '){

        map[nextPersonRow][nextPersonCol] = 'A';
        map[currentPersonRow][currentPersonCol] = ' ';

        map[nextBoxRow][nextBoxCol] = 'X';
        map[currentBoxRow][currentBoxCol] = 'A';

        currentPersonRow = nextPersonRow;
        currentPersonCol = nextPersonCol;
        currentBoxRow = nextBoxRow;
        currentBoxCol = nextBoxCol;
    }
    }
}
//小人向右移动的方法
void moveToRight(){
    //小人的下一个坐标
    int nextPersonCol = currentPersonCol + 1;
    int nextPersonRow = currentPersonRow;
    //箱子的下一个坐标
    int nextBoxRow = currentBoxRow;
    int nextBoxCol = currentBoxCol + 1;

    //如果小人的下一个坐标是路
    if(map[nextPersonRow][nextPersonCol]==' '){
    map[nextPersonRow][nextPersonCol] = 'A';
    map[currentPersonRow][currentPersonCol] = ' ';
    currentPersonRow = nextPersonRow;
    currentPersonCol = nextPersonCol;
    }
    //如果小人的下一个坐标是墙
    if(map[nextPersonRow][nextPersonCol]=='#'){
        //什么也不做
    }
    //如果小人的下一个坐标是箱子
    if(map[nextPersonRow][nextPersonCol]=='X'){
        if(map[nextBoxRow][nextBoxCol]==' '){

        map[nextPersonRow][nextPersonCol] = 'A';
        map[currentPersonRow][currentPersonCol] = ' ';

        map[nextBoxRow][nextBoxCol] = 'X';
        map[currentBoxRow][currentBoxCol] = 'A';

        currentPersonRow = nextPersonRow;
        currentPersonCol = nextPersonCol;
        currentBoxRow = nextBoxRow;
        currentBoxCol = nextBoxCol;
    }
    }
}
//小人向左移动的方法
void moveToLeft(){
    //小人的下一个坐标
    int nextPersonCol = currentPersonCol - 1;
    int nextPersonRow = currentPersonRow;
    //箱子的下一个坐标
    int nextBoxRow = currentBoxRow;
    int nextBoxCol = currentBoxCol - 1;

    //如果小人的下一个坐标是路
    if(map[nextPersonRow][nextPersonCol]==' '){
    map[nextPersonRow][nextPersonCol] = 'A';
    map[currentPersonRow][currentPersonCol] = ' ';
    currentPersonRow = nextPersonRow;
    currentPersonCol = nextPersonCol;
    }
    //如果小人的下一个坐标是墙
    if(map[nextPersonRow][nextPersonCol]=='#'){
        //什么也不做
    }
    //如果小人的下一个坐标是箱子
    if(map[nextPersonRow][nextPersonCol]=='X'){
        if(map[nextBoxRow][nextBoxCol]==' '){
        map[nextPersonRow][nextPersonCol] = 'A';
        map[currentPersonRow][currentPersonCol] = ' ';

        map[nextBoxRow][nextBoxCol] = 'X';
        map[currentBoxRow][currentBoxCol] = 'A';

        currentPersonRow = nextPersonRow;
        currentPersonCol = nextPersonCol;
        currentBoxRow = nextBoxRow;
        currentBoxCol = nextBoxCol;
    }
    }
}

