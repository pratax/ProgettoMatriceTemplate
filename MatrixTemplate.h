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

    int getRighe() const {
        return rows;
    }


    int getColonne() const {
        return columns;
    }

    MatrixTemplate selectRow()



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







private:
    T* matrix;
    int rows,columns;
};

#endif //PROGETTOMATRICITEMPLATE_MATRICETEMPLATE_H
