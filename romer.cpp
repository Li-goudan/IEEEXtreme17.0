#include<bits/stdc++.h>
using namespace std;

int n;
string s1,s2,sign;
int t,num;
map <string,string> fa;
pair <string, string> p[100005];


string find(string x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}


int main()
{
	scanf("%d",&n);getchar();
	for(int i=0;i<n;i++){
		cin>>s1>>sign>>s2;
		getchar();
		/*
		fa[s1]=s1;
		fa[s2]=s2;*/
		
		
		if(fa[s1]=="") {fa[s1]=s1; }
		if(fa[s2]=="") {fa[s2]=s2; }
		
		
		if(sign[0]=='?'){
			p[++t].first=s1;
			p[t].second=s2;
			
		}else {
			fa[find(s2)]=find(s1);
		}
	/*	map<string ,string>::iterator iter=fa.begin();
		for (iter=fa.begin();iter!=fa.end();iter++)
		cout<<"    "<<iter->first<<" "<<iter->second<<endl;
		//cout<<s1<<"  "<<fa[s1]<<"  "<<s2<<"  "<<fa[s2]<<endl;*/
	}
	int tt=t;
	while(tt--)
	for(int ii=1;ii<=t;ii++){
			
			if(find(p[ii].first)!=p[ii].first) fa[find(p[ii].second)]=find(p[ii].first);
			if(find(p[ii].second)!=p[ii].second) fa[find(p[ii].first)]=find(p[ii].second);
			
	}
	map<string ,string>::iterator iter=fa.begin();
	for (iter=fa.begin();iter!=fa.end();iter++)
		if (iter->first==iter->second) cout<<iter->second<<endl;
	//	cout<<iter->first<<" "<<iter->second<<endl;
	return 0;
}