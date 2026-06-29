//https://leetcode.com/problems/find-all-anagrams-in-a-string/?envType=problem-list-v2&envId=sliding-window
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        unordered_map<int,int> p_map,s_map;
        for(auto i : p){
            p_map[i]++;
        }
        vector<int>result;
        for(int i=0;i<s.size();i++){
            s_map[s[i]]++;

            if(i>=k) s_map[s[i-k]]--;
            
            if(i>=k && s_map[s[i-k]]==0) s_map.erase(s[i-k]);

            if(i>=k-1 && s_map==p_map) result.push_back(i-k+1);

        }
        return result;
    }
};