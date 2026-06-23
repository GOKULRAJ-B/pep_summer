#include<iostream>
using namespace std;
int main(){
    // int a=35;
    // // if(a>=35){
    // //     cout<<"pass";
    // // }
    // // else{
    // //     cout<<"Fail";
    // // }
    
    // char grade='A';
    // switch(grade){

    //     case 'A':
    //         cout<<"Excellent";
    //         break;
        
    //     case 'B':
    //         cout<<"Good";
    //         break;
        
    //     default:
    //         cout<<"Invalid";
    // }

    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(i==0 || i==5){
                cout<<"* ";
            }
            else{
                if(j==0 || j==5){
                    cout<<"* ";
                }
                else{
                    cout<<"  ";
                }
            }
        }
        cout<<endl;
    }
}