/*4) Implement the logic to 
a. Reverse the elements of an array 
b. Find the matrix multiplication 
c. Find the Transpose of a Matrix*/

//(a)
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"reversed array = ";
    int i=0;
    while(i<n/2){
        swap(arr[i],arr[n-i-1]);
        i++;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


//(b)

#include<iostream>
using namespace std;
int main(){
    int arr1[2][3] = {1,2,3,4,5,6};
    int arr2[3][2] = {1,2,3,4,5,6};

    int mul[2][2] = {0};

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<3;k++){
                mul[i][j] += arr1[i][k]*arr2[k][j];
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<mul[i][j]<<" ";
        }
        cout<<endl;
    }
}

//(c)
#include<iostream>
using namespace std;
int main(){
    int arr[2][3]={1,2,3,4,5,6};
    int transpose[3][2] = {0};

    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            transpose[i][j]=arr[j][i];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
}




