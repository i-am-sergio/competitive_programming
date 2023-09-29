#include <bits/stdc++.h>
using namespace std; 

void fast(){
    ios::sync_with_stdio(false);    
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fast();
    long x;
    vector<long> integers;
    long numMedio1, numMedio2, mediana, pos;

    while(cin >> x)
    {
        integers.emplace_back(x);
        std::sort(integers.begin(), integers.end());
        
        if(integers.size() % 2 != 0){ // si es impar
            pos = integers.size() / 2;
            mediana = integers[pos];
            cout << mediana << "\n";
            continue;
        } else { // si es par media de numeros del medio
            numMedio1 = integers[integers.size() / 2];
            numMedio2 = integers[(integers.size() / 2) - 1];
            mediana = (numMedio1 + numMedio2) / 2;
            cout << mediana << "\n";
        }
    }
    return 0;
}