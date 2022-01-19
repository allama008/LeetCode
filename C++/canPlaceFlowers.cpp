/*
605. Can Place Flowers
https://leetcode.com/problems/can-place-flowers/
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n) 
        {
            int flag = 0, counterCheck = n;
            vector<int>::iterator it = flowerbed.begin();
            while(it != flowerbed.end())
            {
                if(*it == 0 && (it == flowerbed.begin() || *(it - 1) == 0) && (it == flowerbed.end()-1 || *(it+1) == 0))
                {    
                    *it = 1;
                    flag++;
                }
                if(flag >= n)
                    return true;
                it++;
            }
            return false;
        }
};

/*class Solution {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n) 
        {
            int flag = 0, counterCheck = n;
            vector<int>::iterator it = flowerbed.begin();
            while(it != flowerbed.end())
            {
                if(*it == 0)
                    flag++;
                else if(*it == 1)
                    flag = 0;
                if(flag == 3)
                {
                    flag = 1;
                    counterCheck--;
                }
                it++;
            }
            if(counterCheck == 0)
                return true;
            return false;
        }
};*/

int main()
{
    vector<int> vec = {0, 0, 1, 1};
    Solution solObj;
    bool finalAnswer = solObj.canPlaceFlowers(vec, 1);
    cout<<boolalpha<<finalAnswer<<endl;
    return 0;
}