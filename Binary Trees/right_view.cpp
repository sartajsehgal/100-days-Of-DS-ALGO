#include <iostream>
#include <queue>
using namespace std;

//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

class node {
public:
	int data;
	node *left;
	node *right;
	node(int d)
	{
		data = d;
		left = right = NULL;
	}
};

node* buildTree()
{
	int d;
	cin>>d;
	if(d==-1)
	{
		return NULL;
	}
	node *root=new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void bfs(node *root)
{
	queue<node *> q;
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
			{
				q.push(temp->left);
			}
			if(temp->right)
			{
				q.push(temp->right);
			}
		}
	}
}

void right_view(node *root,int level)
{
	if(root==NULL)
	{
		return;
	}
	static int max=-1;
	if(level>max)
	{
		cout<<root->data<<endl;
		max=level;
	}
	right_view(root->right,level+1);
	right_view(root->left,level+1);
	return;
}

int main()
{
	node *root = buildTree();
	bfs(root);
	cout<<endl;
	right_view(root,0);
}