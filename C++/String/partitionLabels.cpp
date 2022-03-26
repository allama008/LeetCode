/*
763. Partition Labels
https://leetcode.com/problems/partition-labels/
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;

/*
class Solution 
{
    public:
        vector<int> partitionLabels(string s) 
        {
            unordered_map<char, int> umap;
            vector<int> outputVector;
            int idx = 0;
            for(auto it = s.begin(); it != s.end(); it++, idx++)
                umap[*it] = max(umap[*it], idx);
            int previousIdx = -1, lastIdx = umap[s[0]];
            for(auto it = s.begin() + 1; it != s.end(); it++)
                if()
            
        }
};
*/
/*
class Solution {
    public:
        vector<int> partitionLabels(string s) 
        {
            unordered_map<char,int>mp;
            // filling impact of character's
            for(int i = 0; i < s.size(); i++)
                mp[s[i]] = i;
            // making of result
            vector<int> res;
            int prev = -1;
            int maxi = 0;
            
            for(int i = 0; i < s.size(); i++)
            {
                maxi = max(maxi, mp[s[i]]);
                if(maxi == i)
                {
                    // partition time
                    res.push_back(maxi - prev);
                    prev = maxi;
                }
            }
            return res;
        }
};

*/
class Solution 
{
    public:
        vector<int> partitionLabels(string s) 
        {
            vector<int> result;
            unordered_map<char, int> umap;
            int maxIdx = 0, prevIdx = -1, strLength = s.size();
            for(int i = 0; i < strLength; i++)
                umap[s[i]] = i;
            
            for(int i = 0; i < strLength; i++)
            {
                maxIdx = max(maxIdx, umap[s[i]]);
                if(maxIdx == i)
                {
                    result.push_back(maxIdx - prevIdx);
                    prevIdx = maxIdx;
                }
            }
            return result;
        }
};

int main()
{
    string s = "ababcbacadefegdehijhklij";
    Solution solObj;
    vector<int> finalAnswer = solObj.partitionLabels(s);
    for(auto i : finalAnswer)
        cout<<i<<" ";
    return 0;
}
