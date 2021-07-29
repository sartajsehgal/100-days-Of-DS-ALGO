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

int calculate_height(node* root,int key,int level)
{
	if(root==NULL)
		return -1;
	if(root->data==key)
		return level;
	int left=calculate_height(root->left,key,level+1);
	if(left!=-1)
		return left;
	int right=calculate_height(root->right,key,level+1);
	return right;
}

int distance_bw_two_nodes(node *root,int a,int b)
{
	node *lca_node=lca(root,a,b);
	int h1=calculate_height(lca_node,a,0);
	int h2=calculate_height(lca_node,b,0);
	return h1+h2;
}

int main()
{
	node *root = buildTree();
	cout<<"For values 6 and 9: "<<distance_bw_two_nodes(root,6,9)<<endl;
	cout<<"For values 2 and 9: "<<distance_bw_two_nodes(root,2,9)<<endl;
	cout<<"For values 5 and 9: "<<distance_bw_two_nodes(root,5,9)<<endl;
	cout<<"For values 3 and 10: "<<distance_bw_two_nodes(root,3,10)<<endl;
}