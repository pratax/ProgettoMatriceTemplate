//
// Created by Christian Pratellesi on 11/07/18.
//

#ifndef PROGETTOMATRICITEMPLATE_MATRICETEMPLATE_H
#define PROGETTOMATRICITEMPLATE_MATRICETEMPLATE_H

#include <stdexcept>
#include <cmath>
#include <cfloat>

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

    MatrixTemplate selectColumn(int c){
        if(c<0)
            throw std::out_of_range("Il numero della colonna da estrarre non può essere minore di 0");
        if(c>=columns)
            throw std::out_of_range("Il numero della colonna da estrarre supera le dimensioni della matrice");
        MatrixTemplate<T> tmpmat(rows,1);
        for(int i=0;i<rows;i++){
            tmpmat.matrix[i]=this->matrix[i*columns+c];
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

    MatrixTemplate transposedMatrx(){
        MatrixTemplate<T>transmat(columns,rows);
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                transmat.matrix[j*transmat.columns+i]=matrix[i*columns+j];
            }
        }
        return transmat;
    }

    MatrixTemplate operator+(const MatrixTemplate& rmatrix){
        if(rows!=rmatrix.rows || columns!=rmatrix.columns)
            throw std::logic_error("Le dimensioni delle due matrici non coincidono");
        MatrixTemplate<T>matsum(rows,columns);
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                matsum.matrix[i*columns+j]=matrix[i*columns+j]+rmatrix.matrix[i*columns+j];
            }
        }
        return matsum;
    }

    MatrixTemplate operator+=(const MatrixTemplate& rmatrix){
        if(rows!=rmatrix.rows || columns!=rmatrix.columns)
            throw std::logic_error("Le dimensioni delle due matrici non coincidono");
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                matrix[i*columns+j]+=rmatrix.matrix[i*columns+j];
            }
        }
        return *this;
    }

    bool operator==(const MatrixTemplate& rmatrix){
        if(rows!=rmatrix.rows || columns!=rmatrix.columns)
            return false;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(!areEqual(matrix[i*columns+j],rmatrix.matrix[i*columns+j])){
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const MatrixTemplate& rmatrix){
        return !(*this==rmatrix);
    }

    bool areEqual(T a, T b){
        return a==b;
    }

    template<>
    bool areEqual<float>(float a, float b){
        float diff = a-b;
        if(fabs(diff)<=FLT_EPSILON)
            return true;
        return false;
    }

    template<>
    bool areEqual<double>(double a, double b){
        double diff = a-b;
        if(fabs(diff)<=FLT_EPSILON)
            return true;
        return false;
    }

    MatrixTemplate operator-(const MatrixTemplate& rmatrix){
        if(rows!=rmatrix.rows || columns!=rmatrix.columns)
            throw std::logic_error("Le dimensioni delle due matrici non coincidono");
        MatrixTemplate<T>matsub(rows,columns);
        for(int i=0;i<rows;i++){
            for(int j=0;j<rows;j++){
                matsub.matrix[i*columns+j]=matrix[i*columns+j]-rmatrix.matrix[i*columns+j];
            }
        }
        return matsub;
    }

    MatrixTemplate operator-=(const MatrixTemplate& rmatrix){
        if(rows!=rmatrix.rows || columns!=rmatrix.columns)
            throw std::logic_error("Le dimensioni delle due matrici non coincidono");
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                matrix[i*columns+j]-=rmatrix.matrix[i*columns+j];
            }
        }
        return *this;
    }

    MatrixTemplate operator*(const MatrixTemplate& rmatrix){
        if(columns!=rmatrix.rows)
            throw std::logic_error("Il numero di colonne della prima matrice deve essere uguale al numero di righe della seconda matrice");
        MatrixTemplate<T>matmult(rows,rmatrix.columns);
        for(int i=0;i<matmult.rows;i++){
            for(int j=0;j<matmult.columns;j++){
                for(int m=0;m<columns;m++) {
                    matmult.matrix[i*matmult.columns+j]+=matrix[i*columns+m]*rmatrix.matrix[m*rmatrix.columns+j];
                }
            }
        }
        return matmult;
    }

    MatrixTemplate operator*(const T& num){
        MatrixTemplate<T>matmult(rows,columns);
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                matmult.matrix[i*columns+j]=num*matrix[i*columns+j];
            }
        }
        return matmult;
    }

    MatrixTemplate elmult(const MatrixTemplate& rmatrix){
        if(rows!=rmatrix.rows || columns!=rmatrix.columns)
            throw std::logic_error("Le dimensioni delle due matrici non coincidono");
        MatrixTemplate<T>elmult(rows,columns);
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                elmult.matrix[i*columns+j]=matrix[i*columns+j]*rmatrix.matrix[i*columns+j];
            }
        }
        return elmult;
    }

    MatrixTemplate operator^(const int& a){
        if(a<1)
            throw std::logic_error("L'esponente deve essere un intero maggiore di 0");
        MatrixTemplate<T>matpow(rows,columns);
        matpow=*this;
        for(int i=1;i<a;i++){
            matpow=matpow*(*this);
        }
        return matpow;
    }

















private:
    T* matrix;
    int rows,columns;
};

#endif //PROGETTOMATRICITEMPLATE_MATRICETEMPLATE_H
