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

int height(node *root)
{
	if(root==NULL)
		return 0;
	return max(height(root->left), height(root->right)) + 1;
}

//This solution is O(N^2)
int diameter(node *root)
{
	if(root==NULL)
		return 0;
	int h1=height(root->left);
	int h2=height(root->right);
	int op1=h1+h2;
	int op2=diameter(root->left);
	int op3=diameter(root->right);
	return max(op1,max(op2,op3));
}

//Optimised O(N) solution
pair<int,int> Optimised_diameter(node *root)
{
	pair<int,int> p;
	if(root==NULL)
	{
		p.first = p.second = 0;
		return p;
	}
	pair<int,int> left = Optimised_diameter(root->left);
	pair<int,int> right = Optimised_diameter(root->right);
	int height = max(left.first, right.first) + 1;
	int diameter = max(left.first+right.first, max(left.second, right.second));
	p.first = height;
	p.second = diameter;
	return p;
}

int main()
{
	node *root = buildTree();
	cout<<"Diameter: "<<diameter(root)<<endl;
	pair<int,int> p = Optimised_diameter(root);
	cout<<"Height: "<<p.first<<"\nDiameter: "<<p.second<<endl;
}