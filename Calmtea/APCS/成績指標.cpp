#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin >>n){
        int s=-1,b=-1;
        int l[n];
        for(int i=0;i<n;i++){
            cin >>l[i];
        }
        for(int i=0;i<n-1;i++){
            for(int k=n-1;k>i;k--){
                if(l[k]<l[k-1]){
                    swap(l[k],l[k-1]);
                }
            }
        }
        for(int i=0;i<n;i++){
            cout <<l[i]<<" ";
        }
        cout <<endl;
        for(int i=0;i<n;i++){
            if(l[i]<60){
                s=l[i];
            }
            if(l[n-1-i]>=60){
                b=l[n-1-i];
            }
        }
        if(s!=-1)
            cout <<s<<endl;
        else
            cout <<"best case"<<endl;
        if(b!=-1)
            cout <<b<<endl;
        else
            cout <<"worst case"<<endl;
    }

    return 0;
}



