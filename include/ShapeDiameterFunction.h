/*==================================================================================================

                       Copyright (c) 2016 GeometryPlusPlus, ThreePark
                             Unpublished - All rights reserved

====================================================================================================*/
#pragma once
#include "ITriMesh.h"
#include <vector>

namespace GPP
{
    class MeshQueryTool;
    // the mesh should have normals for each of the vertices
    class ShapeDiameterFunction
    {
    public:
        ShapeDiameterFunction(const ITriMesh* triMesh);
        ~ShapeDiameterFunction();

        void SetConeAngle(Real angle);
        Real GetSDFValueAt(Int vertexId, bool *isInfinite = NULL);
        Real GetThicknessAt(Int vertexId, bool *isInfinite = NULL);
        ErrorCode GetThicknessValues(std::vector<Real>& thicknessValues, std::vector<bool>* isInfiniteValues = NULL);

    private:
        void Init();

    private:
        const ITriMesh* mpTriMesh;
        MeshQueryTool*  mpQueryTool;
        Real mConeAngle;
    };
}
