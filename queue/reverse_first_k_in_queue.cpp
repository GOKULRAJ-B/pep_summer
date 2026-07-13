//https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        if(k<=0 || k>q.size()) return q;
        stack<int> st;
        for(int i=0;i<k;i++){
            st.push(q.front());
            q.pop();
        }
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        int n = q.size();
        for(int i=0;i<n-k;i++){
            q.push(q.front());
            q.pop();
        }
        return q;
    }
};