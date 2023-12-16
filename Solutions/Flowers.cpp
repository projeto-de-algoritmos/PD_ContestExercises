#include <bits/stdc++.h>
using namespace std;
#define maxsize 100001
#define mod 1000000007

vector<long long> visitados(maxsize, -1);  
vector<long long> memoization(maxsize); 
int k; 

int contarCombinacoes(int n){
    if(n == 0) 
        return 1; 

    if(visitados[n] != -1)
        return visitados[n];
    
    int combinacoes = 0;

    //flor branca
    if(n >= k)
        combinacoes += contarCombinacoes(n - k), combinacoes = combinacoes % mod;
        
    //flor vermelha
    combinacoes += contarCombinacoes(n - 1), combinacoes = combinacoes % mod;

    return visitados[n] = combinacoes;
}

int main() {
    int t; 
    cin >> t >> k;
    
    //precomputar as combinacoes
    for(int i = 1; i < maxsize; i++)
        memoization[i] = memoization[i - 1] + contarCombinacoes(i), memoization[i] = memoization[i] % mod;
    
    while(t--){
        int a, b;
        cin >> a >> b;
        
        int soma = (memoization[b] - memoization[a - 1] + mod) % mod;
        cout << soma << endl;
    }
}