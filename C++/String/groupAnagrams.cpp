/*
49. Group Anagrams
https://leetcode.com/problems/group-anagrams/
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

//Better solution from the discussion panel
class Solution 
{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) 
        {
            unordered_map<string, vector<string>> umap;
            for (string inputWord : strs) 
            {
                string sortedWord = inputWord; 
                sort(sortedWord.begin(), sortedWord.end());
                umap[sortedWord].push_back(inputWord);
            }
            vector<vector<string>> anagrams;
            for (auto umapIdx : umap) 
                anagrams.push_back(umapIdx.second);
        return anagrams;
    }
};

// My Solution
/*class Solution 
{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) 
        {
            unordered_map<string, vector<int>> umap;
            unordered_map<string, vector<int>>::iterator it;
            vector<vector<string>> returnVector;
            vector<string> tempVector;
            vector<string> sortedVector(strs);
            string sortedWord;
            int idx = 0;

            for(string &str : sortedVector)
                sort(str.begin(), str.end());

            for(auto &sortedWord : sortedVector)
            {
                it = umap.find(sortedWord);
                if(it != umap.end())
                    (it->second).push_back(idx);
                else
                    umap[sortedWord].push_back(idx);
                idx++;
            }
            for(auto &umapIdx : umap)
            {
                for(auto &vectorIdx : umapIdx.second)
                    tempVector.push_back(strs[vectorIdx]);
                returnVector.push_back(tempVector);
                tempVector.clear();
            }
            return returnVector;
        }
};*/

int main()
{
    vector<string> inputVector = {"eat","tea","tan","ate","nat","bat"};//{"a"};
    Solution solObj;
    vector<vector<string>> finalAnswer = solObj.groupAnagrams(inputVector);
    for(int i = 0; i < finalAnswer.size(); i++)
    {
        for(auto it = finalAnswer[i].begin(); it != finalAnswer[i].end(); it++)
            cout<<*it<<" ";
        cout<<endl;
    }
    return 0;
}