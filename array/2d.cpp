#include<iostream>
using namespace std;
void printEvenColumn(int arr[][4]){
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(j%2==0) cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<3;i++){
        int sum = 0;
        for(int j=0;j<4;j++){
            sum += arr[i][j];
        }
        cout<<"row "<<i<<": "<<sum<<endl;
    }
    
}
void returnMax(int arr[][4]){
    int maxSum = INT_MIN;
    int index;
    for(int i=0;i<3;i++){
        int sum = 0;
        for(int j=0;j<4;j++){
            sum += arr[i][j];
        }
        if(sum>=maxSum){
            maxSum = sum;
            index = i;
        }
    }
    cout<<"Sum: "<<maxSum<<endl;
    cout<<"Index: "<<index<<endl;
}
void zigzag(int arr[4][4]){
    int k=0;
    for(int i=0;i<4;i++){
        if(k==0){
            k=1;
            for(int j=0;j<4;j++){
                cout<<arr[j][i]<<" ";
            }
        }
        else{
            k=0;
            for(int j=3;j>=0;j--){
                cout<<arr[j][i]<<" ";
            }
        }
        cout<<endl;
    }
}
void spiralPrint(int arr[][4], int n, int m){
    int left_corner = 0;
    int top_row = 0;
    int right_corner = m-1;
    int bottom_row = n-1;
    while(top_row<=bottom_row && left_corner<=right_corner){
        for(int i = left_corner; i<=right_corner; i++){
            cout<<arr[top_row][i]<<" ";
        }
        top_row++;
        cout<<endl;
        for(int i = top_row; i<=bottom_row; i++){
            cout<<arr[i][right_corner]<<" ";
        }
        right_corner--;
        cout<<endl;
        for(int i = right_corner; i>=left_corner; i--){
            cout<<arr[bottom_row][i]<<" ";
        }
        bottom_row--;
        cout<<endl;
        for(int i = bottom_row; i>=top_row; i--){
            cout<<arr[i][left_corner]<<" ";
        }
        left_corner++;
        cout<<endl;
    }
}
int main(){
   
    int arr[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    //zigzag(arr);
    //
    spiralPrint(arr,4,4);
}