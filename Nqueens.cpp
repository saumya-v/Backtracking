#include<iostream>
#include<vector>
using namespace std;
bool isBoardsafe(vector<vector<int>> &board,int row,int col){
    int n=board.size();
    //same column
    for(int i=row-1;i>=0;i--){
        if(board[i][col]==1){
            return false;
        }
    }
    //upper left diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }
    //upper right diagonal
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
}
void placeQueen(vector<vector<int>> board,int row,int n){
    //we have reached some solution, print the board matrix and return
    if(row==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    //place at all possible positions and move to smaller problem
    //if we cant get the position right and want to backtrack then replace the 1 which you put before to 0
    for(int j=0;j<n;j++){
        if(isBoardsafe(board,row,j)){
            board[row][j]=1;
            placeQueen(board,row+1,n);
            board[row][j]=0;
        }
    }
}
void placeNqueens(int n){
    vector<vector<int>> board(n,vector<int>(n,0));
    placeQueen(board,0,n);
}
int main(){
    int n;
    cin>>n;
    placeNqueens(n);
}
