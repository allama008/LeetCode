/*
895. Maximum Frequency Stack
https://leetcode.com/problems/maximum-frequency-stack/
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;

class FreqStack 
{
    public:
        unordered_map<int, int> freq;
        unordered_map<int, stack<int>> m;
        int maxfreq = 0;

        FreqStack() 
        {
            
        }

        void push(int x) 
        {
            maxfreq = max(maxfreq, ++freq[x]);
            m[freq[x]].push(x);
        }

        int pop() 
        {
            int x = m[maxfreq].top();
            m[maxfreq].pop();
            if (!m[freq[x]--].size()) maxfreq--;
            return x;
        }

};
//My Solution. Working but TLE
/*
class FreqStack 
{
    public:
        vector<int> stack;
        unordered_map<int, int> umap;
        vector<int> highestFreq;
        int maxCount = INT_MIN;
        int result = 0;
        FreqStack() 
        {
            
        }
        
        void push(int val) 
        {
            stack.push_back(val);
            umap[val]++;
            if(!highestFreq.empty() && umap[val] == maxCount)
                highestFreq.push_back(val);
            else if(!highestFreq.empty() && umap[val] > maxCount)
            {
                highestFreq.clear();
                highestFreq.push_back(val);
            }

        }
        
        int pop() 
        {
            if(highestFreq.empty())
            {    
                maxCount = INT_MIN;
                for(auto it = umap.begin(); it != umap.end(); it++)
                    if(maxCount < it->second)
                    {
                        highestFreq.clear();
                        highestFreq.push_back(it->first);
                        maxCount = it->second;
                    }
                    else if(maxCount == it->second)
                        highestFreq.push_back(it->first);
            }
            for(int i = stack.size() - 1; i >= 0; i--)
            {
                for(auto it = highestFreq.begin(); it != highestFreq.end(); it++)
                    if(*it == stack[i])
                    {
                        result = *it;
                        umap[*it]--;
                        highestFreq.erase(it);
                        stack.erase(stack.begin() + i);
                        return result;
                    }
            }
            return result;
        }
};
*/

int main()
{
    FreqStack* obj = new FreqStack();
    obj->push(5);
    obj->push(7);
    obj->push(5);
    obj->push(7);
    obj->push(4);
    obj->push(5);    
    cout<<obj->pop()<<endl;
    cout<<obj->pop()<<endl;
    cout<<obj->pop()<<endl;
    cout<<obj->pop()<<endl;
    return 0;
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */