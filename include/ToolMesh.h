#pragma once
#include "GppDefines.h"
#include <vector>

namespace GPP
{
    class ITriMesh;
    class TriMesh;
    class HalfMesh;

    //Share the same Vertex3D data
    extern GPP_EXPORT HalfMesh* ConvertTriMeshToHalfMesh(TriMesh* triMesh);

    extern GPP_EXPORT void DeleteConvertedHalfMesh(HalfMesh* halfMesh);

    //Share the same Vertex3D data
    extern GPP_EXPORT TriMesh* ConvertHalfMeshToTriMesh(HalfMesh* halfMesh);

    extern GPP_EXPORT void DeleteConvertedTriMesh(TriMesh* triMesh);

    //Seperate two meshes
    extern GPP_EXPORT HalfMesh* CreateHalfMeshFromITriMesh(const ITriMesh* triMesh);

    //Seperate two meshes
    //inputMesh should not be null
    extern GPP_EXPORT Int ConvertTriMeshToITriMesh(const TriMesh* inputMesh, ITriMesh* convertedMesh);
    
    //triMesh should not be null
    //halfMesh should UpdateVertexIndex before calling
    extern GPP_EXPORT Int ConvertHalfMeshToITriMesh(const HalfMesh* halfMesh, ITriMesh* triMesh);

    extern GPP_EXPORT TriMesh* CopyTriMesh(const TriMesh* triMesh);
}
