#include <bits/stdc++.h>
using namespace std; 

vector<string> personNames;
vector<int> dds;
vector<int> mms;
vector<int> yyyys;

void fast(){
    ios::sync_with_stdio(false);    
    cin.tie(nullptr);
    cout.tie(nullptr);
}

string masJoven(){
    vector<int> posiciones;
    vector<int> temp;
    int n = personNames.size();
    auto maximo = max_element(yyyys.begin(), yyyys.end());
    for (int i=0; i<n; i++){ // yyyy
        if(*maximo == yyyys[i]){
            posiciones.emplace_back(i);
            temp.emplace_back(mms[i]);
        }
    }
    if(posiciones.size()==1) 
        return personNames[posiciones[0]];
    else {
        maximo = max_element(temp.begin(), temp.end());
        posiciones.clear();
        temp.clear();
        for (int i=0; i<n; i++){ // mm
            if(*maximo == mms[i]){
                posiciones.emplace_back(i);
                temp.emplace_back(dds[i]);
            }
        }
        if(posiciones.size()==1) 
            return personNames[posiciones[0]];
        else {
            maximo = max_element(temp.begin(), temp.end());
            posiciones.clear();
            temp.clear();
            for (int i=0; i<n; i++){ // mm
                if(*maximo == dds[i]){
                    return personNames[i];
                }
            }
        }
    }
    return "";
}

string masViejo(){
    vector<int> posiciones;
    vector<int> temp;
    int n = personNames.size();
    auto minimo = min_element(yyyys.begin(), yyyys.end());
    for (int i=0; i<n; i++){ // yyyy
        if(*minimo == yyyys[i]){
            posiciones.emplace_back(i);
            temp.emplace_back(mms[i]);
        }
    }
    if(posiciones.size()==1) 
        return personNames[posiciones[0]];
    else {
        minimo = min_element(temp.begin(), temp.end());
        posiciones.clear();
        temp.clear();
        for (int i=0; i<n; i++){ // mm
            if(*minimo == mms[i]){
                posiciones.emplace_back(i);
                temp.emplace_back(dds[i]);
            }
        }
        if(posiciones.size()==1) 
            return personNames[posiciones[0]];
        else {
            minimo = min_element(temp.begin(), temp.end());
            posiciones.clear();
            temp.clear();
            for (int i=0; i<n; i++){ // mm
                if(*minimo == dds[i]){
                    return personNames[i];
                }
            }
        }
    }
    return "";
}

int main(){
    // fast();
    // vector<string> temp;
    int n;
    cin>>n;
    string personName; 
    int dd, mm, yyyy;
    for(int i=1; i<=n; i++){
        // personName dd mm yyyy
        cin>>personName>>dd>>mm>>yyyy;
        // temp = {personName, dd,mm,yyyy};
        personNames.emplace_back(personName);
        dds.emplace_back(dd);
        mms.emplace_back(mm);
        yyyys.emplace_back(yyyy);
    }

    // for (int i=0; i<personNames.size(); i++){
    //     cout<<personNames[i]<<"-"<<dds[i]<<"-"<<mms[i]<<"-"<<yyyys[i]<<"\n";
    // }
    cout<<masJoven()<<"\n";
    cout<<masViejo()<<"\n";

    return 0;
}
