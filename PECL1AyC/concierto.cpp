//
//  concierto.cpp
//  PECL1AyC
//
//  Created by Mario on 18/11/14.
//  Copyright (c) 2014 Mario. All rights reserved.
//

#include "concierto.h"

Concierto::Concierto(int N, int P, int Q, vector<int> F, vector<int> G)
{
    this->N = N; // n personas
    this->P = P; //n filas
    this->Q = Q; //n grupos
    this->F = F; // array filas
    this->G = G; // array grupos
    complains = 0;
    for (int i = 0; i < P; i++) {
        B.push_back(Row(F[i]));
    }
}

Concierto::~Concierto()
{
    
}

int Concierto::asignar_Lima(vector<int> filas, vector<int> grupos)
{
    int pos;
    for (int c = 0; c < Q; c++) {
        //buscar hueco del tamaño del grupo
        pos = find(filas.begin(), filas.end(), grupos[c]) - filas.begin();
        if (pos < filas.size()) {           //hueco encontrado
            filas[pos] -=grupos[c];
            fill(pos, grupos[c], c);
        } else {                            //hueco no encontrado
            int max = get_max(filas);
            if (grupos[c] < filas[max]) {   //grupo cabe en fila
                filas[max] -= grupos[c];
                fill(max, grupos[c], c);
            } else {                        //no cabe, hay q fragmentar
                complains+=grupos[c];
                int min = get_min(filas);
                while (grupos[c] > filas[min]) {
                    grupos[c] -= filas[min];
                    fill(min, filas[min], c);
                    filas[min] = 0;
                    min = get_min(filas);
                }
                max = get_max(filas);
                fill(max, grupos[c], c);
                filas[max] -= grupos[c];
            }
        }
    }
    return complains;
}

int Concierto::asignar_Lima_Verbose(vector<int> filas, vector<int> grupos)
{
    int pos;
    for (int c = 0; c < Q; c++) {
        //buscar hueco del tamaño del grupo
        cout << "iteración " << c << endl;
        pos = find(filas.begin(), filas.end(), grupos[c]) - filas.begin();
        if (pos < filas.size()) {           //hueco encontrado
            cout << "Hueco encontrado! Sentando " << grupos[c] << " personas en la fila " << pos << endl;
            filas[pos] -=grupos[c];
            fill(pos, grupos[c], c);
        } else {                            //hueco no encontrado
            //Hueco no encontrado, buscando la fila con más huecos libres
            int max = get_max(filas);
            cout << "Hueco no encontrado, la fila con más huecos libres es la fila " << max << endl;
            if (grupos[c] < filas[max]) {   //grupo cabe en fila
                //el grupo cabe entero en la fila, sentando n personas en la fila
                //f con h huecos libres
                cout << "El grupo cabe en la fila, sentando " << grupos[c] << " personas en la fila " << max << endl;
                filas[max] -= grupos[c];
                fill(max, grupos[c], c);
            } else {                        //no cabe, hay q fragmentar
                //el grupo no cabe entero en la fila
                cout << "El grupo no cabe entero en la fila, hay que fragmentar" << endl;
                complains+=grupos[c];
                //buscando la fila con menos huecos
                int min = get_min(filas);
                while (grupos[c] > filas[min]) {
                    cout << "La fila con menos huecos libres es " << min << endl;
                    grupos[c] -= filas[min];
                    fill(min, filas[min], c);
                    cout << "Sentando " << filas[min] << " personas" << endl;
                    filas[min] = 0;
                    min = get_min(filas);
                }
                cout << "El subgrupo ya cabe entero en alguna fila, buscando la que más libre está" << endl;
                max = get_max(filas);
                fill(max, grupos[c], c);
                cout << "Sentando " << grupos[c] << " personas en la fila " << max << endl;
                filas[max] -= grupos[c];
            }
        }
    }
    return complains;
}

int Concierto::asignar_Lima(bool verbose)
{
    if (verbose) {
        return asignar_Lima_Verbose(F, G);
    }else{
        return asignar_Lima(F,G);        
    }

}

int Concierto::get_complains()
{
    return complains;
}

void Concierto::printButacas()
{
    cout << "Butacas:" << endl;;
    for (int i = 0; i < B.size(); i++) {
        for (int j = 0; j < B[i].chairs.size(); j++) {
            cout << "[" << B[i].chairs[j] << "]";
        }
        cout << endl;
    }
}

bool Concierto::fill(int nfila, int npersonas, int id)
{
    int free = B[nfila].free;
    for (int i = free; i < free+npersonas; i++) {
        B[nfila].chairs[i] = id+1;
    }
    B[nfila].free = free+npersonas;
    return true;
}

int Concierto::get_max(vector<int> n)
{
    //O(n)
    int max = 0;
    int pos = 0;
    for (int i = 0; i < n.size(); i++) {
        if (max < n[i]) {
            max = n[i];
            pos = i;
        }
    }
    return pos;
}

int Concierto::get_min(vector<int> n) {
    int min = INT16_MAX;
    int pos = 0;
    for (int i = 0; i < n.size(); i++) {
        if (n[i] == 0) {
            continue;
        }
        if (min > n[i]) {
            min = n[i];
            pos = i;
        }
    }
    return pos;
}