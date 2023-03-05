#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,x,max,temp; max=0;

    x=0;
    temp=0;

    cin >> n;

    int str[n];

    for(int i=0; i<n; i++) {
        cin >> str[i];
    }
    
    for(int i=0; i<n; i+=2) {
        if(str[i] == str[i+2])
        {
            str[i+1] = str[i]+1;
            max+=2;
        } else if(str[i]-str[i+2] == -2) {
            str[i+1] = str[i]+1;
            max+=2;
        } else if(str[i]-str[i+2] == 2) {
            str[i+1] = str[i]-1;
            max+=2;
        } else {
            max++;
            if(str[i-max] == 0 && i-max >= 0) max++ ;
            if(str[i+1] == 0 && i+1 < n) max++;
            if(temp<max) temp=max;
            max=0;
        }
    }
    cout<<temp<<endl;
    
    return 0;
}