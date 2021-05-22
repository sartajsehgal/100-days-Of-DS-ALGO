#include <bits/stdc++.h>
using namespace std;

struct ques
{
	int qno;
	int max_score;
	int sub_parts;
	float ratio;
};

bool compare(ques q1,ques q2)
{
	if(q1.sub_parts!=q2.sub_parts)
	{
		return q1.sub_parts>q2.sub_parts;
	}
	else
	{
		return q1.ratio<q2.ratio;
	}
}

vector<int> ans(int std,ques qn[],int min_marks)
{
	int i=0;
	vector<int> a;
	while(std<min_marks)
	{
		std+=qn[i].max_score;
		a.push_back(qn[i].qno);
		i++;
	}
	sort(a.begin(),a.end());
	a.insert(a.begin(),i);
	return a;
}

int main()
{
	int min_marks,s,n;
	cin>>min_marks>>s>>n;
	int std[s];
	struct ques qn[n];
	for(int i=0;i<s;i++)
	{
		cin>>std[i];
	}
	for(int i=0;i<n;i++)
	{
		qn[i].qno=i+1;
		cin>>qn[i].max_score>>qn[i].sub_parts;
		qn[i].ratio=((float)qn[i].max_score/qn[i].sub_parts);
	}
	sort(qn,qn+n,compare);
	for(int i=0;i<s;i++)
	{
		vector<int> a=ans(std[i],qn,min_marks);
		for(auto i=a.begin();i!=a.end();++i)
		{
			cout<<*i<<" ";
		}
		cout<<endl;
	}
}