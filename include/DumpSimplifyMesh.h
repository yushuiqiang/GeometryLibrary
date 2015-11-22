#pragma once
#include "DumpInfo.h"

namespace GPP
{
    extern GPP_EXPORT DumpBase* CreateDumpMeshSimplificationQuadric(void);

    class GPP_EXPORT DumpMeshSimplificationQuadric : public DumpBase
    {
    public:
        DumpMeshSimplificationQuadric();
        ~DumpMeshSimplificationQuadric();

        virtual ApiName GetApiName(void);
        virtual void LoadDumpFile(const std::string& fileName);
        virtual ErrorCode Run(void);
        virtual TriMesh* GetTriMesh(Int id = 0);

        void DumpApiInfo(const ITriMesh* triMesh, Int targetVertexCount);

    private:
        TriMesh* mpTriMesh;
        Int mTargetVertexCount;
    }; 
}
