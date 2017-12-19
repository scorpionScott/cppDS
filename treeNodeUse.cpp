#include<iostream>
#include"treeNode.h"
#include<queue>
using namespace std;

treeNode<int>* takeInput()
{
    int rootData;
    cout<<"Please enter rootData";
    cin>>rootData;
    treeNode<int>* root=new treeNode<int>(rootData);
    int numChild;
    cout<<"Please enter the number of children for the root";
    cin>>numChild;
    for(int i=0;i<numChild;i++)
    {
        root->children.push_back(takeInput());
    }
    return root;
}

void printTree(treeNode<int>* root)
{
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {
        printTree(root->children.at(i));
    }
}

treeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Please enter root data:";
    cin>>rootData;
    treeNode<int>* root=new treeNode<int>(rootData);
    queue<treeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        treeNode<int>* next=pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Please enter the number of children for "<<next->data<<"th node:";
        cin>>numChild;
        int child;
        for(int i=0;i<numChild;i++){
                cout<<"Please enter the value of "<<i<<"th child of"<<next->data<<":";
            cin>>child;
            treeNode<int>* childNode=new treeNode<int>(child);
            next->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
    }
    return root;
}

void printTreeLevelWise(treeNode<int>* root)
{
    queue<treeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        treeNode<int>* next=pendingNodes.front();
        pendingNodes.pop();
        cout<<next->data<<":";
        for(int i=0;i<next->children.size();i++)
        {
            cout<<next->children.at(i)->data<<" ";
            pendingNodes.push(next->children.at(i));
        }
        cout<<endl;
    }
}

int countNodes(treeNode<int>* root)
{
    int count=0;
    for(int i=0;i<root->children.size();i++)
    {
        count+=countNodes(root->children.at(i));
    }
    
    return count+1;
}

int sumNodes(treeNode<int>* root)
{
    int sum=0;
    for(int i=0;i<root->children.size();i++)
    {
        sum+=sumNodes(root->children.at(i));
    }
    
    return sum+root->data;
}

treeNode<int>* maxNodeFind(treeNode<int>* root)
{
    treeNode<int>* maxNode=root;
    treeNode<int>* compare;
    for(int i=0;i<root->children.size();i++)
    {
        compare=maxNodeFind(root->children.at(i));
        if(compare->data>maxNode->data)
        {
            maxNode=compare;
        }
    }
    
    return maxNode;
}

int heightTree(treeNode<int>* root)
{
    int height=0;
    for(int i=0;i<root->children.size();i++)
    {
        int compare=heightTree(root->children.at(i));
        if(compare>height)
        {
            height=compare;
        }
    }
    
    return height+1;
}

void preOrder(treeNode<int>* root)
{
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {
        preOrder(root->children.at(i));
        
    }
}
//1 3 2 3 4 2 5 6 3 7 8 9 2 10 11 0 0 0 0 0 0 0
int main() 
{
    treeNode<int>* root=takeInputLevelWise();
    //printTreeLevelWise(root);
    preOrder(root);
}
