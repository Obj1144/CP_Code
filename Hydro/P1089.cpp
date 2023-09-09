#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int cot=0;
    int pos=-1;
    for(int l=0,r=s.length()-1;l<=r;l++,r--){
        if(s[l]!=s[r]){
            if(pos==-1) pos=l;
            if(s[l]>s[r]) s[l]=s[r];
            else s[r]=s[l];
            cot++;
        }
    }
    if(cot==2) ;
    else if(cot==1){
        for(int l=0,r=s.length()-1;l<=r;l++,r--){
            if(s[l]!='a'&&l==pos){
                s[l]=s[r]='a';
                break;
            }
            else if(l==r){
                s[l]='a';
                break;
            }
        }
    }
    else{
        for(int l=0,r=s.length()-1;l<=r;l++,r--){
            if(s[l]!='a'){
                s[l]=s[r]='a';
                break;
            }
        }
    }
    cout<<s<<"\n";
}