// UVA 13048
#include <bits/stdc++.h>
using namespace std;

void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int examinar(string &linea)
{
    int n = linea.size();
    int contador = 0;
    for (int i = 0; i < n; i++)
    {
        if (linea[i] == 'D')
        {
            contador++;
        }
        else if (linea[i] == 'B')
        {
            contador++;
        }
        else if (i + 1 < n && linea[i + 1] == 'B')
        {
            contador++;
        }
        else if (i + 2 < n && linea[i + 2] == 'B')
        {
            contador++;
        }
        else if (linea[i] == 'S')
        {
            contador++;
        }
        else if (i + 1 < n && linea[i + 1] == 'S')
        {
            contador++;
        }
        else if (i - 1 >= 0 && linea[i - 1] == 'S')
        {
            contador++;
        }
    }
    return ((n - contador) < 0) ? 0 : n - contador;
}

int main()
{
    fast();
    int T, numEspaciosPosib = 0;
    cin >> T;
    string linea;
    for (int i = 1; i <= T; i++)
    {
        std::cin >> linea;
        numEspaciosPosib = examinar(linea);
        cout << "Case " << i << ": " << numEspaciosPosib << "\n";
    }
    return 0;
}