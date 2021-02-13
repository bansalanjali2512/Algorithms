/*
    Q.1: Given order of n matrices, find the minimum multiplication
         operations required for multiplying n matrices.
    Submitted By: Anjali Bansal (04)
    Date: 24th Oct, 2018
*/

#include <iostream>
using namespace std;

int s[20][20];      //2D array to store the where to apply parenthesis
int md[2][20];

//******************************
//function declaration
//******************************

int matrixChainOrder(int p[], int n);
void printOptimalParens(int s[20][20], int i, int j);
bool checkCompatibility(int md[2][20], int n);


//******************************
//main function
//******************************

int main () {
    /*
        Objective       : Given order of n matrices, find the minimum multiplication
                          operations required for multiplying n matrices.
        Input parameters: None
        Return Value    : Integer
    */

    int n;                        //number of matrices
    cout << "\n Enter number of matrices you want to multiply: ";
    cin >> n;

    int r, c;
    cout << "\n Enter matrix dimensions: ";
    for(int i = 0; i < n; i++) {
        cout << "\n Enter Matrix" << i+1 << " dimension: ";
        cin >> r >> c;
        md[0][i] = r;
        md[1][i] = c;
    }

    if( !checkCompatibility(md, n) )
        cout << "\n Matrices Not compatible!";
    else
        cout << "\n Matrices Compatible!";

    while( !checkCompatibility(md, n) ) {
        cout << "\n\n Enter compatible matrix dimensions: ";
        for(int i = 0; i < n; i++) {
            cout << "\n Enter Matrix" << i+1 << " dimension: ";
            cin >> r >> c;
            md[0][i] = r;
            md[1][i] = c;
        }
    }

    //cout << "\n\n Minimum Multiplication Operations Required: " << matrixChainOrder(p, n);
    cout << endl;
    return 0;
}


//******************************
//function definition
//******************************

int matrixChainOrder(int p[], int n) {
    /*
        Objective       : Given order of n matrices, find the minimum multiplication
                          operations required for multiplying n matrices
        Input parameters: p - Integer array, contain matrix dimensions
                          n - Integer, Number of matrices
        Return Value    : Integer, minimum multiplication operations required
    */

    int m[n][n];                       //2D array to store number of operations

    for(int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    int j, q;
    for(int l = 2; l <= n; l++) {      //l is the chain length

        for(int i = 1; i <= (n - l + 1); i++) {

            j = (i + l - 1);
            m[i][j] = INT_MAX;

            for(int k = i; k <= j - 1; k++) {

                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "\n Optimal Parenthesis: ";
    printOptimalParens(s,1,n);

    return m[1][n];
}


void printOptimalParens(int s[20][20], int i, int j)
{
    /*
        Objective       : Given order of n matrices, print optimal parenthesis for
                          multiplying n matrices in minimum multiplication operations
        Input parameters: s - Integer array, contain matrix dimensions
                          i - Integer,
                          j - Integer,
        Return Value    : None
    */

    if(i == j) {
        cout << "A" << i;
    }
    else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}


bool checkCompatibility(int md[2][20], int n) {
    int j = 0;
    for(int i = 0; i < n-1; i++) {
        if(md[1][j] != md[0][j+1]) {
            return false;
        }
        j++;
    }
    return true;
}
