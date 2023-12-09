#include <bits/stdc++.h>
using namespace std; 
#define maxsize 100001

int main () {
    int n; 
    cin >> n; 

    int maiorElemento = -1; 

    vector<long long> frequencia(maxsize, 0); 
    for(int i = 0; i < n; i++){
        int x; 
        cin >> x; 
        frequencia[x]++; 
        maiorElemento = max(maiorElemento, x); 
    }

    vector<long long> partida(maxsize, 0); 
    partida[0] = 0; 
    partida[1] = frequencia[1]; 

    for(long long i = 2; i < maxsize; i++){
        //ou escolho o elemento anterior ou escolho o penultimo elemento + o elemento atual
        partida[i] = max(partida[i - 1], partida[i - 2] + frequencia[i] * i);
    }

    cout << partida[maiorElemento] << endl; 
    return 0; 
}