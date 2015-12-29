#pragma once
#include "IPointCloud.h"
#include "ITriMesh.h"

namespace GPP
{
    // Motivation:
    // 1. Some algorithm only needs coord, normal information, such as point sampling, octree. Thus we could do algorithm on IPointList
    // 2. Sometimes we want to do algorithm on sub-set of a point set, we could warp the subset like a point list, like SampledPointList
    // 3. Here we define some subclass of IPonitList for common usage: PointCloudPointList, SampledPointList, TriMeshPointList

    class GPP_EXPORT IPointList
    {
    public:
        IPointList() {};
        virtual ~IPointList() {};

        virtual Int GetPointCount() const = 0;
        virtual Vector3 GetPointCoord(Int pid) const = 0;
        virtual Vector3 GetPointNormal(Int pid) const = 0;
    };

    class GPP_EXPORT PointCloudPointList : public IPointList
    {
    public:
        explicit PointCloudPointList(const IPointCloud* pointCloud);
        virtual ~PointCloudPointList();

        virtual Int GetPointCount() const;
        virtual Vector3 GetPointCoord(Int pid) const;
        virtual Vector3 GetPointNormal(Int pid) const;

    private:
        const IPointCloud* mpPointCloud;
    };

    class GPP_EXPORT SampledPointList : public IPointList
    {
    public:
        explicit SampledPointList(const IPointCloud* pointCloud, const Int* sampleIndex, Int sampleCount);
        virtual ~SampledPointList();

        virtual Int GetPointCount() const;
        virtual Vector3 GetPointCoord(Int pid) const;
        virtual Vector3 GetPointNormal(Int pid) const;

    private:
        const IPointCloud* mpPointCloud;
        const Int* mpSampleIndex;
        Int mSampleCount;
    };

    class GPP_EXPORT TriMeshPointList : public IPointList
    {
    public:
        explicit TriMeshPointList(const ITriMesh* trMesh);
        virtual ~TriMeshPointList();

        virtual Int GetPointCount() const;
        virtual Vector3 GetPointCoord(Int pid) const;
        virtual Vector3 GetPointNormal(Int pid) const;

    private:
        const ITriMesh* mpTriMesh;
    };
}
