// UVA 11321
#include <bits/stdc++.h>
using namespace std;

void fazt(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

struct Number {
    int num;
    int modulo;
    Number(){}

    Number(int num, int modulo){
        this->num = num;
        this->modulo = modulo;
    }
};

/*
1 Empate entre impar y par : impar sobre par
2 Empate entre impar y impar : impar mayor sobre impar menor
3 Empate entre par y par : par menor sobre par mayor
*/
bool esPar(const Number& a){
    return (a.num%2==0)? true : false; 
}

bool comparador1 (const Number& num1, const Number& num2){
    return (num1.modulo < num2.modulo);
}

bool comparador2 (const Number& num1, const Number& num2){
    if(!esPar(num1) && esPar(num2)) {
        if(num1.modulo == num2.modulo){
            return true;
        }
    }
    else if(esPar(num1) && !esPar(num2)) {
        if(num1.modulo == num2.modulo){
            return false;
        }
    }
    if(!esPar(num1) && !esPar(num2)){
        if(num1.modulo == num2.modulo){
            return (num2.num < num1.num);
        }
    }
    else if(esPar(num1) && esPar(num2)){
        if(num1.modulo == num2.modulo){
            return (num1.num < num2.num);
        }
    } 
    return (num1.modulo < num2.modulo) ? true : false;
}

int main(){
    fazt();
    vector<Number> numbers;
    int n, m, num;

    while(true)
    {
        cin >> n >> m;
        cout<<n<<" "<<m<<"\n";
        if(n==0) {
            break;
        }

        for(int k=0; k<n; k++){
            cin>>num;
            numbers.push_back({num, num % m});
        }

        sort(numbers.begin(), numbers.end(),comparador2);
        
        for(int i=0; i<n; i++){
            cout<<numbers[i].num<<"\n";
            // cout<<numbers[i].num<<" - modulo -> "<<numbers[i].modulo<<"\n";
        }
        numbers.clear();
    }
    

    return 0;
}