#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1,s2;
int pmt[1000005];
void get_pmt(const string& s){
    for(int i=1,j=0;i<s.length();i++){
        while(j&&s[i]!=s[j]) j=pmt[j-1];
        if(s[i]==s[j]) j++;
        pmt[i]=j;
    }
}
void kmp(const string& a,const string& b){
    for(int i=0,j=0;i<a.length();i++){
        while(j&&a[i]!=b[j]) j=pmt[j-1];
        if(a[i]==b[j]) j++;
        if(j==b.length()){
            cout<<i-j+2<<"\n";
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s1>>s2;
    get_pmt(s2);
    kmp(s1,s2);
    for(int i=0;i<s2.length();i++){
        cout<<pmt[i]<<" ";
    }
    cout<<"\n";
    return 0;
}