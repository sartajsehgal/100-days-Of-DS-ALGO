#include<iostream>
#include<queue>
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

// int sum(node *root)
// {
// 	if(root==NULL)
// 	{
// 		return 0;
// 	}
// 	int v1=sum(root->left);
// 	int v2=sum(root->right);
// 	if(v1!=0 || v2!=0)
// 		return v1+v2+root->data;
// 	return root->data;
// }

int  replace(node *root)
{
	/*if(root==NULL)
	{
		return;
	}
	int s=sum(root);
	if(s!=root->data)
		root->data=s-root->data;
	else
		root->data=s;
	replace(root->left);
	replace(root->right);*/
	if(root==NULL)
	{
		return 0;
	}
	if(root->left==NULL && root->right==NULL)
	{
		return root->data;
	}
	int leftSum=replace(root->left);
	int rightSum=replace(root->right);
	int temp=root->data;
	root->data=leftSum+rightSum;
	return leftSum+rightSum+temp;
}

int main()
{
	node *root = buildTree();
	cout<<"Before Replacing node with sum of its all children and grand children\n";
	bfs(root);
	int a = replace(root);
	cout<<"After Replacing node with sum of its all children and grand children\n";
	bfs(root);
}