/*
941. Valid Mountain Array
https://leetcode.com/problems/valid-mountain-array/
*/

#include<iostream>
#include<vector>
using namespace std;

/*class Solution 
{
    public:
        bool validMountainArray(vector<int>& arr) 
        {
            if(arr.size() < 3)
                return false;
            bool startIncrease = true, startDecrease = false;
            int counterIncrease = 0, counterDecrease = 0;
            for(auto it = arr.begin() + 1; it != arr.end() - 1; it++)
            {
                if((*it > *(it-1)) && !startDecrease)
                    counterIncrease++;
                else if((*it > *(it -1)) && startDecrease)
                    {cout<<"Checkpoint1.\n"; return false;}
                else if((*it < *(it - 1)) && startDecrease)
                    counterDecrease++;
                else if((*it < *(it - 1)) && !startDecrease && !counterDecrease)
                {
                    startDecrease = true;
                    counterDecrease++;
                }
                else
                    {cout<<"Checkpoint2.\n"; return false;}
            }
        if(counterIncrease > 0 && counterDecrease > 0 && startDecrease)
            return true;
        else
            {cout<<"Checkpoint3.\n"; return false;}
        }
        
};*/

class Solution 
{
    public:
        bool validMountainArray(vector<int>& arr) 
        {
            if(arr.size() < 3)
                return false;
            vector<int>::iterator it = arr.begin() + 1;
            int counterIncrease = 0, counterDecrease = 0;
            for(it; it != arr.end() - 1; it++)
            {
                if(*it <= *(it -1))
                    break;
                counterIncrease++;
            }
            if(!counterIncrease)
                return false;
            if(it + 1 != arr.end())
                it++;
            for(it; it != arr.end(); it++)
            {
                if(*it >= *(it-1))
                    return false;
                counterDecrease++;
            }
            if(!counterDecrease)
                return false;
            return true;
        }
        
};

int main()
{
    vector<vector<int>> testVector = {{1, 2, 3, 4, 3, 2, 1}, {1, 1, 2, 3, 1},
                                    {5, 4, 6, 3, 2}, {5, 6, 3, 5}, {5, 4, 3, 2},
                                    {2, 3, 4, 5}, {1, 2, 1}, {1, 2}};
    vector<int> testVector1 = {3, 5, 5};
    Solution solObj;
    //for(int i = 0; i < testVector.size(); i++)
        //for(auto it = testVector[i].begin(); it != testVector[i].end(); it++)
            //cout<<boolalpha<<solObj.validMountainArray(testVector[i])<<endl;
    cout<<boolalpha<<solObj.validMountainArray(testVector1);
    return 0;

}