#include <iostream>
#include <cmath>

int main()
{
    int t;       // casos de prueba
    long long n; // numero de guerreros en la tropa
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        std::cout << (long long)(std::floor(std::sqrt(2.0 * n + 0.25) + 0.5) - 1) << std::endl;
    }
    return 0;
}
