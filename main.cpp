/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nuria
 *
 * Created on 31 de Janeiro de 2022, 20:09
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "Matrix.h"

using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {
    Matrix *m = new Matrix();
    
    m->SetCustosMatriz();
    m->GetMatriz();
    m->SetOfertas();
    m->SetDemanda();
    
    m->SetPenalidadesOrig();
    m->SetPenalidadesDest();
    m->SetMatrizSolucao();
    
    m->SetPenalidadesOrig();
    m->SetPenalidadesDest();
    m->SetMatrizSolucao();
    
    m->SetPenalidadesOrig();
    m->SetPenalidadesDest();
    m->SetMatrizSolucao();
    
    m->SetPenalidadesOrig();
    m->SetPenalidadesDest();
    m->SetMatrizSolucao();
    
    m->SetPenalidadesOrig();
    m->SetPenalidadesDest();
    m->SetMatrizSolucao();
    
    m->SetPenalidadesOrig();
    m->SetPenalidadesDest();
    m->SetMatrizSolucao();
    return 0;
}