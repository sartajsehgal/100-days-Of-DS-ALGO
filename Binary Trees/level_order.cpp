#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
		int data;
		node *left;
		node *right;

		node(int d)
		{
			data = d;
			left=NULL;
			right=NULL;
		}
};

node* buildTree()
{
	int data;
	cin>>data;
	if(data==-1)
	{
		return NULL;
	}
	node *root = new node(data);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

int calculate_height(node *root)
{
	if(root==NULL)
		return 0;
	return max(calculate_height(root->left),calculate_height(root->right))+1;
}

void printKthLevel(node *root,int k)
{
	if(root==NULL)
		return;
	if(k==1)
	{
		cout<<root->data<<" ";
	}
	printKthLevel(root->left,k-1);
	printKthLevel(root->right,k-1);
}

void printAllLevels(node *root)
{
	int H=calculate_height(root);
	for(int i=1;i<=H;i++)
	{
		printKthLevel(root,i);
		cout<<endl;
	}
}

int main()
{
	node *root=buildTree();
	printAllLevels(root);
}