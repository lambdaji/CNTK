//
// <copyright file="GPUMatrixcuBLASTests.cpp" company="Microsoft">
//     Copyright (c) Microsoft Corporation.  All rights reserved.
// </copyright>
//
//GPUMatrix Unit tests should go here
#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Math\CPUMatrix.h"
#include "..\Math\GPUMatrix.h"

#pragma warning (disable: 4244 4245 4305)       // conversions and truncations; we don't care in this test project

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Microsoft::MSR::CNTK;

#define epsilon 0.000001

namespace CNTKMathTest
{    
    //*_NoExceptionOnly_Test kind of tests tests only that the method runs without exception. 
    //They doesn't test correctness!!!
    TEST_CLASS(GPU_BLASTests)
    {

    TEST_METHOD(GPU_MultiplyAndWeightedAdd_NoExceptionOnly_Test)
    {        
        float alpha = 0.4;
        GPUMatrix<float> M0_GPU(12, 5, 0 /*deviceId*/);
        GPUMatrix<float> M1_GPU(5, 11, 0 /*deviceId*/);
        GPUMatrix<float> M2_GPU(12, 11, 0 /*deviceId*/);
        GPUMatrix<float>::MultiplyAndWeightedAdd(0.1,M0_GPU,false,M1_GPU,false,alpha,M2_GPU); 
    }


    TEST_METHOD(GPU_Scale_NoExceptionOnly_Test)
    {
        float scale = 0.5;
        GPUMatrix<float> M0_GPU(12, 53, 0 /*deviceId*/);
        GPUMatrix<float> M1_GPU(12, 53, 0 /*deviceId*/);
        GPUMatrix<float>::Scale(scale,M0_GPU);        
    }
    
    TEST_METHOD(GPU_InnerProduct_NoExceptionOnly_Test)
    {        
        float *arr = new float[100];
        for (int i=0;i<100;i++) arr[i]=1;
        GPUMatrix<float> AG(10, 10, 0 /*deviceId*/, arr, matrixFlagNormal);
        GPUMatrix<float> BG(10, 10, 0 /*deviceId*/, arr, matrixFlagNormal);
        GPUMatrix<float> CG(1, 10, 0 /*deviceId*/, arr, matrixFlagNormal);
        GPUMatrix<float>::InnerProduct(AG,BG,CG,true);        
    }

    };
}

