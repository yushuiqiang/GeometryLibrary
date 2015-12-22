#pragma once
#include "IPointCloud.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT Point3D
    {
    public:
        Point3D();
        Point3D(const Vector3& coord);
        Point3D(const Vector3& coord, const Vector3& normal);

        void SetCoord(const Vector3& coord);
        Vector3 GetCoord() const;
        void SetNormal(const Vector3& normal);
        Vector3 GetNormal() const;
        void SetColor(const Vector3& color);
        Vector3 GetColor() const;

        ~Point3D();

    private:
        Vector3 mCoord;
        Vector3 mNormal;
        Vector3 mColor;
    };

    class GPP_EXPORT PointCloud : public IPointCloud
    {
    public:
        PointCloud();

        virtual Int GetPointCount() const;
        virtual Vector3 GetPointCoord(Int pid) const;
        virtual void SetPointCoord(Int pid, const Vector3& coord);
        virtual Vector3 GetPointNormal(Int pid) const;
        virtual void SetPointNormal(Int pid, const Vector3& normal);
        virtual bool HasNormal() const;
        virtual void SetHasNormal(bool has);
        // Return inserted triangle id
        virtual Int InsertPoint(const Vector3& coord);
        // Return inserted triangle id
        virtual Int InsertPoint(const Vector3& coord, const Vector3& normal);

        virtual void SwapPoint(Int pointId0, Int pointId1); 
        virtual void PopbackPoints(Int popCount);
        virtual void Clear(void);

        void SetHasColor(bool has);
        bool HasColor(void);
        Vector3 GetPointColor(Int pid) const;
        void SetPointColor(Int pid, const Vector3& color);

        void ReservePoint(Int pointCount);
        void UnifyCoords(Real bboxSize, Real* scaleValue = NULL, Vector3* objCenterCoord = NULL);
        void UnifyCoords(Real scaleValue, const Vector3& objCenterCoord);

        virtual ~PointCloud();

    private:
        std::vector<Point3D* > mPointList;
        bool mHasNormal;
        bool mHasColor;
    };
}
