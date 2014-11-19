//
//  concierto.cpp
//  PECL1AyC
//
//  Created by Mario on 18/11/14.
//  Copyright (c) 2014 Mario. All rights reserved.
//

#include "concierto.h"

Concierto::Concierto(int N, int P, int Q, int *F, int *G)
{
    this->N = N;
    this->P = P;
    this->Q = Q;
    this->F = F;
    this->G = G;
}

Concierto::~Concierto()
{
    
}

int Concierto::asignar_Lima()
{
    int complains = 0;
    for (int i = 0; i < Q; i++) {
        int max = 0;
        int max_pos = 0;
        bool sat = false;
        for (int j = 0; j < P; j++) {
            //si el grupo llena la fila, marcar fila como completa
            if (F[j] == G[i]) {
                F[j] = 0;
                sat = true;
            }else if (F[j] > max){
                max = F[j];
                max_pos = j;
            }
        }
        if (!sat) {
            F[max_pos] -= G[i];
        }
    }
    return complains;
}

void Concierto::print()
{
    cout << "N: "<< N << endl;
    cout << "P: " << P<< endl;
    cout << "Q: " << Q<< endl;
    cout << "Filas: ";
    for (int i = 0; i < P; i++) {
        cout << "[" << F[i] << "]";
    }
    cout << endl;
}