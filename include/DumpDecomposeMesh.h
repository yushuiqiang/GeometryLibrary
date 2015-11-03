#pragma once
#include "DumpInfo.h"

namespace GPP
{
    extern DumpBase* CreateDumpMeshHeightFieldDecomposition(void);

    class DumpMeshHeightFieldDecomposition : public DumpBase
    {
    public:
        DumpMeshHeightFieldDecomposition();
        ~DumpMeshHeightFieldDecomposition();

        virtual void LoadDumpFile(const std::string& fileName);
        virtual Int Run(void);
        virtual TriMesh* GetTriMesh(void);

        void DumpApiInfo(const ITriMesh* triMesh);

    private:
        TriMesh* mpTriMesh;
    }; 
}
