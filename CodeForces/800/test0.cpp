#include <iostream>
#include <vector>
using namespace std;

int determinant(vector<vector<int>>& A, int n) {
    if (n == 1) { // Caso base: matriz de 1x1
        return A[0][0];
    }
    
    int det = 0; // Inicializar el determinante
    
    for (int i = 0; i < n; i++) {
        vector<vector<int>> B(n - 1, vector<int>(n - 1)); // Crear la matriz B
        
        // Llenar la matriz B eliminando la columna i y la fila 0
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (k < i) {
                    B[j - 1][k] = A[j][k];
                } else if (k > i) {
                    B[j - 1][k - 1] = A[j][k];
                }
            }
        }
        
        // Calcular el cofactor y el determinante recursivamente
        int cofactor = (i % 2 == 0) ? A[0][i] : -A[0][i];
        det += cofactor * determinant(B, n - 1);
    }
    
    return det;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }     
    }

    int det = determinant(A, n);
    cout << det << endl; 
    return 0;
}