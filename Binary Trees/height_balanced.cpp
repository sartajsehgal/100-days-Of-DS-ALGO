#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

class node{
public:	
	int data;
	node *left;
	node *right;
	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

node * buildTree()
{
	int d;
	cin >> d;
	if(d==-1)
		return NULL;
	node *root=new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

pair<int,bool> isBalanced(node *root)
{
	pair<int,bool> p;
	if(root==NULL)
	{
		p.first = 0;
		p.second = true;
		return p;
	}
	pair<int,bool> left=isBalanced(root->left);
	pair<int,bool> right=isBalanced(root->right);
	p.first = max(left.first,right.first)+1;
	if(abs(left.first-right.first)<=1 && left.second && right.second)
	{
		p.second = true;
	}
	else
	{
		p.second = false;
	}
	return p;
}

node* buildBalancedTree(int arr[],int s,int e)
{
	int mid=(s+e)/2;
	if(s>e)
	{
		return NULL;
	}
	node* root=new node(arr[mid]);
	root->left=buildBalancedTree(arr,s,mid-1);
	root->right=buildBalancedTree(arr,mid+1,e);
	return root;
}

void bfs(node *root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node *temp=q.front();
		q.pop();
		if(temp==NULL)
		{
			cout<<endl;
			if(!q.empty())
				q.push(NULL);
		}
		else
		{
			cout<<temp->data<<" ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
}

int main()
{
	// node *root = buildTree();
	// pair<int,bool> p=isBalanced(root);
	// if(p.second)
	// {
	// 	cout<<"Tree is balanced\n";
	// }
	// else
	// {
	// 	cout<<"Tree is not balanced\n";
	// }
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int s=0,e=sizeof(arr)/sizeof(arr[0])-1;
	node* root=buildBalancedTree(arr,s,e);
	bfs(root);
	pair<int,bool> p=isBalanced(root);
	if(p.second)
	{
		cout<<"Tree is balanced\n";
	}
	else
	{
		cout<<"Tree is not balanced\n";
	}
}