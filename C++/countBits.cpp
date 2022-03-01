/*
338. Counting Bits
https://leetcode.com/problems/counting-bits/
*/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution 
{
    public:
        vector<int> countBits(int n)
        {
            vector<int> returnVector(n+1);
            returnVector[0] = 0;
            for(int i = 1; i <= n; i++)
                returnVector[i] = returnVector[i/2] + i%2;
            return returnVector;
        }
};

//My Solution. O(nlgn) time solution.
/*
class Solution 
{
    private:
        int countBitsHelper(int n)
        {
            int sum = 0;
            while(n)
            {
                sum += n%2;
                n /= 2;
            }
            return sum;
        }
    public:
        vector<int> countBits(int n)
        {
            vector<int> returnVector;
            for(int i = 0; i <= n; i++)
                returnVector.push_back(countBitsHelper(i));
            return returnVector;
        }
};
*/
int main()
{
    Solution solObj;
    vector<int> finalAnswer = solObj.countBits(2);
    for(auto i : finalAnswer)
        cout<<i<<" ";
    cout<<endl;
    finalAnswer = solObj.countBits(5);
    for(auto i : finalAnswer)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}