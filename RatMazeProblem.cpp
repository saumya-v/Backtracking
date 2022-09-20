#include<iostream>
using namespace std;
void printSolution(int solution[20][20],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << solution[i][j] << " ";
        }
    }
    cout<<endl;
}
void mazeHelp(int maze[20][20],int n,int solution[20][20],int x,int y){
    if(x == n-1 && y == n-1){
        solution[x][y] =1;
        printSolution(solution,n);
        solution[x][y] =0;
        return;
    }
    if(x>=n || x<0 || y>=n || y<0 || maze[x][y] ==0 || solution[x][y]==1){
        return;
    }
    //to include itself
    solution[x][y] = 1;
    //for upwards
    mazeHelp(maze,n,solution,x-1,y);
    //for downwards
    mazeHelp(maze,n,solution,x+1,y);
    //to move left
    mazeHelp(maze,n,solution,x,y-1);
    //to move right
    mazeHelp(maze,n,solution,x,y+1);
    //put 0 after exploring all paths so that further kaam aa paaye
    solution[x][y] = 0;
}
void ratInAMaze(int maze[20][20], int n){
    int solution[20][20];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            solution[i][j]=0;
        }
    }
// initialization of solution 2D arrays goes here.
    mazeHelp(maze,n,solution,0,0);
}

int main(){
    int n;
    cin>>n;
    int maze[20][20];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
    ratInAMaze(maze,n);
}
