#include<set>
#include<map>
#include<cctype>
#include<string>
#include<cstring>
#include<iostream>

using namespace std;

int n,m;
string* ns=nullptr;
string* ms=nullptr;
void tolower(string& s){
    for(auto& x:s){
        x=tolower(x);
    }
    return;
}

int main(void){
    cin>>n>>m;
    ns=new string[n];
    ms=new string[m];
    cin.get();
    for(int i=0; i<n; ++i)
        getline(cin,ns[i]);
    cin.get();
    for(int i=0; i<m; ++i)
        getline(cin,ms[i]);

    for(int i=0; i<m; ++i){
        ms[i]=ms[i].substr(ms[i].find_last_of(' ')+1);
    tolower(ms[i]);
    }
    
    set<string>* ps=new set<string>[n];
    for(int i=0; i<n; ++i){
        int od=0,d=0;

        while(true ){
            d=ns[i]. find(' ' ,od);
            if(d==-1)
                break;
            ps[i]. insert(ns[i]. substr(od,d-od));
            od=d+1;
        }
            ps[i]. insert(ns[i].substr(od));
    }
    int index[101];
    memset(index, ~0, sizeof(index));
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j)
            if(ps[j].find(ms[i])!=ps[j]. end())
                index[i]=j;
    }
    int index_count[101];
    memset(index_count, 0, sizeof(index_count));
    char out[101];
    memset(out ,~0, sizeof(out));
    for(int i=0; i<m; ++i){
        if(index[i]^~0) 
            ++index_count[index[i]];
    }
    char q='A';
    for(int i=0; i<m; ++i){
        if(index[i]==~0 || index_count[index[i]]<=1)
            cout<<'X' ;
        else{
            if(out[index[i]]==~0){
                out[index[i]]=q++;
                if(q=='X')
                    ++q;
            }
        cout<<out [ index[i]];
        }
    }

    delete []ps;
    delete []ns;
    delete []ms;
    return 0;
}
