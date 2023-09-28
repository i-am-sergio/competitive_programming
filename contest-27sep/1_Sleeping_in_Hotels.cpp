#include <iostream>
#include <string>
using namespace std;

void fast()
{
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie(NULL);
}

int masCercanoIzq(string &linea, int pos)
{
    int contadorIzq = 0;
    int i = pos - 1;
    while (i >= 0)
    {
        if (linea[i] == 'X')
            break;
        i--;
        contadorIzq++;
    }
    return contadorIzq;
}

int masCercanoDer(string &linea, int pos)
{
    int contadorDer = 0;
    int i = pos + 1;
    while (i < linea.size())
    {
        if (linea[i] == 'X')
            break;
        i++;
        contadorDer++;
    }
    return contadorDer;
}

int masCercano(string &linea, int &pos)
{
    int distancia;
    if (pos == 0)
    {
        return masCercanoDer(linea, pos);
    }
    else if (pos == linea.size() - 1)
    {
        return masCercanoIzq(linea, pos);
    }

    int izq = masCercanoIzq(linea, pos);
    int der = masCercanoDer(linea, pos);
    return (izq <= der) ? izq : der;
}

int main()
{
    fast();
    std::string linea;
    int solucionMax = 0;
    int solucionTemp = 0;

    while (cin >> linea)
    {
        for (int i = 0; i < linea.size(); i++)
        {
            if (linea[i] != 'X')
                solucionTemp = masCercano(linea, i);

            if (solucionTemp > solucionMax)
                solucionMax = solucionTemp;
            // cout << "solucionTemp -> " << solucionTemp << "\n";
            // cout << "solucionMax -> " << solucionMax << "\n";
        }

        cout << solucionMax << endl;
        solucionMax = 0;
        solucionTemp = 0;
    }

    return 0;
}
