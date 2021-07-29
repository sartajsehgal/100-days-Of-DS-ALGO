#include <iostream>
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

node* buildTree()
{
	int d;
	cin >> d;
	if(d==-1) return NULL;
	node *root=new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

node* lca(node* root,int a,int b)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data==a or root->data==b)
	{
		return root;
	}
	node *left=lca(root->left,a,b);
	node *right=lca(root->right,a,b);
	if(left!=NULL and right!=NULL)
	{
		return root;
	}
	if(left!=NULL)
		return left;
	return right;
}

int main()
{
	node *root = buildTree();
	cout<<"For values 6 and 9: "<<lca(root,6,9)->data<<endl;
	cout<<"For values 2 and 9: "<<lca(root,2,9)->data<<endl;
	cout<<"For values 5 and 9: "<<lca(root,5,9)->data<<endl;
	cout<<"For values 3 and 10: "<<lca(root,3,10)->data<<endl;
}