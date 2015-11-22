#pragma once
#include "GppDefines.h"
#include <vector>

namespace GPP
{
    class ITriMesh;
    class TriMesh;
    class HalfMesh;

    // Returned half mesh's normal is not calculated, you can call UpdateNormal if you need it
    extern GPP_EXPORT HalfMesh* CreateHalfMeshFromITriMesh(const ITriMesh* triMesh);

    //inputMesh should not be null
    extern GPP_EXPORT ErrorCode ConvertTriMeshToITriMesh(const TriMesh* inputMesh, ITriMesh* convertedMesh);
    
    //triMesh should not be null
    //halfMesh should UpdateVertexIndex before calling
    extern GPP_EXPORT ErrorCode ConvertHalfMeshToITriMesh(const HalfMesh* halfMesh, ITriMesh* triMesh);

    //Deep Copy
    extern GPP_EXPORT TriMesh* CopyTriMesh(const TriMesh* triMesh);
}
