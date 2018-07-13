#include <iostream>
#include "MatrixTemplate.h"
#include "MatrixFactory.h"

int main() {
    MatrixFactory<int>* matfact;
    auto pow = matfact->createMatrixTemplate(2,2);
    pow->print();
}