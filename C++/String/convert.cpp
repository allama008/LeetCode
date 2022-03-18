/*
6. Zigzag Conversion
https://leetcode.com/problems/zigzag-conversion/
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution 
{
    public:
        string convert(string s, int numRows) 
        {
            int strLength = s.length(), idx = 0, jdx = 0, columnSize = 0, kdx = 0, ldx = 0;
            while(idx < strLength)
            {
                if(idx += numRows)
                    columnSize++;
                while(jdx < numRows - 2 && idx < strLength)
                {
                    columnSize++;
                    idx++;
                    jdx++;
                }
                jdx = 0;
            }
            if(idx < strLength)
                columnSize++;
            vector<vector<char>> zigZag(numRows, vector<char>(columnSize, ' '));
            for(int j = 0; j < columnSize; j++)
            {
                while(kdx < numRows && ldx < strLength)
                    zigZag[kdx++][j] = s[ldx++];
                if(kdx == numRows && numRows >= 2)
                    kdx -= 2;
                else if(kdx == numRows && numRows < 2)
                    kdx--;
                while(kdx != 0 && j < columnSize && ldx < strLength)
                    zigZag[kdx--][++j] = s[ldx++];
            }
            string returnString;
            for(int i = 0; i < numRows; i++)
                for(auto it = zigZag[i].begin(); it != zigZag[i].end(); it++)
                    if(*it != ' ')
                        returnString.push_back(*it);
            return returnString;
        }
};

int main()
{
    string str = "AB";
    Solution solObj;
    cout<<solObj.convert(str, 1)<<endl;
    return 0;
}