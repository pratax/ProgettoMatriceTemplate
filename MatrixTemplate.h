//
// Created by Christian Pratellesi on 11/07/18.
//

#ifndef PROGETTOMATRICITEMPLATE_MATRICETEMPLATE_H
#define PROGETTOMATRICITEMPLATE_MATRICETEMPLATE_H

#include <stdexcept>

template<typename T>
class MatrixTemplate{
public:
    MatrixTemplate(int r, int c):rows(r),columns(c){
        if(rows<0)
            rows=0;
        if(columns<0)
            columns=0;
        matrix=new T[rows*columns];
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                matrix[i*columns+j]=0;
            }
        }
    };

    ~MatrixTemplate(){
        delete[] matrix;
    }

    int getRows() const {
        return rows;
    }


    int getColumns() const {
        return columns;
    }

    MatrixTemplate selectRow(int r){
        if(r<0)
            throw std::out_of_range("Il numero della riga da estrarre non può essere minore di 0");
        if(r>=rows)
            throw std::out_of_range("Il numero della riga da estrare supera le dimensioni della matrice");
        MatrixTemplate<T> tmpmat(1,columns);
        for(int j=0;j<columns;j++){
            tmpmat.matrix[j]=this->matrix[r*columns+j];
        }
        return tmpmat;
    }



    T getValue(int r, int c) const {
        if(r<0)
            throw std::out_of_range("Il numero della riga non può essere minore di 0");
        if(r>=rows)
            throw std::out_of_range("Il numero della riga supera le dimensioni della matrice");
        if(c<0)
            throw std::out_of_range("Il numero della colonna non può essere minore di 0");
        if(c>=columns)
            throw std::out_of_range("Il numero della colonna supera le dimensioni della matrice");
        return matrix[r*columns+c];
    }

    void setValue(int r, int c, T& value) {
        if(r<0)
            throw std::out_of_range("Il numero della riga non può essere minore di 0");
        if(r>=rows)
            throw std::out_of_range("Il numero della riga supera le dimensioni della matrice");
        if(c<0)
            throw std::out_of_range("Il numero della colonna non può essere minore di 0");
        if(c>=columns)
            throw std::out_of_range("Il numero della colonna supera le dimensioni della matrice");
        matrix[r*columns+c]=value;
    }

    MatrixTemplate(const MatrixTemplate& rmatrix){
        rows=rmatrix.rows;
        columns=rmatrix.columns;
        matrix = new T[rows*columns];
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                matrix[i*columns+j]=rmatrix.matrix[i*columns+j];
            }
        }
    }

    MatrixTemplate& operator=(const MatrixTemplate& rmatrix){
        if(this!=&rmatrix){
            rows=rmatrix.rows;
            columns=rmatrix.columns;
            if(matrix!= nullptr)
                matrix= nullptr;
            matrix = new T[rows*columns];
            for(int i=0;i<rows;i++){
                for(int j=0;j<columns;j++){
                    matrix[i*columns+j]=rmatrix.matrix[i*columns+j];
                }
            }
        }
        return *this;
    }







private:
    T* matrix;
    int rows,columns;
};

#endif //PROGETTOMATRICITEMPLATE_MATRICETEMPLATE_H
