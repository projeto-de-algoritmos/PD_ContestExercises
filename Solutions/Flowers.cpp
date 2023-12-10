#include <bits/stdc++.h>
using namespace std;
#define maxsize 100001
#define mod 1000000007

long long int dp[maxsize];
long long int pre[maxsize];
int k; 

int contarCombinacoes(int n){
    if(n == 0) 
        return 1; 

    if(dp[n] != -1)
        return dp[n];

    int combinacoes = 0;

    //flor branca
    if(n >= k)
        combinacoes += contarCombinacoes(n - k), combinacoes = combinacoes % mod;

    //flor vermelha
    combinacoes += contarCombinacoes(n - 1), combinacoes = combinacoes % mod;

    return dp[n] = combinacoes;
}

void init(){
    for(int i = 1; i < maxsize; i++)
        dp[i] = -1;

    for(int i = 1; i < maxsize; i++){
        pre[i] = pre[i - 1] + contarCombinacoes(i), pre[i] = pre[i] % mod;
    }
}

int main() {
    int t; 
    cin >> t >> k;

    init();
    while(t--){
        int a, b;
        cin >> a >> b;
        
        int soma = (pre[b] - pre[a - 1] + mod) % mod;
        cout << soma << endl;
    }
}