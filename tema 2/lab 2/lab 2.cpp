// lab 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nr_biti;
    cout << "Introduceti numarul de biti:" << endl;
    cin >> nr_biti;

    if (nr_biti % 7 != 0) {
        cout << "Greseala" << endl;
        return 0;
    }
    else {
        cout << "Introduceti mesajul initial :" << endl;
    }

    
    vector<int> mesaj_initial(nr_biti);
    for (int i = 0; i < nr_biti; i++) {
        cin >> mesaj_initial[i];
    }

    
    int nr_linii = nr_biti / 7; 
    int nr_col = 7;

    
    vector<vector<int>> matrice(nr_linii, vector<int>(nr_col, 0));

    int contor = 0;
    // asez bitii in matrice
    for (int i = 0; i < nr_linii; ++i) {
        for (int j = 0; j < nr_col; ++j) {
            if (contor < nr_biti) {
                matrice[i][j] = mesaj_initial[contor++];
            }
            else {
                matrice[i][j] = 0;
            }
        }
    }

    // coloana
    
    for (int i = 0; i < nr_linii; ++i) {
        int suma_pe_linie = 0;
        for (int j = 0; j < nr_col; ++j) {
            suma_pe_linie += matrice[i][j];
        }

        if (suma_pe_linie % 2 == 0) {
            matrice[i].push_back(0);  
        }
        else {
            matrice[i].push_back(1);  
        }
    }

    // linia 
    vector<int> linie_supl(nr_col + 1, 0);

    
    for (int j = 0; j < nr_col; ++j) {
        int suma_pe_coloana = 0;
        for (int i = 0; i < nr_linii; ++i) {
            suma_pe_coloana += matrice[i][j];
        }

        if (suma_pe_coloana % 2 == 0) {
            linie_supl[j] = 0;  
        }
        else {
            linie_supl[j] = 1;  
        }
    }

  
    matrice.push_back(linie_supl);

    cout << "\nMatricea rezultata este:\n";
    for (int i = 0; i < nr_linii + 1; i++) { 
        for (int j = 0; j < nr_col + 1; j++) { 
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }
    cout << " Mesajul transmis este : " << endl;
    for (int i = 0; i < nr_linii +1; i++)
        for (int j = 0; j < nr_col+1; j++)
            cout << matrice[i][j] << " ";

    return 0;
}

