/*
1249. Minimum Remove to Make Valid Parentheses
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

/*class Solution 
{
    public:
        string minRemoveToMakeValid(string s) 
        {
            int prefixCount = 0, suffixCount = 0;
            //cout<<s<<endl;
            for(string::iterator it = s.begin(); it != s.end(); it++)
            {
                if(*it == '(')
                    prefixCount++;
                else if(*it == ')')
                    prefixCount--;
                if(prefixCount == -1)
                {
                    s.erase(it--);
                    prefixCount++;
                }
                //cout<<*it;
            }  
            cout<<s<<endl;  
            for(auto jt = s.rbegin(); jt != s.rend(); jt++)
            {
                cout<<*jt;
                if(*jt == ')')
                    suffixCount++;
                else if(*jt == '(')
                    suffixCount--;
                if(suffixCount == -1)
                {
                    s.erase(jt.base());
                    jt == s.rbegin() ? jt--;
                    suffixCount++;
                }
                
            }
            return (s.empty() ? "abc" : s);
        }
};*/

// Changed from for loop because iterator needs to updated only if the element is not deleted.
// In forward iterator, once erase operation is carried out, the elements shift backwards so 
// do not update the iterator forward.
// However in backward iteration, if the element is deleted, then the elements remain where 
// they are, hence we used a for loop in backward iteration so that the iterator is updated 
// no matter what.
// https://stackoverflow.com/questions/14760134/why-does-removing-the-first-element-of-a-list-invalidate-rend/14760316#14760316
class Solution 
{
    public:
        string minRemoveToMakeValid(string s) 
        {
            int prefixCount = 0, suffixCount = 0;
            string::iterator it = s.begin();
            while(it != s.end())
            {
                if(*it == '(')
                    prefixCount++;
                else if(*it == ')')
                    prefixCount--;
                if(prefixCount == -1)
                {
                    s.erase(it);
                    prefixCount++;
                }
                else
                    it++;
            }
            for(string::reverse_iterator jt = s.rbegin(); jt != s.rend(); jt++)
            {
                if(*jt == ')')
                    suffixCount++;
                else if(*jt == '(')
                    suffixCount--;
                if(suffixCount == -1)
                {
                    s.erase((jt+1).base());
                    suffixCount++;
                }
            }
            return s;
        }
};
int main()
{
    string str = "))((";
    Solution solObj;
    cout<<solObj.minRemoveToMakeValid(str)<<endl;
    return 0;
}