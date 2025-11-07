/*
Coded by Diego Cabrera
Codeforces username : GAL1LEO-DC
*/
#include <bits/stdc++.h>
using namespace std; 
 
typedef long long ll;
typedef pair<int, int> pi;  
typedef vector<int> vi;
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ln '\n'
#define yes "YES"
#define no "NO"

template <typename TT>
using min_heap = priority_queue<TT, vector<TT>, greater<TT>>;

const int M = 1e9+7;

char alfabeto_esp[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','#','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
map<char, char> f1, f2, g1, g2;


/*
string desplazamiento_cesar(string s, int k){
    string note = "";
    for(char c : s){
        if(c == ' ') continue;
        int n = f_inv[c];
        n-=k;
        if(n<0){
            n+=27;
        }
        char letter = f[n];
        note.pb(letter);
    }
    return note; 
 
}
*/
int main(){

    string mensaje = "SUMISIONSIDECIDENACEPTARLAESDESCIFRARELMENSAJESECRETOANTESDELAMEDIANOCHEDELDOCEDESEPTIEMBREESTEMENSAJESEAUTODESTRUIRAENCINCOSEGUNDOSCINCOCUATROTRESDOSUNOCEROEXPLOTE";

    
    for(int i = 0; i<27; i++){
        f1[alfabeto_esp[i]] = alfabeto_esp[26-i];
        g1[alfabeto_esp[26-i]] = alfabeto_esp[i];
    }
    for(int i = 0; i+1<27; i++){
        f2[alfabeto_esp[i]] = alfabeto_esp[i+1];
        g2[alfabeto_esp[i+1]] = alfabeto_esp[i];
    }
    f2['Z'] = 'A';
    g2['A'] = 'Z';
    /*
    for(auto [l1, l2] : f2){
        cout<<l1<<" : "<<l2<<ln;
    }
    */
    string mensaje_cifrado = "";
    for(auto c : mensaje){
        char letra_cifrada1 = f1[c], letra_cifrada2 = f2[letra_cifrada1];
        mensaje_cifrado.push_back(letra_cifrada2);
    }
    cout<<mensaje_cifrado<<ln;
    int N = mensaje_cifrado.size();
    for(int i = 0; i<N; i++){
        cout<<mensaje_cifrado[i];
        if(i>0 && i%5 == 0)cout<<" ";
    }

    //Desencriptado (SOLUCION)

    string mensaje_desencriptado = "";

    for(auto c : mensaje_cifrado){
        char letra_descifrada1 = g2[c], letra_descifrada2 = g1[letra_descifrada1];
        mensaje_desencriptado.push_back(letra_descifrada2);
    }
    cout<<"Mensaje descencriptado:"<<ln;
    cout<<mensaje_desencriptado;



    return 0; 
}
