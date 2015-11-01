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

    class SelfAdjointEigenSolverImpl;
    class GPP_EXPORT SelfAdjointEigenSolver
    {
    public:
        SelfAdjointEigenSolver();
        ~SelfAdjointEigenSolver();

        Int Compute(const GeneralMatrix& generalMatrix);
        
        std::vector<Real> GetEigenVector(Int index) const;

        //The eigenvalues are sorted in increasing order
        Real GetEigenValue(Int index) const;

    private:
        SelfAdjointEigenSolverImpl* mpImpl;
    };
}
