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

void pairBFS(node *root)
{
	queue<pair<node*,int>> q;
	q.push(make_pair(root,0));
	int prev=0;
	while(!q.empty())
	{
		pair<node*,int> p=q.front();
		q.pop();
		if(p.second!=prev)
		{
			cout<<endl;
			prev=p.second;
		}
		cout<<p.first->data<<" ";
		if(p.first->left)
			q.push(make_pair(p.first->left,p.second+1));
		if(p.first->right)
			q.push(make_pair(p.first->right,p.second+1));
	}
}

int main()
{
	node *root = buildTree();
	bfs(root);
	cout<<endl;
	pairBFS(root);
}