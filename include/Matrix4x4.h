#pragma once
#include "GppDefines.h"
#include "Vector3.h"

namespace GPP
{
    // v0  v1  v2  v3
    // v4  v5  v6  v7
    // v8  v9  v10 v11
    // v12 v13 v14 v15
    class Matrix4x4
    {
    public:
        Matrix4x4();
        Matrix4x4(Real initValue);
        Matrix4x4(const Matrix4x4& matrix);
        ~Matrix4x4();

        void Init(Real value);
        Real QuadricValue(const Vector3& vec) const;
        Real GetValue(Int index) const;
        void SetValue(Int index, Real value);
        Real GetValue(Int rid, Int cid) const;
        void SetValue(Int rid, Int cid, Real value);
        void Free(void);
        bool IsEmpty(void) const;

        Matrix4x4  operator + (const Matrix4x4& mat) const;
        Matrix4x4  operator - (const Matrix4x4& mat) const;
        Matrix4x4& operator += (const Matrix4x4& mat);
        Matrix4x4& operator -= (const Matrix4x4& mat);
        Matrix4x4& operator = (const Matrix4x4& mat);

    private:
        Real* mpValues;
    };
}
