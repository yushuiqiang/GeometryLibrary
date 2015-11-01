#pragma once
#include "DumpInfo.h"

namespace GPP
{
    extern DumpBase* CreateDumpMeshParameterizationABF(void);

    class DumpMeshParameterizationABF : public DumpBase
    {
    public:
        DumpMeshParameterizationABF();
        ~DumpMeshParameterizationABF();

        virtual void LoadDumpFile(const std::string& fileName);
        virtual Int Run(void);
        virtual TriMesh* GetTriMesh(void);

        void DumpApiInfo(const ITriMesh* triMesh);

    private:
        TriMesh* mpTriMesh;
    }; 
}
