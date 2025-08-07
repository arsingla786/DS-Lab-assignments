//5) Write a program to find sum of every row and every column in a two-dimensional array.

#include<iostream>
using namespace std;
int main(){
    int arr[2][3]= {4,5,6,7,8,9};

    for(int i=0;i<2;i++){
        int rowSum=0;
            for(int j=0;j<3;j++){
                rowSum += arr[i][j];
            }
            cout<<"sum of row "<<i<<"="<<rowSum<<endl;
    }

    for(int j=0;j<3;j++){
        int colSum=0;
            for(int i=0;i<2;i++){
                colSum += arr[i][j];
            }
            cout<<"sum of col "<<j<<"="<<colSum<<endl;
    }
}
//end//
//Arnav singla - 1024031010
