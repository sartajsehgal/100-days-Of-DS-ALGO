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

node* delete_node(node *root,int val)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(val<root->data)
	{
		root->left = delete_node(root->left,val);
		return root;
	}
	else if(val==root->data)
	{
		//3 cases possible
		//1. leaf node
		if(root->left==NULL and root->right==NULL)
		{
			delete root;
			return NULL;
		}
		//2. one child
		if(root->right==NULL and root->left!=NULL)
		{
			node *temp=root->left;
			delete root;
			return temp;
		}
		else if(root->left==NULL and root->right!=NULL)
		{
			node *temp=root->right;
			delete root;
			return temp;
		}
		//3. Two children
		if(root->left!=NULL and root->right !=NULL)
		{
			//we have to chose the inorder successor of root
			node *inorder_succ=root->right;
			while(inorder_succ->left!=NULL)
			{
				inorder_succ=inorder_succ->left;
			}
			root->data=inorder_succ->data;
			root->right=delete_node(root->right,inorder_succ->data);
			return root;
		}
	}
	else
	{
		root->right = delete_node(root->right,val);
		return root;
	}
	return root;
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
	node *del=delete_node(root,7);
	cout<<endl;
	inorder(root);
	cout<<endl;
	bfs(root);
}