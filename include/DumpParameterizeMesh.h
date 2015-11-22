#pragma once
#include "DumpInfo.h"

namespace GPP
{
    extern GPP_EXPORT DumpBase* CreateDumpMeshParameterizationABF(void);

    class GPP_EXPORT DumpMeshParameterizationABF : public DumpBase
    {
    public:
        DumpMeshParameterizationABF();
        ~DumpMeshParameterizationABF();

        virtual ApiName GetApiName(void);
        virtual void LoadDumpFile(const std::string& fileName);
        virtual ErrorCode Run(void);
        virtual TriMesh* GetTriMesh(Int id = 0);

        void DumpApiInfo(const ITriMesh* triMesh);

    private:
        TriMesh* mpTriMesh;
    }; 
}
