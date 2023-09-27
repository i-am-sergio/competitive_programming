#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, R, C, K;
    while (cin >> N >> R >> C >> K)
    {
        if (N + R + C + K == 0)
            break;
        vector<vector<int>> G[2];
        G[0].resize(R, vector<int>(C));
        G[1].resize(R, vector<int>(C));
        int i, j, k;
        for (i = 0; i < R; i++)
            for (j = 0; j < C; j++)
                cin >> G[0][i][j];
        int bandera = 1;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        while (K--)
        {
            for (i = 0; i < R; i++)
            {
                for (j = 0; j < C; j++)
                {
                    G[bandera][i][j] = G[1 - bandera][i][j];
                    int x = G[1 - bandera][i][j] - 1;
                    if (x < 0)
                        x += N;
                }
            }
            bandera = 1 - bandera;
        }
        bandera = 1 - bandera;
        for (i = 0; i < R; i++, cout << endl)
        {
            for (j = 0; j < C; j++)
            {
                if (j)
                    cout << ' ';
                cout << G[bandera][i][j];
            }
        }
    }
    return 0;
}
