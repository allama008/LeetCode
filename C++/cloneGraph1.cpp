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
            Node *tmpnode = node;

            Node *tempNode = node, *tempNode1 = node, *tempNode2 = node;
            int counter, flag = 1, k;
            for(counter = 0; flag != 0; counter++, tempNode++)
                if(tempNode->val != counter+1)
                    flag = 0;

            Node *newNode = new Node[counter];
            for(int i = 1; i < counter; i++, tempNode1++)
                newNode[i].val = tempNode1->val;

            for(int i = 1; i < counter; i++, tempNode2++)
                for(auto it = tempNode2->neighbors.begin(); it != tempNode2->neighbors.end(); it++)
                    newNode[i].neighbors.push_back(&newNode[(*it)->val]);
            return &newNode[1];
        }
};

int main()
{
    Node *node = new Node[2];
    /*for(int i = 1; i < 5; i++)
        node[i].val = i;
    //cout<<node[1].val<<" "<<node[2].val<<" "<<node[3].val<<" "<<node[4].val<<endl;
    node[1].neighbors.push_back(&node[2]);
    node[1].neighbors.push_back(&node[4]);
    node[2].neighbors.push_back(&node[1]);
    node[2].neighbors.push_back(&node[3]);
    node[3].neighbors.push_back(&node[2]);
    node[3].neighbors.push_back(&node[4]);
    node[4].neighbors.push_back(&node[1]);
    node[4].neighbors.push_back(&node[3]);
    /*for(int i = 1; i < 5; i++)
    {
        cout<<node[i].val<<"----> ";
        for(auto it = node[i].neighbors.begin(); it != node[i].neighbors.end(); it++)
            cout<<(*it)->val<<" ";
        cout<<endl;
    }*/

    node[1].val = 1;

    Solution solObj;
    Node *finalAnswer = solObj.cloneGraph(&node[1]);
    cout<<"Checkpoint 1\n";
    for(int i = 0; i < 1; i++, finalAnswer++)
    {
        cout<<finalAnswer->val<<"----> ";
        for(auto it = finalAnswer->neighbors.begin(); it != finalAnswer->neighbors.end(); it++)
            cout<<(*it)->val<<" ";
        cout<<endl;
    }

    return 0;
}