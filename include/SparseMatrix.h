#pragma once
#include "GppDefines.h"
#include <vector>
#include <string>

namespace GPP
{
    class GPP_EXPORT Triplet
    {
    public:
        Triplet();
        Triplet(Int row, Int col, Real value);
        ~Triplet();

        Int  GetRow() const;
        void SetRow(Int row);
        Int  GetCol() const;
        void SetCol(Int col);
        Real GetValue() const;
        void SetValue(Real value);
    
    private:
        Int mRow, mCol;
        Real mValue;
    };

    class SparseMatrixImpl;
    class GPP_EXPORT SparseMatrix
    {
    public:
        SparseMatrix();
        SparseMatrix(Int nRow, Int nCol);
        SparseMatrix(Int nRow, Int nCol, const std::vector<Triplet>& tripletList);
        SparseMatrix(const SparseMatrix& matrix);
        ~SparseMatrix();
        
        SparseMatrixImpl* GetImpl(void);
        const SparseMatrixImpl* GetImpl(void) const;

        void Init(Int nRow, Int nCol);
        bool AddTriplet(Int row, Int col, Real value);
        bool BuildFromTriplets(void);
        Real GetValue(Int row, Int col) const;
        void SetValue(Int row, int col, Real value);
        SparseMatrix Transpose(void) const;
        void PrintMatrix(std::string matrixName) const;

        SparseMatrix& operator = (const SparseMatrix& matrix);
        SparseMatrix operator + (const SparseMatrix& matrix) const;
        SparseMatrix operator - (const SparseMatrix& matrix) const;
        SparseMatrix operator * (const SparseMatrix& matrix) const;
        std::vector<Real> operator * (const std::vector<Real>& vec) const;
        SparseMatrix& operator += (const SparseMatrix& matrix);
        SparseMatrix& operator -= (const SparseMatrix& matrix);

    private:
        SparseMatrixImpl* mpImpl;
    };

    class LinearSparseLUSolverImpl;
    class GPP_EXPORT LinearSparseLUSolver
    {
    public:
        LinearSparseLUSolver();
        ~LinearSparseLUSolver();

        Int Factorize(const SparseMatrix& sparseMatrix);
        Int Solve(const std::vector<Real>& vecB, std::vector<Real>* result);
        void Free(void);

    private:
        LinearSparseLUSolverImpl* mpImpl;
    };

    class LeastSquareSparseLUSolverImpl;
    class LeastSquareSparseLUSolver
    {
    public:
        LeastSquareSparseLUSolver();
        ~LeastSquareSparseLUSolver();

        Int Factorize(const SparseMatrix& sparseMatrix);
        Int Solve(const std::vector<Real>& vecB, std::vector<Real>* result);
        void Free(void);

    private:
        LeastSquareSparseLUSolverImpl* mpImpl;
    };
}
