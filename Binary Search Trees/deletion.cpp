#include <iostream>
#include <queue>
using namespace std;

class node {
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

node* insert(node* root,int val)
{
	if(root == NULL)
	{
		node *temp = new node(val);
		return temp;
	}
	if(val <= root->data)
	{
		root->left = insert(root->left,val);
	}
	else
	{
		root->right = insert(root->right,val);
	}
	return root;
}

node* buildTree()
{
	int d;
	cin >> d;
	node *root = NULL;
	while(d!=-1)
	{
		root=insert(root,d);
		cin >> d;
	}
	return root;
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
	bfs(root);
}