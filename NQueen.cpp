/*
    Q.3: Implement N Queen's problem using Back Tracking.
    Submitted By: Anjali Bansal (04)
*/

#include <iostream>
using namespace std;

int solnCount = 0;

//******************************
//function declaration
//******************************

void printBoard(int* board, int n);
bool isValid(int *board, int row, int col, int n);
bool solveNQueen(int *board, int n, int col);
bool nQueen(int n);


//******************************
//main function
//******************************

int main () {
    /*
        Objective       : Implement N Queen's problem using Back Tracking
        Input parameters: None
        Return Value    : Integer
    */

    int n;
    cout<<"Enter chessboard dimension: ";
    cin>>n;

    nQueen(n);

    cout << endl;
    return 0;
}


//******************************
//function definition
//******************************

void printBoard(int* board, int n) {
     /*
        Objective       : To print possible solution
        Input parameters: board - pointer to 2D array of size n*n
                          n - Integer, dimension of chessboard
        Return Value    : None
    */

    for(int i = 0; i < n; i++) {
        cout << "    ";
        for(int j = 0; j < n; j++) {
            cout << " " << *(board + i * n + j) << " ";
        }
        cout << endl;
    }
}


bool isValid(int *board, int row, int col, int n) {
    /*
        Objective       : Check whether queen can be placed or not in cell board[row][col]
        Input parameters: board - pointer to 2D array of size n*n
                          row - row in which queen is to be placed
                          col - column in which queen is to be placed
                          n - Integer, dimension of chessboard
        Return Value    : true if queen can be placed
                          otherwise, return false
    */

    //check row on left side
    for (int i = 0; i < col; i++) {
        if(*(board + row * n + i)) {
            return false;
        }
    }

    //check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(*(board + i * n + j)) {
            return false;
        }
    }

    //check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < n; i++, j--) {
        if(*(board + i * n + j)) {
            return false;
        }
    }

    return true;
}


bool solveNQueen(int *board, int n, int col) {
    /*
        Objective       : Solve N Queen's problem using Back Tracking
        Input parameters: board - pointer to 2D array of size n*n
                          n - Integer, dimension of chessboard
                          col - column in which queen is to be placed
        Return Value    : true if solution exist
                          otherwise, return false
    */

    //print possible solution
    if(col == n) {
        solnCount++;
        cout<<"\n\n *** Solution " << solnCount << " *** \n\n";
        printBoard(board, n);
        return true;
    }

    bool isSolnExist = false;
    for(int i = 0; i < n; i++) {
        //check if valid or not to place the queen
        if(isValid(board, i, col, n)) {
            *(board + i * n + col) = 1;     //place the queen
            isSolnExist = solveNQueen(board, n, col + 1) || isSolnExist;
            *(board + i * n  + col) = 0;    //backtrack to find possible solution
        }
    }

    return isSolnExist;
}


bool nQueen(int n) {
    /*
        Objective       : Implement N Queen's problem using Back Tracking
        Input parameters: n - Integer, dimension of chessboard
        Return Value    : false if queens cannot be placed
                          otherwise, return true
    */

    int board[n][n];        //chessboard with n*n dimension

    //initializing the chessboard cells to 0
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    //check if solution not exist
    if(solveNQueen(*board, n, 0) == false) {
      cout << "\n Solution does not exist!";
      return false;
    }

    return true;
}
