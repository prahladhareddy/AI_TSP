#include <bits/stdc++.h>
using namespace std;

float f(){
    return (float) rand()/1000.0;
}

int main(){
    int n;
    cin>>n;
    cout<< "euclidean\n";
    cout<<n<<"\n";
    for(int i=0 ;i<n;i++){
        cout<<f()<<" "<<f()<<"\n";
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<f()<<" ";
        }
        cout<<"\n";
    }
}