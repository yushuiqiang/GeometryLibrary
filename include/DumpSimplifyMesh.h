#pragma once
#include "DumpInfo.h"

namespace GPP
{
    extern DumpBase* CreateDumpMeshSimplificationQuadric(void);

    class DumpMeshSimplificationQuadric : public DumpBase
    {
    public:
        DumpMeshSimplificationQuadric();
        ~DumpMeshSimplificationQuadric();

        virtual void LoadDumpFile(const std::string& fileName);
        virtual Int Run(void);
        virtual TriMesh* GetTriMesh(void);

        void DumpApiInfo(const ITriMesh* triMesh, Int targetVertexCount);

    private:
        TriMesh* mpTriMesh;
        Int mTargetVertexCount;
    }; 
}
