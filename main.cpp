#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/*
 *  Permet de récupérer les lignes ne contenant pas une occurence
 *  et de creer un nouveau fichier contenant les autres lignes
 */

int main()
{
    const string file_source = "c:/test/test.txt";       // fichier source
    const string file_new = "c:/test/fichier_new.txt"; // nouveau fichier crée
    const char* occurence = "FR";                   // occurence

    ifstream fichier(file_source, ios::in);  //déclaration du flux et ouverture du fichier
    ofstream fichier_new(file_new, ios::out);  //déclaration du flux et ouverture du fichier

    if(fichier)  // si l'ouverture a réussi
    {
        string ligne;
        while(getline(fichier, ligne))
        {
            auto* c = new char[ligne.length() + 1];
            strcpy(c, ligne.c_str());

            if(strstr(c, occurence) == nullptr) { // si la ligne ne contient pas l'occurence

                if (fichier_new)
                {
                    cout << "on ecrit dans le fichier new la ligne : " + ligne << endl;
                    fichier_new << ligne << endl;
                }
                else {
                    cerr << "Erreur à l'ouverture du fichier_new !" << endl;
                }
            }
            else {
                cout << "la ligne contient FR " <<endl;
            }

            delete[] c;
        }
        fichier.close();
    }
    else {
        cerr << "Erreur à l'ouverture du fichier_source !" << endl;
    }

    return 0;

}