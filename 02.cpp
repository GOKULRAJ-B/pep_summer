#include <iostream>
using namespace std;

void doubleTheValue(int &num){
    num *= 2;
    cout<< "Inside :" << num << endl;
}

int main(){
    int num = 10;
    doubleTheValue(num);

    cout<< "Outside : " << num << endl;
}