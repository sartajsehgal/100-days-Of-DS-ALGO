#include <bits/stdc++.h>
using namespace std;

void merge(vector<vector<int>> &arr,int sm,int m,int sn,int n)
{
	int nm=(sm+m)/2;
	int nn=(sn+n)/2;
	
	vector<vector<int>> p1(nm-sm+1,vector<int>(nn-sn+1,0));
	vector<vector<int>> p2(nm-sm+1,vector<int>(n-nn,0));
	vector<vector<int>> p3(m-nm,vector<int>(nn-sn+1,0));
	vector<vector<int>> p4(m-nm,vector<int>(n-nn,0));

	for(int i=0;i<=nm-sm;i++)
	{
		for(int j=0;j<=nn-sn;j++)
		{
			p1[i][j] = arr[sm + i][sn + j];
		}
	}
	
	for(int i=0;i<=nm-sm;i++)
	{
		for(int j=0;j<=n-nn-1;j++)
		{
			p2[i][j] = arr[sm + i][nn + j + 1];
		}
	}
	
	for(int i=0;i<=m-nm-1;i++)
	{
		for(int j=0;j<=nn-sn;j++)
		{
			p3[i][j] = arr[nm + i + 1][sn + j];
		}
	}

	for(int i=0;i<=m-nm-1;i++)
	{
		for(int j=0;j<=n-nn-1;j++)
		{
			p4[i][j] = arr[nm + i + 1][nn + j + 1];
		}
	}
	
	int i1=0,j1=0;
	int i2=0,j2=0;
    int mi=sm,mj=sn;

    for(int i=sm;i<=nm;i++)
    {
    	while(j1<=nn-sn && j2<=n-nn-1)
    	{
    		if(p1[i1][j1]<=p2[i2][j2])
    		{
    			arr[mi][mj]=p1[i1][j1];
    			j1++;
    			mj++;
    		}
    		else
    		{
    			arr[mi][mj]=p2[i2][j2];
    			j2++;
    			mj++;
    		}
    	}
    	while(j1<=nn-sn)
    	{
    		arr[mi][mj]=p1[i1][j1];
    		j1++;
    		mj++;
    	}
    	while(j2<=n-nn-1)
    	{
    		arr[mi][mj]=p2[i2][j2];
    		j2++;
    		mj++;
    	}
    	mi++;
    	j1=0;j2=0;mj=0;i1++;i2++;
    }

    int i3=0,j3=0;
	int i4=0,j4=0;
    mi=nm+1;mj=sn;

    for(int i=nm+1;i<=m;i++)
    {
    	while(j3<=nn-sn && j4<=n-nn-1)
    	{
    		if(p3[i3][j3]<=p4[i4][j4])
    		{
    			arr[mi][mj]=p3[i3][j3];
    			j3++;
    			mj++;
    		}
    		else
    		{
    			arr[mi][mj]=p4[i4][j4];
    			j4++;
    			mj++;
    		}
    	}
    	while(j3<=nn-sn)
    	{
    		arr[mi][mj]=p3[i3][j3];
    		j3++;
    		mj++;
    	}
    	while(j4<=n-nn-1)
    	{
    		arr[mi][mj]=p4[i4][j4];
    		j4++;
    		mj++;
    	}
    	mi++;
    	j3=0;j4=0;mj=sn;i3++;i4++;
    }

    vector<vector<int>> matrix(arr);

    int x=sm,y=sn;
    int x1=sm,x2=nm+1;
    for(int j=sn;j<=n;j++)
    {
    	while(x1<=nm && x2<=m)
    	{
    		if(matrix[x1][j]<=matrix[x2][j])
    		{
    			arr[x][y]=matrix[x1][j];
    			x1++;x++;
    		}
    		else
    		{
    			arr[x][y]=matrix[x2][j];
    			x2++;x++;
    		}
    	}
    	while(x1<=nm)
    	{
    		arr[x][y]=matrix[x1][j];
    		x1++;x++;
    	}
    	while(x2<=m)
    	{
    		arr[x][y]=matrix[x2][j];
    		x2++;x++;
    	}
    	x1=sm;x2=nm+1;
    	y++;
    	x=sm;
    }

    // for(int i=sm;i<=m;i++)
    // {
    // 	for(int j=sn;j<=n;j++)
    // 	{
    // 		cout<<arr[i][j]<<" ";
    // 	}
    // 	cout<<endl;
    // }
    // cout<<endl;

}

void merge_sort(vector<vector<int>> &arr,int sm,int m,int sn,int n)
{
	if(sm<m || sn<n)
	{
		int nm=(sm+m)/2;
		int nn=(sn+n)/2;

		merge_sort(arr,sm,nm,sn,nn);
		merge_sort(arr,sm,nm,nn+1,n);
		merge_sort(arr,nm+1,m,sn,nn);
		merge_sort(arr,nm+1,m,nn+1,n);

		merge(arr,sm,m,sn,n);
	}
}

int main()
{
	int m,n;
	cin>>m>>n;
	vector<vector<int>> arr(m,vector<int>(n,0));
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	merge_sort(arr,0,m-1,0,n-1);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}