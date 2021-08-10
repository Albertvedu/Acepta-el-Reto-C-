//
// Created by albert on 4/8/21.
//

#include <iostream>
#include <string>
#include <climits>
#include <fstream>

using namespace std;
string searchWord(string basicString, int i, bool b);

int main_P255(){
    string  palabra;
    if ( ifstream archivo{"/home/albert/CLionProjects/Acepta-el-Reto-C++/problems/p255.txt"}) {


        //while ( cin >> palabra ){
        while (getline(archivo, palabra) && ! palabra.empty() ){
            string sortida;
            int pos = 0;
            int bestLong = 1;
            bool coincidencia = false;

            if ( palabra.length() < 2001) {
                for (int i = 0; i < palabra.length() - 1; i++) {
                    sortida = searchWord(palabra, pos, coincidencia);
                    if (bestLong < sortida.length()) bestLong = sortida.length();
                    pos++;  // quant torna al métode, segueix per la següent lletra
                }

                if (palabra.length() != 0) cout << bestLong << endl;
            }
        } cout << "fin archivo";
    } else cout << "No se pudo abrir el archivo\n";
    return 0;
}
/*
 * Aquest métode busca de l'última lletra cap a la primera
 * i quant el tornar a ejecutar, fa de l'última cap a la segona lletra i així va repetin, tercera, quarta
 */
string searchWord(string palabra, int pos, bool coincidencia) {
    int posicio = pos;
    int posFinalChar = 0;
    int posInitialChar = INT_MAX;

    for (int i = palabra.length()-1; i > posicio ; i--) {

        if ( palabra.at(i) == palabra.at(posicio)){  // coincideix la última lletra amb la primera
            coincidencia = true;
            if ( posFinalChar < i ) posFinalChar = i; // Guarda pos primera coincidència
            if ( posInitialChar > posicio) posInitialChar = posicio;
            posicio ++;
        }else {
            posicio = pos;   // tornar a començar buscant per la lletra inicial de la búsqueda
            posInitialChar = INT_MAX;
            posFinalChar = 0;
            if (coincidencia) {
                i ++;
                coincidencia = false;
            }
        }
    }

    if ( coincidencia ) return palabra.substr(posInitialChar, posFinalChar - posInitialChar +1);
    else return "";
}