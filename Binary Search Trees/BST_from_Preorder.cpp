#include <iostream>
#include <queue>
#include <algorithm>
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

node* makeTreeFromPreorder(int preorder[],int inorder[],int s,int e)
{   
	if(s>e)
		return NULL;
	static int i=0;
	node *root = new node(preorder[i]);
	int idx=-1;
	for(int j=s;j<=e;j++)
	{
		if(preorder[i]==inorder[j])
		{
			idx=j;
			break;
		}
	}
	i++;
	root->left = makeTreeFromPreorder(preorder,inorder,s,idx-1);
	root->right = makeTreeFromPreorder(preorder,inorder,idx+1,e);
	return root;
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
	int preorder[6]={5,3,1,7,6,8};
	int inorder[6];
	for(int i=0;i<6;i++)
	{
		inorder[i]=preorder[i];
	}
	sort(inorder,inorder+6);
	node *root = makeTreeFromPreorder(preorder,inorder,0,5);
	bfs(root);
}