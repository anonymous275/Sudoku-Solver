#include<stdio.h>
#include<stdlib.h>
#define n 9
int board[n][n];
//int row=0,col=0;
void printgrid(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ",board[i][j]);
        printf("\n");
    }
}
int findunassignedplace(int *row,int *col){
    for((*row)=0;(*row)<n;(*row)++){
        for((*col)=0;(*col)<n;(*col)++)
            if(board[*row][*col]==0)
              return 1;
    }
    return 0;
}
int usedinrow(int row,int num){
    int i;
    for(i=0;i<n;i++){
        if(board[row][i]==num)
            return 1;
    }
    return 0;
}
int usedincol(int col,int num){
    int i;
    for(i=0;i<n;i++){
        if(board[i][col]==num)
            return 1;
    }
    return 0;
}
int usedinbox(int startrow,int startcol,int num){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(board[startrow+i][startcol+j]==num)
                return 1;
        }
    }
    return 0;
}
int issafe(int row,int col,int num){
    if(!usedinrow(row,num) && !usedincol(col,num) && !usedinbox(row-row%3,col-col%3,num))
        return 1;
    else
        return 0;
}
int sudoku(){
    int num,row,col;
    if(!findunassignedplace(&row,&col))
        return 1;
    for(num=1;num<=9;num++){
        if(issafe(row,col,num)){
            board[row][col]=num;
            if(sudoku())
                return 1;
            board[row][col]=0;
        }
    }
    return 0;
}
int main(){
    int i,j,a;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            board[i][j]=0;
    }
    printf("******************************* SUDOKU SOLVER ******************************************\n");
    printf("Enter a partially filled-in grid and assign '0' to the location where there is nothing\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            scanf("%d",&board[i][j]);
    }
    a=sudoku();
    printf("YOUR SUDOKU SOLUTION IS:\n");
    if(!a)
        printf("Solution doesn't exists\n");
    else
        printgrid();
    return 0;
}
