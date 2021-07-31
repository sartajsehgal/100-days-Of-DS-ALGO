#include <iostream>
#include <queue>
using namespace std;

class node {
public:
	int data;
	node* right;
	node* left;
	node(int d)
	{
		data = d;
		left = right = NULL;
	}
};

node* insert(node* root,int val)
{
	if(root == NULL)
		return new node(val);
	if(val<=root->data)
		root->left = insert(root->left,val);
	else
		root->right = insert(root->right,val);
	return root;
}

node* buildTree()
{
	int d;
	cin>>d;
	node* root = NULL;
	while(d!=-1)
	{
		root = insert(root,d);
		cin>>d;
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

class LinkedList {
	public:
		node *head;
		node *tail;
};

LinkedList convert_to_ll(node *root)
{
	LinkedList l;
	if(root == NULL)
	{
		l.head = l.tail = NULL;
		return l;
	}
	if(root->left == NULL and root->right ==NULL)
	{
		l.head = l.tail = root;
		return l;
	}
	if(root->left != NULL and root->right == NULL)
	{
		LinkedList lLeft = convert_to_ll(root->left);
		lLeft.tail->right = root;
		l.head = lLeft.head;
		l.tail = root;
	}
	if(root->left == NULL and root->right != NULL)
	{
		LinkedList lRight = convert_to_ll(root->right);
		root->right = lRight.head;
		l.head = root;
		l.tail = lRight.tail;
	}
	if(root->left != NULL and root->right != NULL)
	{
		LinkedList lLeft = convert_to_ll(root->left);
		LinkedList lRight = convert_to_ll(root->right);
		lLeft.tail->right = root;
		root->right = lRight.head;
		l.head = lLeft.head;
		l.tail = lRight.tail;
	}
	return l;
}

int main()
{
	node *root = buildTree();
	inorder(root);
	cout<<endl;
	bfs(root);
	cout<<endl;
	LinkedList l = convert_to_ll(root);
	node *temp = l.head;
	while(temp != NULL)
	{
		cout<<temp->data<<"-->";
		temp = temp->right;
	}
	return 0;
}