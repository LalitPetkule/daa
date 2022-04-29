#include<iostream>
using namespace std;
int grid[10][10];
int a = 0;
void print(int n) {
    for (int i = 0;i <= n-1; i++) {
        for (int j = 0;j <= n-1; j++) {
                cout<<grid[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}
bool isSafe(int col, int row, int n) {

    for (int i = 0; i < row; i++) {
        if (grid[i][col]) {
            return false;
        }
    }
    for (int i = row,j = col;i >= 0 && j >= 0; i--,j--) {
        if (grid[i][j]) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < n; j++, i--) {
        if (grid[i][j]) {
            return false;
        }
    }
    return true;
}
bool solve (int n, int row) {
    if (n == row) {
        a++;
    	cout<<a<<endl;
        print(n);
        return true;
    }

    bool result = false;
    for (int i = 0;i <=n-1;i++) {
        if (isSafe(i, row, n)) {
            grid[row][i] = 1;

            result = solve(n, row+1) || result;


            grid[row][i] = 0;
        }
    }
    return result;
}
int main()
{
        int n;
        cout<<"Enter the number of queen"<<endl;
        cin >> n;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                grid[i][j] = 0;
            }
        }
        bool res = solve(n, 0);
        if(res == false) {
            cout << -1 << endl; //if there is no possible solution
        } else {
            cout << endl;
        }
        cout<<"Total number of solutions : "<<a;
  return 0;
}
