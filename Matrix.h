/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matrix.h
 * Author: nuria
 *
 * Created on 1 de Fevereiro de 2022, 00:30
 */

#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
    int linhas;
    int colunas;
    int **matrix;
    int **matrixSolucao;
    int *ofertas;
    int *demandas;
    int *penalidadesOrig;
    int *penalidadesDest;
    
public:
    Matrix();
    Matrix(const Matrix& orig);
    virtual ~Matrix();
    void SetCustosMatriz();
    void GetMatriz();
    void SetMatrizSolucao();
    void GetMatrizSolucao();
    void SetOfertas();
    void SetDemanda();
    void SetPenalidadesOrig();
    void SetPenalidadesDest();
};

#endif /* MATRIX_H */

