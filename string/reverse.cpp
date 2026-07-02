#include<bits/stdc++.h>
using namespace std;

string reverse(string s){
    string str ="";
    for(int i=s.size()-1;i>=0;i--){
        str+=s[i];
    }
    return str;
}
int main(){
    string s = "Hello";
    cout<<reverse(s);
}