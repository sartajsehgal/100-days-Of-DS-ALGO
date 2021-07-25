#include <iostream>
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

void mirror(node *root)
{
    if(root==NULL)
        return;
    node *temp=root->left;
    root->left=root->right;
    root->right=temp;
    mirror(root->left);
    mirror(root->right);
    return;
}

void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
	node *root=buildTree();
	inorder(root);
	cout<<endl;
	mirror(root);
	inorder(root);
	return 0;
}