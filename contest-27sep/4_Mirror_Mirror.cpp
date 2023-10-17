// UVA 0466
#include <bits/stdc++.h>
using namespace std;

void fazt()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


string getEstado2(vector<string> & A, vector<string> & B) {
    int n = A.size();
    bool _90 = true, _180= true, _270 = true;
    bool vertically = true, preserv = true;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(A[i][j] != B[i][j]) {
                preserv = false;
            }
            if(A[i][j] != B[j][n-i-1]) {
                _90 = false;
            }
            if(A[i][j] != B[n-i-1][n-j-1]) {
                _180 = false;
            }
            if(A[i][j] != B[n-j-1][i]) {
                _270 = false;
            }
            if(A[i][j] != B[n-i-1][j]) {
                vertically = false;
            }
        }
    }
    
    if(preserv){    // Preserved
        return "preserved";
    }
    else if(_90){ // 90 rotation     // Only Rotations
        return "rotated 90 degrees";
    } 
    else if (_180) { // 180 rotation
        return "rotated 180 degrees";
    } 
    else if (_270) { // 270 rotation
        return "rotated 270 degrees";
    }
    else if(vertically) {
        return "reflected vertically";
    }
    else { // combinations
        int n = A.size();
        vector<string> C(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                C[i][j] = A[n-i-1][j];  
            }
        }
        _90 = _180 = _270 = true;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(C[i][j] != B[j][n-i-1]){
                    _90 = false;
                }
                if(C[i][j] != B[n-i-1][n-j-1]){
                    _180 = false;
                }
                if(C[i][j] != B[n-j-1][i]){
                    _270 = false;
                }
            }
        }
        if(_90){
            return "reflected vertically and rotated 90 degrees";
        } else if(_180){
            return "reflected vertically and rotated 180 degrees";
        } else if(_270){
            return "reflected vertically and rotated 270 degrees";
        }
    }
    return "improperly transformed";
}



int main(){
    // fazt();
    int dimension;
    string izq, der;
    

    int contador = 1;
    while(cin>>dimension) {
        vector<string> A;
        vector<string> B;
        for(int k=1; k<=dimension; k++){
            cin>>izq>>der;
            A.emplace_back(izq);
            B.emplace_back(der);
            
        }
        cout << "Pattern " << contador << " was " << getEstado2(A, B) << ".\n";
        
        A.clear();
        B.clear();
        contador++;
    }

    return 0;
}


bool verticalReflection(vector<string> & A, vector<string> & B){
    int n = A.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j] != B[n-i-1][j]){
                return false;
            }        
        }
    }
    return true;
}
bool rotated90(vector<string> & A, vector<string> & B){
    int n = A.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j] != B[j][n-i-1]){
                return false;
            }        
        }
    }
    return true;
}
bool rotated180(vector<string> & A, vector<string> & B){
    int n = A.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j] != B[n-i-1][n-j-1]){
                return false;
            }        
        }
    }
    return true;
}
bool rotated270(vector<string> & A, vector<string> & B){
    int n = A.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j] != B[n-j-1][i]){
                return false;
            }        
        }
    }
    return true;  
}
bool verticalReflectionAnd90(vector<string> & A, vector<string> & B){
    int n = A.size();
    vector<string> C(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            C[i][j] = A[n-i-1][j];  
        }
    }
    return (rotated90(C,B));
}
bool verticalReflectionAnd270(vector<string> & A, vector<string> & B){
    int n = A.size();
    vector<string> C(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            C[i][j] = A[n-i-1][j];  
        }
    }
    return (rotated270(C,B));
}
bool verticalReflectionAnd180(vector<string> & A, vector<string> & B){
    int n = A.size();
    vector<string> C(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            C[i][j] = A[n-i-1][j];  
        }
    }
    return (rotated180(C,B));
}
string getEstado(vector<string> & A, vector<string> & B){
    string result = "";
    
    if(equal(A.begin(),A.end(), B.begin())){    // Preserved
        return "preserved";
    }
    else if(rotated90(A,B)){ // 90 rotation     // Only Rotations
        return "rotated 90 degrees";
    } 
    else if (rotated180(A,B)) { // 180 rotation
        return "rotated 180 degrees";
    } 
    else if (rotated270(A,B)) { // 270 rotation
        return "rotated 270 degrees";
    }
    else if(verticalReflection(A,B)) {
        return "reflected vertically";
    }
    else { // combinations
        int n = A.size();
        vector<string> C(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                C[i][j] = A[n-i-1][j];  
            }
        }
        if(rotated90(C,B)){
            return "reflected vertically and rotated 90 degrees";
        } else if(rotated180(C,B)){
            return "reflected vertically and rotated 180 degrees";
        } else if(rotated270(C,B)){
            return "reflected vertically and rotated 270 degrees";
        }

    }
    return "improperly transformed";
}