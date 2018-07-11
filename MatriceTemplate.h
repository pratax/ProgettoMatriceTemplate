//
// Created by Christian Pratellesi on 11/07/18.
//

#ifndef PROGETTOMATRICITEMPLATE_MATRICETEMPLATE_H
#define PROGETTOMATRICITEMPLATE_MATRICETEMPLATE_H

template<typename T>
class MatriceTemplate{
public:
    MatriceTemplate(int r, int c):righe(r),colonne(c){
        if(righe<1)
            righe=1;
        if(colonne<1)
            colonne=1;
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



private:
    T* matrice;
    int righe,colonne;
};

#endif //PROGETTOMATRICITEMPLATE_MATRICETEMPLATE_H
