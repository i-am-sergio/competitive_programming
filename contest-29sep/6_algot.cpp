#include <bits/stdc++.h>
using namespace std; 

void fast(){
    ios::sync_with_stdio(false);    
    cin.tie(nullptr);
    cout.tie(nullptr);
}
long long inversion = 0;

void Merge(vector<int> & A, int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;
    int* L = new int[n1];
    int* R = new int[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = A[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[medio + 1 + j];

    int i = 0, j = 0, k = inicio;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
            inversion = inversion + n1 - i;
        }
        k++;
    }
    
    while (i < n1) { // Copia los elementos restantes del L
        A[k] = L[i];
        i++; k++;
    }
    
    while (j < n2) { // Copia los elementos restantes del R
        A[k] = R[j];
        j++; k++;
    }
    
    delete[] L;
    delete[] R;
}


void MergeSort(vector<int>& A, int p, int r){// A, principio, fin
    if(p < r){
        int q = (p + r) / 2; // Dividimos por la mitad
        MergeSort(A, p, q);
        MergeSort(A, q+1, r);
        Merge(A,p,q,r); // Mezcla las partes ordenadas
    }
}

void printVector(vector<int>& A, int size)
{
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
}


int main(){
    fast();
    vector<int> A;
    int n, num;
    while(true){
        cin>>n;
        if(n==0) break;
        for(int i=0; i<n; i++){
            cin>>num;
            A.emplace_back(num);
        }
        inversion = 0;
        MergeSort(A,0,n-1);
        cout<<inversion<<"\n";
        A.clear();
    }

    return 0;
}