// UVA 12709
#include <bits/stdc++.h>
using namespace std;

void fazt(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    fazt();
    int n, L, W, H;
    vector<int> Ls;
    vector<int> Ws;
    vector<int> Hs;
    vector<int> volumenes;
    vector<double> aceleraciones;
    vector<int> empates;
    int mayorVolumen;
    double mayorAceleracion;
    int aux;

    while(true){
        mayorVolumen = 0;
        mayorAceleracion = 0;
        cin>>n;
        if(n==0) break;
        
        for(int i=0; i<n; i++) {
            cin >> L >> W >> H;
            Ls.emplace_back(L);
            Ws.emplace_back(W);
            Hs.emplace_back(H);
            volumenes.emplace_back(L*W*H);
            aceleraciones.emplace_back(10 - ((double) 10 / (2*H)));
            
        }
        
        mayorAceleracion = aceleraciones[0];
        for(int k=0; k<aceleraciones.size(); k++){
            if(aceleraciones[k] >= mayorAceleracion){
                mayorAceleracion = aceleraciones[k];
            }
        }
        for(int k=0; k<aceleraciones.size(); k++){
            if(aceleraciones[k] == mayorAceleracion){
                if(volumenes[k] > mayorVolumen){
                    mayorVolumen = volumenes[k];
                }
            }
        }
        
        cout<<mayorVolumen<<"\n";
        Ls.clear();
        Ws.clear();
        Hs.clear();
        volumenes.clear();
        aceleraciones.clear();
        empates.clear();

        // for(int i=0; i<n; i++){
        //     cout<<Ls[i]<<"-"<<Ws[i]<<"-"<<Hs[i]<<"\n";
        // }
    }

    return 0;
}