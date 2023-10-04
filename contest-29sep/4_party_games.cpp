#include <bits/stdc++.h>
using namespace std;

void fazt(){
    ios::sync_with_stdio(false);    
    cin.tie(nullptr);
    cout.tie(nullptr);
}

string getSTRING(vector<string>& nombres){
    string medio1 = nombres[nombres.size()/2 - 1];
    string medio2 = nombres[nombres.size()/2];
    string resultado = "";
    int k = 0, j = 0;
    if(medio1.size() < medio2.size()){
        do{
            if(medio1[k] == medio2[k] || k+1 == medio1.size()){
                resultado += medio1[k];
            } else {
                resultado += (medio1[k]+1);
                break;
            }
            k++;
        } while (k<medio1.size());
    } 
    else {
        for(k=0; k<medio1.size(); k++){
            if(medio1[k] == medio2[k]){
                resultado += medio1[k];
            } else if(k+1 == medio2.size()) {
                if(k+1 == medio1.size()){
                    resultado += medio1[k]; break;
                }
                if(medio1[k] + 1 != medio2[k]){
                    resultado += (medio1[k]+1); break;
                }
                resultado += medio1[k];
                for (j = k+1; j < medio1.size(); j++) {
                    if (j+1 == medio1.size()){
                        resultado += medio1[j]; continue;
                    }
                    if (medio1[j] != 'Z') {
                        resultado += (medio1[j]+1); break;
                    }
                    resultado += medio1[j];
                }
                break;
            } else {
                resultado += (medio1[k]+1);
                break;
            }
        }
    }
    // cout<<"k="<<k<<"\n";
    return resultado;
}

int main(){
    fazt();
    int n;
    string nombre;
    vector<string> nombres;
    
    while(true){
        cin >> n;
        if(n==0) break;
        
        for(int i=0; i<n; i++){
            cin >> nombre;
            nombres.push_back(nombre);
        }
        sort(nombres.begin(), nombres.end());
        cout<<getSTRING(nombres)<<"\n";
        nombres.clear();
    }

    return 0;
}