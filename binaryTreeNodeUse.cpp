#include<bits/stdc++.h>
#include"binaryTreeNode.h"
#include"printTree.cpp"
using namespace std;

binaryTreeNode<int>* buildTree(int *preorder, int preLenght, int *inorder, int inLength) {
    // Write your code here
  	if(preLenght<=0 || inLength<=0)
    {
      return NULL;
    }
  
  	binaryTreeNode<int>* root=new binaryTreeNode<int>(preorder[0]);
  	int i=0;
  	for(;i<inLength;i++)
    {
      if(inorder[i]==preorder[0])
      {
        break;
      }
    }

  	root->left=buildTree(preorder+1,i,inorder,i);
  	root->right=buildTree(preorder+i+1,preLenght-i-1,inorder+i+1,inLength-i-1);
	return root;
}

binaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
  	if(postLength<=0 || inLength<=0)
    {
      return NULL;
    }
  
  	binaryTreeNode<int>* root=new binaryTreeNode<int>(postorder[postLength-1]);
  	int i=0;
  	for(;i<inLength;i++)
    {
      if(inorder[i]==root->data)
      {
        break;
      }
    }
  	
  	root->left=getTreeFromPostorderAndInorder(postorder,i,inorder,i);
  	root->right=getTreeFromPostorderAndInorder(postorder+i,postLength-i-1,inorder+i+1,inLength-i-1);
	return root;
}


binaryTreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Please enter root data:";
    cin>>rootData;
    binaryTreeNode<int>* root=new binaryTreeNode<int>(rootData);
    queue<binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        binaryTreeNode<int>* next=pendingNodes.front();
        pendingNodes.pop();
        int leftChild,rightChild;
        cout<<"Enter left child of "<<next->data<<":";
        cin>>leftChild;
        if(leftChild!=-1)
        {
            binaryTreeNode<int>* node=new binaryTreeNode<int>(leftChild);
            next->left=node;
            pendingNodes.push(node);
        }
        cout<<"Enter right child of "<<next->data<<":";
        cin>>rightChild;
        if(rightChild!=-1)
        {
            binaryTreeNode<int>* node=new binaryTreeNode<int>(rightChild);
            next->right=node;
            pendingNodes.push(node);
        }
    }
    
    return root;
}

void printBTLevelWise(binaryTreeNode<int>* root)
{
    queue<binaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty())
    {
        binaryTreeNode<int>* next=pendingNodes.front();
        pendingNodes.pop();
        cout<<next->data<<":";
        if(next->left!=NULL)
        {
            cout<<"LC:"<<next->left->data<<" ";
            pendingNodes.push(next->left);
        }
        
        if(next->right!=NULL)
        {
            cout<<"RC:"<<next->right->data<<" ";
            pendingNodes.push(next->right);
        }
        cout<<endl;
        
    }
}

int countNodes(binaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    
    return countNodes(root->left)+countNodes(root->right)+1;
}
int heightBT(binaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    
    int height=0;
    int compare=0;
    compare=heightBT(root->left);
    if(compare>height)
        height=compare;
    compare=heightBT(root->right);
    if(compare>height)
        height=compare;
    return height+1;
}

binaryTreeNode<int>* mirror(binaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return root;
    }
    
    binaryTreeNode<int>* temp=root->left;
    root->left=root->right;
    root->right=temp;
    root->left=mirror(root->left);
    root->right=mirror(root->right);
    
    return root;
}

void mirrorBinaryTree(binaryTreeNode<int>* root) {
    if(root==NULL)
    {
      return;
    }
  
  	binaryTreeNode<int>* temp=root->left;
  	root->left=root->right;
  	root->right=temp;
  	
  	mirrorBinaryTree(root->left);
  	mirrorBinaryTree(root->right);
}

int diameter(binaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    
    int option1=heightBT(root->left)+heightBT(root->right);
    int option2=diameter(root->left);
    int option3=diameter(root->right);
    
    return max(option1,max(option2,option3));
}

class output{
public:
    int height;
    int diameter;
    
    output()
    {
     height=0;
     diameter=0;
    }
};

output diameterAlt(binaryTreeNode<int>* root)
{
    output ans;
    if(root==NULL)
    {
        ans.height=0;
        ans.diameter=0;
        return ans;
    }
    output leftD=diameterAlt(root->left);
    output rightD=diameterAlt(root->right);
    ans.height=max(leftD.height,rightD.height)+1;
    int option1=leftD.height+rightD.height;
    int option2=leftD.diameter;
    int option3=rightD.diameter;
    
    ans.diameter=max(option1,max(option2,option3));
    
    return ans;
}

int depthBT(binaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return -1;
    }
    
    return 1+max(depthBT(root->left),depthBT(root->right));
}

bool isBalanced(binaryTreeNode<int> *root) {
    
	if(root==NULL)
    {
      return true;
    }
  	int rightDepth=depthBT(root->right);
  	int leftDepth=depthBT(root->left);
  	if(rightDepth-leftDepth<=1 && rightDepth-leftDepth>-1)
    {
      return (isBalanced(root->left) && isBalanced(root->right));
    }
  
  	else if(leftDepth-rightDepth<=1 && leftDepth-rightDepth>-1)
      return (isBalanced(root->left) && isBalanced(root->right));
  
  	else return false;
}

int main()
{
    binaryTreeNode<int>* root=takeInputLevelWise();
    postorder(root);//printBTLevelWise(mirror(root));
}
