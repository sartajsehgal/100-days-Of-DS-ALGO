#include <iostream>
#include <queue>
using namespace	std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};

node* buildTree(int preorder[],int inorder[],int s,int e)
{
	//cout<<"hello"<<endl;
	if(s>e)
	{
		return NULL;
	}
	static int i=0;
	node* root=new node(preorder[i]);
	int ind=-1;
	for(int j=s;j<=e;j++)
	{
		if(inorder[j]==preorder[i])
		{
			ind=j;
			break;
		}
	}
	i++;
	root->left=buildTree(preorder,inorder,s,ind-1);
	root->right=buildTree(preorder,inorder,ind+1,e);
	return root;
}

void bfs(node *root)
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
	int preorder[]={1,2,3,4,8,5,6,7};
	int inorder[]={3,2,8,4,1,6,7,5};
	int n=sizeof(preorder)/sizeof(int);
	node* root = buildTree(preorder,inorder,0,n-1);
	bfs(root);
}