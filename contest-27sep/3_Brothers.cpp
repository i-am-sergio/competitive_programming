#include <bits/stdc++.h>
using namespace std;

void fazt()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void batalla(vector<vector<int>>& ini, int n,int r, int c){
    vector<vector<int>> res = ini;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(j+1<c){ // 2 0
                if(ini[i][j+1] == ini[i][j]+1 || ini[i][j+1]+n == ini[i][j]+1){ // der
                    res[i][j+1] = ini[i][j];
                }
            }
            if(j-1 >= 0){
                if(ini[i][j-1] == ini[i][j]+1 || ini[i][j-1]+n == ini[i][j]+1){ // izq
                    res[i][j-1] = ini[i][j];
                }
            }
            if(i+1 < r){
                if(ini[i+1][j] == ini[i][j]+1 || ini[i+1][j]+n == ini[i][j]+1){ // abajo
                    res[i+1][j] = ini[i][j];
                }
            }
            if(i-1 >= 0){
                if(ini[i-1][j] == ini[i][j]+1 || ini[i-1][j]+n == ini[i][j]+1){ // arriba
                    res[i-1][j] = ini[i][j];
                }
            }
        }
    }
    ini = res;
}

int main(){
    fazt();
    int n,r,c,k;
    while (true) {
        cin >> n >> r >> c >> k;
        if(n==0 && r==0 && c==0 && k==0) {
            break;
        }
        vector<vector<int>> inicio(r,vector<int>(c));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin >> inicio[i][j];
            }
        }
        for(int i=0; i<k; i++){
            batalla(inicio,n,r,c);
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cout<<inicio[i][j];
                if(j!=c-1)
                    cout<<" ";
            }
            cout<<"\n";
        }
    }
    
    return 0;
}