/*
133. Clone Graph
https://leetcode.com/problems/clone-graph/
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;    

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution 
{
    public:
        Node* cloneGraph(Node* node) 
        {
            Node *tempNode = node, *tempNode1 = node;
            int counter, flag = 1, k;
            //cout<<"Checkpoint 2\n";
            for(counter = 1; flag != 0; counter++, tempNode++)
                if(tempNode->val != counter)
                //{cout<<tempNode->val<<" "<<counter<<endl;
                    flag = 0;
                /*else
                    cout<<tempNode->val<<" "<<counter<<endl;*/
            //for(int i = 1; i)
            cout<<node[0].val<<" ";
            cout<<"Checkpoint 3\n";
            Node *newNode = new Node[counter];
            for(int i = 1; i < counter; i++)
            {
                newNode[i].val = i;
                //cout<<newNode[i].val<<" "<<i<<"----->";
                for(auto it = tempNode1[i-1].neighbors.begin(); it != tempNode1[i-1].neighbors.end(); it++)
                {
                    //cout<<"Hi ";
                    /*if(tempNode1[4].val == 4)
                        cout<<"Working here\n";*/
                    k = (*it)->val;
                    cout<<k<<" ";
                    newNode[i].neighbors.push_back(&newNode[k]);
                }
                cout<<endl;
            }
            return &newNode[1];
        }
};

int main()
{
    Node *node = new Node[5];
    for(int i = 1; i < 5; i++)
        node[i].val = i;
    cout<<node[1].val<<" "<<node[2].val<<" "<<node[3].val<<" "<<node[4].val<<endl;
    node[1].neighbors.push_back(&node[2]);
    node[1].neighbors.push_back(&node[4]);
    node[2].neighbors.push_back(&node[1]);
    node[2].neighbors.push_back(&node[3]);
    node[3].neighbors.push_back(&node[2]);
    node[3].neighbors.push_back(&node[4]);
    node[4].neighbors.push_back(&node[1]);
    node[4].neighbors.push_back(&node[3]);
    for(int i = 1; i < 5; i++)
    {
        cout<<node[i].val<<"----> ";
        for(auto it = node[i].neighbors.begin(); it != node[i].neighbors.end(); it++)
            cout<<(*it)->val<<" ";
        cout<<endl;
    }

    Solution solObj;
    Node *finalAnswer = solObj.cloneGraph(&node[1]);
    cout<<"Checkpoint 1\n";
    for(int i = 0; i < 5; i++)
    {
        cout<<finalAnswer[i].val<<"----> ";
        for(auto it = finalAnswer[i].neighbors.begin(); it != finalAnswer[i].neighbors.end(); it++)
            cout<<(*it)->val<<" ";
        cout<<endl;
    }

    return 0;
    /*Node *node = new Node[2];
    Node *tempNode;
    node[0].val = 1;
    node[1].val = 100;
    node[0].neighbors.push_back(&node[1]);
    cout<<node[0].val<<" "<<node[1].val<<endl;
    cout<<&node[1]<<endl;
    for(int i = 0; i < node[0].neighbors.size(); i++)
    {
        tempNode = node[0].neighbors[i];
        cout<<tempNode->val<<endl;
        cout<<(node[0].neighbors[i])->val<<endl;
    }
    return 0;*/
}