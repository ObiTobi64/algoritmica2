#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

// el numero maximo sera 10^18
// 1000000000000000000
string number;
int dp[20][2][20];

/* 
* Crear una funcion para verificar si un numero es primo
*
*/ 
bool isPrime(int n) {   
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}


/* 
* Digit DP para contar los numeros 
* donde la suma de los digitos sea un numero primo 
*/ 
int solve_dp(int pos, int mayor,int total) {
    if(pos > number.size()) { // cuando la posicion exceda al numero dado
        return 0;
    }
    // Modificar de acuerdo al problema
    if(pos == number.size()) {
        if(pares == 2) { // tiene 2 pares el numero 
            return 1;
        }
        else {
            return 0;
        }
    }
    dp[pos][mayor][total] = 0;
    if(dp[pos][mayor][pares] == -1) { // Pregunto si no lo he calculado 
        int tope = 9;
        if(mayor == true) {  // el numero que voy a crear puede llegar a ser mayor
            tope = number[pos]-'0';  // solo podemos usar los numeros de 0 al tope -- '3'-'0' =  51 - 48 = 3 
        }
        for(int digito = 0; digito <= tope; digito++) {
            if(digito == tope ) {
                dp[pos][mayor][pares] += solve_dp(pos+1, true, digito+total);
            }
            else { // 0 1 2 
                dp[pos][mayor][pares] += solve_dp(pos+1, false, digito+total);
            }
        }
    }
    return dp[pos][mayor][pares];
}



int main(){

    // hallar los numeros que tengan 2 pares en su interior del rango 20 hasta 30

    int  a = 20;
    int b = 30;
    // calculando f(a)
    number = to_string(a-1);
    memset(dp, -1, sizeof(dp));
    int pares_hasta_a = solve_dp(0, true, 0);
    // calculando f(b)
    memset(dp, -1, sizeof(dp));
    number = to_string(b);
    int pares_hasta_b = solve_dp(0, true, 0);
    // total para f(a,b) = f(b) - f(a-1)
    cout<< pares_hasta_b - pares_hasta_a;
    return 0;
}