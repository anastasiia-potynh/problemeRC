// tema4 fereastra glisanta.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int nr_pachete = 9;
    const float prob_pierdere = 0.4;

    srand(time(0));
    

    for (int i = 1; i <= nr_pachete; ++i) {
        bool primit = false;

        while (!primit) {
            cout << "Trimit pachetul " << i << "..." << endl;

            float sansa = rand() / (float)RAND_MAX;

            if (sansa > prob_pierdere) {
               
                cout << "Pachetul " << i << " a fost primit" << endl;
                cout << "ACK pentru pachetul " << i << "\n" << endl;
                primit = true;
            }
            else {
                
                cout << "Pachetul" << i << " s-a pierdut!  Retrimit...\n" << endl;
            }
        }
    }

    cout << "Toate pachetele au fost transmise cu succes!" << endl;

    return 0;
}

