//
// Created by Christian Pratellesi on 13/07/18.
//
#include "gtest/gtest.h"
#include "../MatrixTemplate.h"
#include "../MatrixFactory.h"

TEST(MatrixTemplate,DefaultConstructor){
    MatrixFactory<int>intFactory;
    auto Mat1 = intFactory.createMatrixTemplate(3,3);
    ASSERT_EQ(3,Mat1->getRows());
    ASSERT_EQ(3,Mat1->getColumns());
    ASSERT_EQ(0,Mat1->getValue(2,2));
    auto Mat2 = intFactory.createMatrixTemplate(-1,2);
    ASSERT_EQ(0,Mat2->getRows());
}