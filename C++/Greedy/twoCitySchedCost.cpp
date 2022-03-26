/*
1029. Two City Scheduling
https://leetcode.com/problems/two-city-scheduling/
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool compareFunction(vector<int> &firstElement, vector<int> &secondElement)
{
    if(firstElement[0] - firstElement[1] < secondElement[0] - secondElement[1])
        return true;
    return false;
}

class Solution 
{
    /* Placing compareFunction doesn't work here. Neither does it work if placed inside
    ** the public scope resolution operator. It has to be a global function.
    private:
        bool compareFunction(vector<int> &firstElement, vector<int> &secondElement)
        {
            if(firstElement[0] - firstElement[1] < secondElement[0] - secondElement[1])
                return true;
            return false;
        }
    */
    public:
        int twoCitySchedCost(vector<vector<int>>& costs) 
        {
            sort(costs.begin(), costs.end(), compareFunction);
            int vectorSize = costs.size()/2, result = 0;
            for(int i = 0; i < vectorSize; i++)
                result += costs[i][0] + costs[i+vectorSize][1];
            return result;
        }
};

// Same solution by another author in concise manner.
/*
class Solution 
{
    public:
        int twoCitySchedCost(vector<vector<int>>& costs) 
        {
            sort(costs.begin(), costs.end(), [](const vector<int> &firstElement, const vector<int> &secondElement) {return (firstElement[0] - firstElement[1] < secondElement[0] - secondElement[1]);});
            int vectorSize = costs.size()/2, result = 0;
            for(int i = 0; i < vectorSize; i++)
                result += costs[i][0] + costs[i+vectorSize][1];
            return result;
        }
};
*/
int main()
{
    vector<vector<int>> costs = {{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}}, costs1 = {{10,20},{30,200},{400,50},{30,20}};
    Solution solObj;
    cout<<solObj.twoCitySchedCost(costs)<<" "<<solObj.twoCitySchedCost(costs1)<<endl;
    return 0;
}