#include<iostream>
using namespace std;
int main(){
    
    
    int n,m;
    cin>>n>>m;
    cout<<1<<" "<<(n/2+n%2)*(m/2+m%2)<<endl;
    int output[1005][1005]={0};
    int output2[1005][1005]={0};
    int cnt=1;
    int cntt=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            output2[i][j]=cntt;
            cntt++;
        }
    }

    for(int i=1;i<=n;i++){
        
        for(int j=1;j<=m;j++){
            
            cout<<output2[i][j]<<" ";
            
            
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i=i+2){
        
        for(int j=1;j<=m;j=j+2){
            if(j+1<=m){
            output[i][j+1]=cnt;
                cnt++;
            }
            if(i+1<=n){
            output[i+1][j]=cnt;
            cnt++;
                
            }
            if(i+1<=n && j+1<=n){
                output[i+1][j+1]=cnt;
                cnt++;
                
            }
            output[i][j]=cnt;
            cnt++;

        }
        
        
    }
    
    
    for(int i=1;i<=n;i++){
        
        for(int j=1;j<=m;j++){
            
            cout<<output[i][j]<<" ";
            
            
        }
        cout<<endl;
    }
    
    return 0;
}