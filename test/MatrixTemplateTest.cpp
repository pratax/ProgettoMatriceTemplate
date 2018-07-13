//
// Created by Christian Pratellesi on 13/07/18.
//
#include "gtest/gtest.h"
#include "../MatrixTemplate.h"
#include "../MatrixFactory.h"

TEST(MatrixTemplate,DefaultConstructor){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    ASSERT_EQ(3,Mat1->getRows());
    ASSERT_EQ(3,Mat1->getColumns());
    ASSERT_EQ(0,Mat1->getValue(2,2));
    auto Mat2 = intFactory->createMatrixTemplate(-1,2);
    ASSERT_EQ(0,Mat2->getRows());
}

TEST(MatrixTemplate,CopyConstructor){
    MatrixFactory<int>* intFactory;
    auto Mat1 = intFactory->createMatrixTemplate(3,3);
    Mat1->setValue(0,0,1);
    Mat1->setValue(0,1,5);
    Mat1->setValue(0,2,3);
    Mat1->setValue(1,2,7);
    Mat1->setValue(2,0,5);
    Mat1->setValue(2,1,10);
    Mat1->setValue(2,2,-5);
    auto Mat2(*Mat1);
    ASSERT_TRUE(Mat2==*Mat1);
    Mat2.setValue(2,1,5);
    Mat2.setValue(1,1,-9);
    ASSERT_FALSE(Mat2==*Mat1);
}