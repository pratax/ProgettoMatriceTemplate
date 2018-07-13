//
// Created by Christian Pratellesi on 13/07/18.
//

#ifndef PROGETTOMATRICITEMPLATE_MATRIXFACTORY_H
#define PROGETTOMATRICITEMPLATE_MATRIXFACTORY_H

#include "MatrixTemplate.h"

template<typename T>
class MatrixFactory {
public:
    MatrixFactory()= default;
    ~MatrixFactory()= default;
    MatrixTemplate<T>* createMatrixTemplate(int r, int c){
        return new MatrixTemplate<T>(r,c);
    }
};


#endif //PROGETTOMATRICITEMPLATE_MATRIXFACTORY_H
