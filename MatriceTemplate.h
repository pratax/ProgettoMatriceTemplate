//
// Created by Christian Pratellesi on 11/07/18.
//

#ifndef PROGETTOMATRICITEMPLATE_MATRICETEMPLATE_H
#define PROGETTOMATRICITEMPLATE_MATRICETEMPLATE_H

#include <stdexcept>

template<typename T>
class MatriceTemplate{
public:
    MatriceTemplate(int r, int c):righe(r),colonne(c){
        if(righe<0)
            righe=0;
        if(colonne<0)
            colonne=0;
        matrice=new T[righe*colonne];
        for(int i=0;i<righe;i++){
            for(int j=0;j<colonne;j++){
                matrice[i*colonne+j]=0;
            }
        }
    };

    ~MatriceTemplate(){
        delete[] matrice;
    }

    int getRighe() const {
        return righe;
    }


    int getColonne() const {
        return colonne;
    }

    T getValue(int r, int c) const {
        if(r<0)
            throw std::out_of_range("Il numero della riga non può essere minore di 0");
        if(r>=righe)
            throw std::out_of_range("Il numero della riga supera le dimensioni della matrice");
        if(c<0)
            throw std::out_of_range("Il numero della colonna non può essere minore di 0");
        if(c>=colonne)
            throw std::out_of_range("Il numero della colonna supera le dimensioni della matrice");
        return matrice[r*colonne+c];
    }

    void setValue(int r, int c, T& value) {
        if(r<0)
            throw std::out_of_range("Il numero della riga non può essere minore di 0");
        if(r>=righe)
            throw std::out_of_range("Il numero della riga supera le dimensioni della matrice");
        if(c<0)
            throw std::out_of_range("Il numero della colonna non può essere minore di 0");
        if(c>=colonne)
            throw std::out_of_range("Il numero della colonna supera le dimensioni della matrice");
        matrice[r*colonne+c]=value;
    }





private:
    T* matrice;
    int righe,colonne;
};

#endif //PROGETTOMATRICITEMPLATE_MATRICETEMPLATE_H
