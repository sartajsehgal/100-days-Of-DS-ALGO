#include <iostream>
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
			left=NULL;
			right=NULL;
		}
};

node* buildTree()
{
	int data;
	cin>>data;
	if(data==-1)
	{
		return NULL;
	}
	node *root = new node(data);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void Preorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(node *root)
{
	if(root==NULL)
		return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

void Postorder(node *root)
{
	if(root==NULL)
		return;
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->data<<" ";
}

int main()
{
	node *root=buildTree();
	Preorder(root);
	cout<<endl;
	Inorder(root);
	cout<<endl;
	Postorder(root);
}