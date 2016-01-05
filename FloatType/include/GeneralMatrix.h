#pragma once
#include "GppDefines.h"
#include <vector>

namespace GPP
{
    class GeneralMatrixImpl;
    class GPP_EXPORT GeneralMatrix
    {
    public:
        GeneralMatrix();
        GeneralMatrix(Int nRow, Int nCol);
        GeneralMatrix(Int nRow, Int nCol, const Real* values); //row first
        ~GeneralMatrix();

        GeneralMatrixImpl* GetImpl(void);
        const GeneralMatrixImpl* GetImpl(void) const;

        Int GetRowCount() const;
        Int GetColCount() const;
        Real GetValue(Int row, int col) const;
        void SetValue(Int row, int col, Real value);

    private:
        GeneralMatrixImpl* mpImpl;
    };

    class LeastSquareGeneralLDLSolverImpl;
    class GPP_EXPORT LeastSquareGeneralLDLSolver
    {
    public:
        LeastSquareGeneralLDLSolver();
        ~LeastSquareGeneralLDLSolver();

        ErrorCode Factorize(const GeneralMatrix& generalMatrix);
        ErrorCode Solve(const std::vector<Real>& vecB, std::vector<Real>* result);
        void Free(void);

    private:
        LeastSquareGeneralLDLSolverImpl* mpImpl;
    };

    class SelfAdjointEigenSolverImpl;
    class GPP_EXPORT SelfAdjointEigenSolver
    {
    public:
        SelfAdjointEigenSolver();
        ~SelfAdjointEigenSolver();

        ErrorCode Compute(const GeneralMatrix& generalMatrix);
        
        void GetEigenVector(Int index, std::vector<Real>& eigenVector) const;

        //The eigenvalues are sorted in increasing order
        Real GetEigenValue(Int index) const;

    private:
        SelfAdjointEigenSolverImpl* mpImpl;
    };
}
