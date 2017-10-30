/*  Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
    column is set to 0. */
    
#include <iostream>

using namespace std;

#define ROW 4
#define COL 6

void printMatrix(int arr[ROW][COL]){
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

void setZero(int arr[ROW][COL]){
    //  First find all rows and columns containing at least 1 zero.
    int rowDict[ROW] = {0};
    int colDict[COL] = {0};
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            if(arr[i][j] == 0){
                rowDict[i]++;
                colDict[j]++;
            }
        }
    }
    //  Set all rows with zeroes to 0
    for(int i = 0; i < ROW; i++) {
        if(rowDict[i] > 0)
            for(int j = 0; j < COL; j++)
                arr[i][j] = 0;
    }
    //  Set all columns with zeroes to 0
    for(int i = 0; i < COL; i++) {
        if(colDict[i] > 0) {
            for(int j = 0; j < ROW; j++)
                arr[j][i] = 0;
        }
    }
}

int main() {
    int array[ROW][COL];
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            array[i][j] = 1;
    array[3][2] = 0;
    array[1][2] = 0;
    array[0][5] = 0;
    printMatrix(array);
    cout << "----------" << endl << "setting zeroes..." << endl << "----------" << endl;
    setZero(array);
    printMatrix(array);
    
}