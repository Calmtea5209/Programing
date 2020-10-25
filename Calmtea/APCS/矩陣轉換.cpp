#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r,c,m;
    cin >>r>>c>>m;
    bool p=0;
    int la[r][c];
    int lb[c][r];
    int lm[m];
    for(int i=0;i<r;i++){
        for(int k=0;k<c;k++){
            cin >>la[i][k];
        }
    }
    for(int i=0;i<m;i++){
        cin >>lm[i];
    }
    for(int i=m-1;i>=0;i--){
        if(lm[i]==0){   //旋轉
            if(p==0){
                for(int k=0;k<c;k++){
                    for(int j=0;j<r;j++){
                        lb[c-1-k][j]=la[j][k];
                    }
                }
            }
            else{
                for(int k=0;k<r;k++){
                    for(int j=0;j<c;j++){
                        la[r-1-k][j]=lb[j][k];
                    }
                }

            }
            p=1-p;
        }
        else{   //翻轉
            if(p==0){
                for(int k=0;k<r/2;k++){
                    for(int j=0;j<c;j++){
                        swap(la[r-1-k][j],la[k][j]);
                    }
                }
            }
            else{
                for(int k=0;k<c/2;k++){
                    for(int j=0;j<r;j++){
                        swap(lb[c-1-k][j],lb[k][j]);
                    }
                }
            }

        }
    }
    if(p==0){
        for(int i=0;i<r;i++){
            for(int k=0;k<c;k++){
                cout <<la[i][k];
                if(k!=c-1)
                    cout <<" ";
                else
                    cout <<endl;
            }
        }
    }
    else{
        for(int i=0;i<c;i++){
            for(int k=0;k<r;k++){
                cout <<lb[i][k];
                if(k!=r-1)
                    cout <<" ";
                else
                    cout <<endl;
            }
        }
    }

    return 0;
}
