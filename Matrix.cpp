/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matrix.cpp
 * Author: nuria
 * 
 * Created on 1 de Fevereiro de 2022, 00:30
 */

#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix() {
    int linhas, colunas;

    cout << "\nEntre com o numero de origens (linhas): ";
    cin >> linhas;

    cout << "Entre com o numero de destinnos (colunas): ";
    cin >> colunas;

    this->linhas = linhas;
    this->colunas = colunas;

    this->matrix = new int*[linhas];

    for (int i = 0; i < linhas; i++) { // incializa matriz
        this->matrix[i] = new int[i];
        for (int j = 0; j < colunas; j++) {
            this->matrix[i][j] = 0;
        }
    }

    // this->GetMatriz();
}

Matrix::Matrix(const Matrix& orig) {
}

Matrix::~Matrix() {
}

void Matrix::GetMatriz() {
    cout << "\n";
    for (int i = 0; i < this->linhas; i++) {
        cout << '\n';
        for (int j = 0; j < this->colunas; j++) {
            cout << '\t' << this->matrix[i][j];
        }
    }
}

void Matrix::SetCustosMatriz() {
    int peso;

    cout << "\n";
    for (int i = 0; i < this->linhas; i++) {

        this->matrix[i] = new int[i];

        for (int j = 0; j < this->colunas; j++) {
            cout << "Digite o peso da posição [" << i + 1 << "," << j + 1 << "]: ";
            cin >> peso;
            this->matrix[i][j] = peso;
        }
    }
}

void Matrix::SetOfertas() {
    int oferta;

    this->ofertas = new int[this->linhas];

    cout << "\n";
    for (int i = 0; i < this->linhas; i++) {
        cout << "Digite a oferta da origem " << i + 1 << ": ";
        cin >> oferta;
        this->ofertas[i] = oferta;
    }
}

void Matrix::SetDemanda() {
    int demanda;

    this->demandas = new int[this->colunas];

    cout << "\n";
    for (int i = 0; i < this->colunas; i++) {
        cout << "Digite a demanda do destino " << i + 1 << ": ";
        cin >> demanda;
        this->demandas[i] = demanda;
    }
}

