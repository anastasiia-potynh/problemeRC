// criptare.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool este_prim(int nr) {
    if (nr < 2) return false;
    for (int div = 2; div * div <= nr; div++) {
        if (nr % div == 0)
            return false;
    }
    return true;
}

//yA/yB(rezultatul) = a (radacina primitiva) la putere xA/xB mod q
int calcul_cheie(int a, int x, int q) {
    int y = 1;
    for (int i = 1; i <= x; i++) {
        y = (y * a) % q;
    }
    return y;
}

int radacina_primitiva(int q) {
    for (int nr = 2; nr < q; nr++) {
        bool este_rad_prim = true;

        for (int putere = 1; putere < q; putere++) {
            if (calcul_cheie(nr, putere, q) == 1 && putere != q - 1) {  
                este_rad_prim = false;
                break;
            }
        }

        if (este_rad_prim)
            return nr;
    }
    return -1;
}


string cifru_cezar(string text, int cheia) {
    string rezultat = "";
    for (char c : text) {
        if (c >= 'A' && c <= 'Z') {  
            rezultat += (c - 'A' + cheia) % 26 + 'A';
        }
        else if (c >= 'a' && c <= 'z') {  
            rezultat += (c - 'a' + cheia) % 26 + 'a';
        }
        else { 
            rezultat += c;
        }
    }
    return rezultat;
}

int main() {
    int q;   
    int a;   
    int x_A, x_B;   
    int y_A, y_B;   
    int k_A, k_B;   

    cout << "Introduceti un numar prim q: ";
    cin >> q;

    if (!este_prim(q)) {
        cout << q << " nu este prim, introdu un numar prim \n";
        return 1;
    }

    a = radacina_primitiva(q);
    if (a == -1) {
        cout << "Nu exista radacina primitiva pentru " << q << "\n";
        return 1;
    }

    cout << "Radacina primitiva a lui " << q << " este " << a << endl;

   
    cout << "Introdu cheia privata x_A: ";
    cin >> x_A;
    cout << "Introdu cheia privata x_B: ";
    cin >> x_B;

   
    y_A = calcul_cheie(a, x_A, q);
    y_B = calcul_cheie(a, x_B, q);

    cout << "Cheia publica y_A: " << y_A << endl;
    cout << "Cheia publica y_B: " << y_B << endl;

   
    k_A = calcul_cheie(y_B, x_A, q);
    k_B = calcul_cheie(y_A, x_B, q);

    cout << "Cheia secreta k_A: " << k_A << endl;
    cout << "Cheia secreta k_B: " << k_B << endl;

    if (k_A == k_B)
        cout << "Cheia obtinuta este: " << k_A << endl;
    else
        cout << "Cheile nu coincid!" << endl;

    // cheia de criptare = cheia de la diffie-hellman
    
    string mesaj;
    cout << "Introdu mesajul initial: ";
   
    cin >> mesaj;

   
    string criptat = cifru_cezar(mesaj, k_A);
    cout << "Mesaj criptat : " << criptat << endl;

    return 0;
}


    