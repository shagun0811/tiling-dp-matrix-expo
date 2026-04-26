#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1e9+7;

vector<vector<ll>> multiply(vector<vector<ll>> &A, vector<vector<ll>> &B) {
    vector<vector<ll>> C(3, vector<ll>(3, 0));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % MOD;
            }
        }
    }
    return C;
}

vector<vector<ll>> power(vector<vector<ll>> M, ll n) {
    vector<vector<ll>> result = {{1,0,0},{0,1,0},{0,0,1}}; // Identity
    while(n){
        if(n & 1) result = multiply(result, M);
        M = multiply(M, M);
        n >>= 1;
    }
    return result;
}

ll solve(ll n) {
    if(n == 0) return 1;
    if(n == 1) return 1;
    if(n == 2) return 2;

    vector<vector<ll>> M = {
        {2,0,1},
        {1,0,0},
        {0,1,0}
    };

    auto Mn = power(M, n-2);

    ll f2 = 2, f1 = 1, f0 = 1;

    ll fn = (Mn[0][0]*f2 + Mn[0][1]*f1 + Mn[0][2]*f0) % MOD;
    return fn;
}

int main(){
    ll n;
    cin >> n;
    cout << solve(n) << endl;
}