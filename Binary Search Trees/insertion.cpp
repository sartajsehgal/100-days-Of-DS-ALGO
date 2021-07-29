#include <iostream>
#include <queue>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int d)
	{
		data = d;
		left = right = NULL;
	}
};

node* insert(node* root,int d)
{
	if(root == NULL)
	{
		node* temp = new node(d);
		return temp;
	}
	if(d<=root->data)
	{
		root->left=insert(root->left,d);
	}
	else
	{
		root->right=insert(root->right,d);
	}
	return root;
}

node*  buildTree()
{
	int d;
	cin >> d;

	node* root = NULL;

	while(d!=-1)
	{
		root = insert(root,d);
		cin>>d;
	}
	return root;
}

bool search(node* root,int val)
{
	if(root == NULL)
	{
		return false;
	}
	if(root->data==val)
	{
		return true;
	}
	if(val<=root->data)
	{
		return search(root->left,val);
	}
	return search(root->right,val);
}

void inorder(node* root)
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
	node* root=buildTree();
	inorder(root);
	cout<<endl;
	bfs(root);
	cout<<endl;
	bool isPresent=search(root,10);
	if(isPresent)
	{
		cout<<"Value Found"<<endl;
	}
	else
	{
		cout<<"Value Not Found"<<endl;
	}
}