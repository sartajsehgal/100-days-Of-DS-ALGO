#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class node {
public:
	int data;
	node *right;
	node *left;
	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

node *insert(node *root,int val)
{
	if(root == NULL)
	{
		node *temp=new node(val);
		return temp;
	}
	if(val<=root->data)
	{
		root->left=insert(root->left,val);
	}
	else
	{
		root->right=insert(root->right,val);
	}
	return root;
}

node* buildTree()
{
	int d;
	cin>>d;
	node *root=NULL;
	while(d!=-1)
	{
		root=insert(root,d);
		cin>>d;
	}
	return root;
}

bool isBST(node *root,int minV = INT_MIN, int maxV = INT_MAX)
{
	if(root==NULL)
		return true;
	if(root->data>=minV and root->data<=maxV and isBST(root->left,minV,root->data) and isBST(root->right,root->data,maxV))
		return true;
	return false;
}

void inorder(node * root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void bfs(node* root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node *temp = q.front();
		q.pop();
		if(temp==NULL)
		{
			cout<<endl;
			if(!q.empty())
			{
				q.push(NULL);
			}
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
	node *root = buildTree();
	inorder(root);
	cout<<endl;
	bfs(root);
	cout<<endl;
	if(isBST(root))
		cout<<"Yes it is a BST\n";
	else
		cout<<"No it is not a BST\n";
	return 0;
}