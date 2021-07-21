#include <iostream>
#include <queue>
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
			left = NULL;
			right = NULL;
		}
};

node* buildTree()
{
	int d;
	cin >> d;

	if(d==-1)
	{
		return NULL;
	}
	node *root=new node(d);
	root->left=buildTree();
	root->right=buildTree();
	return root;
}

void bfs(node *root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node *temp=q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
}

int main()
{
	node *root = buildTree();
	bfs(root);
}