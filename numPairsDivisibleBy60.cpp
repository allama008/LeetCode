/*
1010. Pairs of Songs With Total Durations Divisible by 60
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution 
{
    public:
        int numPairsDivisibleBy60(vector<int>& time) 
        {
            int counter = 0;
            vector<int> vec(60, 0);
            for(auto i = time.begin(); i != time.end(); i++)
            {
                int a = *i%60;
                if(a == 0)
                    counter += vec[0];
                else
                    counter += vec[60 - a];
                vec[a]++;
            }
            return counter;
        }
};

int main()
{
    Solution solobj;
    //solobj.printHello();
    vector<int> Sol = {30, 20, 150, 100, 40};
    int finalAnswer = solobj.numPairsDivisibleBy60(Sol);
    cout<<finalAnswer<<endl;
    /*for(auto i = Sol.begin(); i != Sol.end(); i++)
        cout<<*i<<" ";*/
    return 0;
}