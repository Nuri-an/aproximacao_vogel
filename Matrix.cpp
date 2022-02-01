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
#include <cmath>

#define INFINITO 10000000
#define NULO -1

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
    this->matrixSolucao = new int*[linhas];

    for (int i = 0; i < linhas; i++) { // incializa matriz
        this->matrix[i] = new int[i];
        this->matrixSolucao[i] = new int[i];
        for (int j = 0; j < colunas; j++) {
            this->matrix[i][j] = 0;
            this->matrixSolucao[i][j] = 0;
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

void Matrix::GetMatrizSolucao() {
    cout << "\n";
    for (int i = 0; i < this->linhas; i++) {
        cout << '\n';
        for (int j = 0; j < this->colunas; j++) {
            cout << '\t' << this->matrixSolucao[i][j];
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

void Matrix::SetPenalidadesOrig() {
    int menor1, menor2;
    this->penalidadesOrig = new int[this->linhas];

    for (int i = 0; i < this->linhas; i++) {
        menor1 = this->matrix[i][0];
        menor2 = this->matrix[i][1];

        for (int j = 0; j < this->colunas; j++) {
            if (this->matrix[i][j] < menor1 && this->matrix[i][j] < menor2) {
                if (menor1 > menor2)
                    menor1 = this->matrix[i][j];
                else
                    menor2 = this->matrix[i][j];
            } else {
                if (this->matrix[i][j] < menor1 && this->matrix[i][j] != menor2)
                    menor1 = this->matrix[i][j];
                else if (this->matrix[i][j] < menor2 && this->matrix[i][j] != menor1)
                    menor2 = this->matrix[i][j];
            }
        }
        this->penalidadesOrig[i] = fabs(menor1 - menor2);


    }
    /* cout << "\n \t";
    for (int i = 0; i < this->linhas; i++) {
        cout << "\n" << this->penalidadesOrig[i];
    } */
}

void Matrix::SetPenalidadesDest() {
    int menor1, menor2;
    this->penalidadesDest = new int[this->colunas];

    for (int i = 0; i < this->colunas; i++) {
        menor1 = this->matrix[0][i];
        menor2 = this->matrix[1][i];

        for (int j = 0; j < this->linhas; j++) {
            if (this->matrix[j][i] < menor1 && this->matrix[j][i] < menor2) {
                if (menor1 > menor2)
                    menor1 = this->matrix[j][i];
                else
                    menor2 = this->matrix[j][i];
            } else {
                if (this->matrix[j][i] < menor1 && this->matrix[j][i] != menor2)
                    menor1 = this->matrix[j][i];
                else if (this->matrix[j][i] < menor2 && this->matrix[j][i] != menor1)
                    menor2 = this->matrix[j][i];
            }
        }
        this->penalidadesDest[i] = fabs(menor1 - menor2);

    }
    /* cout << "\n \t";
    for (int i = 0; i < this->colunas; i++) {
        cout << "\n" << this->penalidadesDest[i];
    } */
}

void Matrix::SetMatrizSolucao() {
    int maiorPenalidade[2]; // [valor, index]
    string maiorPenalidadeTipo; // "coluna" | "linha"
    int maiorPenalidadeOrig[2]; // [valor, index]
    int maiorPenalidadeDest[2]; // [valor, index]
    int menorCusto[2]; // [valor, index]

    // quais são os maiores valores de penalidade
    for (int i = 0; i < this->linhas; i++) {
        if (i == 0) {
            maiorPenalidadeOrig[0] = this->penalidadesOrig[i];
            maiorPenalidadeOrig[1] = i;
        } else {
            if (maiorPenalidadeOrig[0] < this->penalidadesOrig[i]) {
                maiorPenalidadeOrig[0] = this->penalidadesOrig[i];
                maiorPenalidadeOrig[1] = i;
            }
        }
    }


    for (int i = 0; i < this->colunas; i++) {
        if (i == 0) {
            maiorPenalidadeDest[0] = this->penalidadesDest[i];
            maiorPenalidadeDest[1] = i;
        } else {
            if (maiorPenalidadeDest[0] < this->penalidadesDest[i]) {
                maiorPenalidadeDest[0] = this->penalidadesDest[i];
                maiorPenalidadeDest[1] = i;
            }
        }
    }

    cout << "\nOrigem " << maiorPenalidadeOrig[0] << "\nDestino " << maiorPenalidadeDest[0];


    // qual é o maior dentre os maiores valores de penalidade
    if (maiorPenalidadeOrig[0] > maiorPenalidadeDest[0]) {
        maiorPenalidade[0] = maiorPenalidadeOrig[0];
        maiorPenalidade[1] = maiorPenalidadeOrig[1];
        maiorPenalidadeTipo = "linha";
    } else {
        maiorPenalidade[0] = maiorPenalidadeDest[0];
        maiorPenalidade[1] = maiorPenalidadeDest[1];
        maiorPenalidadeTipo = "coluna";
    }

    // qual é o custo minimo da linha/coluna da maior penalidade
    if (maiorPenalidadeTipo == "linha") {
        for (int i = 0; i < this->colunas; i++) {
            if (i == 0) {
                menorCusto[0] = this->matrix[maiorPenalidadeOrig[1]][i];
                menorCusto[1] = i;
            } else {
                if (menorCusto[0] > this->matrix[maiorPenalidadeOrig[1]][i]) {
                    menorCusto[0] = this->matrix[maiorPenalidadeOrig[1]][i];
                    menorCusto[1] = i;
                }
            }
        }
    } else {
        for (int i = 0; i < this->linhas; i++) {
            if (i == 0) {
                menorCusto[0] = this->matrix[i][maiorPenalidadeDest[1]];
                menorCusto[1] = i;
            } else {
                if (menorCusto[0] > this->matrix[i][maiorPenalidadeDest[1]]) {
                    menorCusto[0] = this->matrix[i][maiorPenalidadeDest[1]];
                    menorCusto[1] = i;
                }
            }
        }
    }

    cout << "\nMenor custo: " << menorCusto[0];

    // adicionar a demanda dessa posição
    if (maiorPenalidadeTipo == "linha") {
        if (this->ofertas[maiorPenalidadeOrig[1]] < this->demandas[menorCusto[1]]) {
            for (int i = 0; i < this->colunas; i++) {
                this->matrix[maiorPenalidade[1]][i] = INFINITO; // inutilizando demais posições da linha
            }
            this->matrixSolucao[maiorPenalidadeOrig[1]][menorCusto[1]] = this->ofertas[maiorPenalidadeOrig[1]];
            this->penalidadesOrig[maiorPenalidadeOrig[1]] = NULO; // oferta esgotada
            this->demandas[menorCusto[1]] = this->demandas[menorCusto[1]] - this->matrixSolucao[maiorPenalidadeOrig[1]][menorCusto[1]]; // quanto ainda falta de demanda
        } else { // toda a demanda será inserida
            for (int i = 0; i < this->linhas; i++) {
                this->matrix[i][menorCusto[1]] = INFINITO; // inutilizando demais posições da coluna
            }
            this->matrixSolucao[maiorPenalidadeOrig[1]][menorCusto[1]] = this->demandas[menorCusto[1]];
            this->penalidadesDest[menorCusto[1]] = NULO; // demanda preenchida
            this->ofertas[maiorPenalidadeOrig[1]] = this->ofertas[maiorPenalidadeOrig[1]] - this->matrixSolucao[maiorPenalidadeOrig[1]][menorCusto[1]]; // quanto de oferta restou

        }
        // this->penalidadesOrig[maiorPenalidadeOrig[1]] = NULO;
    } else {
        if (this->ofertas[menorCusto[1]] < this->demandas[maiorPenalidade[1]]) { // toda oferta sera inserida
            for (int i = 0; i < this->colunas; i++) {
                this->matrix[menorCusto[1]][i] = INFINITO; // inutilizando demais posições da linha
            }
            this->matrixSolucao[menorCusto[1]][maiorPenalidade[1]] = this->ofertas[menorCusto[1]];
            this->penalidadesOrig[menorCusto[1]] = NULO; // oferta esgotada
            this->demandas[maiorPenalidade[1]] = this->demandas[maiorPenalidade[1]] - this->matrixSolucao[menorCusto[1]][maiorPenalidade[1]]; // quanto ainda falta de demanda

        } else { // toda a demanda será inserida
            for (int i = 0; i < this->linhas; i++) {
                this->matrix[i][maiorPenalidade[1]] = INFINITO; // inutilizando demais posições da coluna
            }
            this->matrixSolucao[menorCusto[1]][maiorPenalidade[1]] = this->demandas[maiorPenalidade[1]];
            this->penalidadesDest[maiorPenalidade[1]] = NULO; // demanda preenchida
            this->ofertas[menorCusto[1]] = this->ofertas[menorCusto[1]] - this->matrixSolucao[menorCusto[1]][maiorPenalidade[1]]; // quanto de oferta restou

        }
        // this->penalidadesOrig[maiorPenalidadeOrig[1]] = NULO;

    }
    
    // this->GetMatrizSolucao();
   
}



