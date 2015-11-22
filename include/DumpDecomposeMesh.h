#pragma once
#include "DumpInfo.h"

namespace GPP
{
    extern GPP_EXPORT DumpBase* CreateDumpMeshHeightFieldDecomposition(void);

    class GPP_EXPORT DumpMeshHeightFieldDecomposition : public DumpBase
    {
    public:
        DumpMeshHeightFieldDecomposition();
        ~DumpMeshHeightFieldDecomposition();

        virtual ApiName GetApiName(void);
        virtual void LoadDumpFile(const std::string& fileName);
        virtual ErrorCode Run(void);
        virtual TriMesh* GetTriMesh(Int id = 0);

        void DumpApiInfo(const ITriMesh* triMesh);

    private:
        TriMesh* mpTriMesh;
    }; 
}
