//https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1
class Solution {
  public:
    string removeDuplicates(string &s) {
        // code here
        string str="";
        set<char>uni;
        for(auto i : s){
            int size = uni.size();
            uni.insert(i);
            if(uni.size()>size) str+=i;
        }
        return str;
    }
};

class Solution {
  public:
    string removeDuplicates(string &s) {
        // code here
        vector<bool> seen(256,false);
        string str = "";
        for(auto i : s){
            if(!seen[i]){
                str+=i;
                seen[i]=true;
            }
        }
        return str;
    }
};