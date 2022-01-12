/*
13. Roman to Integer
https://leetcode.com/problems/roman-to-integer/
*/

#include<iostream>
#include<unordered_map>
#include<string>
#include<array>
using namespace std;

class Solution 
{
    public:
        int romanToInt(string s) 
        {
            unordered_map<string, int> umap;
            umap["I"] = 1;
            umap["V"] = 5;
            umap["X"] = 10;
            umap["L"] = 50;
            umap["C"] = 100;
            umap["D"] = 500;
            umap["M"] = 1000;
            umap["IV"] = 4;
            umap["IX"] = 9;
            umap["XL"] = 40;
            umap["XC"] = 90;
            umap["CD"] = 400;
            umap["CM"] = 900;

            int stringLength = s.length();
            int i = stringLength - 1;
            int counter = 0, sum = 0;
            string strSubset;
            while(i >= 0)
            {
                if(i >= 1)
                {
                    strSubset = s.substr(i - 1, 2);
                }    
                else
                    strSubset = 'Q';
                auto it = umap.find(strSubset);
                if(it != umap.end())
                {
                    sum += (it->second);
                    i -= 2;
                }
                else
                {
                    strSubset = s.substr(i, 1);
                    it = umap.find(strSubset);
                    if(it != umap.end())
                    {
                        sum += (it->second);
                        i--;
                    }
                }
                counter++;
            }
            return sum;
        }
};

int main()
{
    Solution solObj;
    /*int answer = solObj.romanToInt("III");
    cout<<answer<<endl;*/
    array<string, 3> vec = {"III", "LVIII", "MCMXCIV"};
    for(auto i = 0; i < 3; i++)
    {
        int answer = solObj.romanToInt(vec[i]);
        //cout<<"1.Check"<<vec[i]<<endl;
        cout<<answer<<endl;
    }
    return 0;
}