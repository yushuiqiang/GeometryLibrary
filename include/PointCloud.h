#pragma once
#include "IPointCloud.h"
#include <vector>

namespace GPP
{
    class GPP_EXPORT PointCloud : public IPointCloud
    {
    public:
        // In the default constructor, PointCloud has no normal, no color information
        // User can set the information in the constructor or use SetHas** api to allocate the memory
        PointCloud();
        PointCloud(bool hasNormal, bool hasColor);

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
        bool HasColor(void) const;
        Vector3 GetPointColor(Int pid) const;
        void SetPointColor(Int pid, const Vector3& color);

        void ReservePoint(Int pointCount);
        void UnifyCoords(Real bboxSize, Real* scaleValue = NULL, Vector3* objCenterCoord = NULL);
        void UnifyCoords(Real scaleValue, const Vector3& objCenterCoord);

        void SetDefaultColor(const Vector3& color);

        virtual ~PointCloud();

    private:
        bool mHasNormal;
        bool mHasColor;
        std::vector<Vector3> mCoordList;
        std::vector<Vector3> mNormalList;
        std::vector<Vector3> mColorList;
        Vector3 mDefaultColor;
    };
}
