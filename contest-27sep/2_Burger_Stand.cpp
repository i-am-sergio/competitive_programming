#include <bits/stdc++.h>
using namespace std;

void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int count(vector<int> &opciones)
{
    int contador = 0;
    for (int i = 0; i < opciones.size(); i++)
    {
        if (opciones[i] == 1)
            contador++;
    }
    return contador;
}

int examinar(string &linea)
{
    int n = linea.size();
    vector<int> opciones(n, 1);
    for (int i = 0; i < n; i++)
    {
        if (linea[i] == 'D')
        {
            opciones[i] = 0;
        }
        if (linea[i] == 'B')
        {
            opciones[i] = 0;
        }
        if (i + 1 < n && linea[i + 1] == 'B')
        {
            opciones[i] = 0;
        }
        if (i + 2 < n && linea[i + 2] == 'B')
        {
            opciones[i] = 0;
        }
        if (linea[i] == 'S')
        {
            opciones[i] = 0;
        }
        if (i + 1 < n && linea[i + 1] == 'S')
        {
            opciones[i] = 0;
        }
        if (i - 1 >= 0 && linea[i - 1] == 'S')
        {
            opciones[i] = 0;
        }
    }
    return count(opciones);
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