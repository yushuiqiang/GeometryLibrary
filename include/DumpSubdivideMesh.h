#pragma once
#include "DumpInfo.h"

namespace GPP
{
    extern DumpBase* CreateDumpMeshSubdivisionLoop(void);

    class DumpMeshSubdivisionLoop : public DumpBase
    {
    public:
        DumpMeshSubdivisionLoop();
        ~DumpMeshSubdivisionLoop();

        virtual void LoadDumpFile(const std::string& fileName);
        virtual Int Run(void);
        virtual TriMesh* GetTriMesh(void);

        void DumpApiInfo(const ITriMesh* triMesh);

    private:
        TriMesh* mpTriMesh;
    };

    
    extern DumpBase* CreateDumpMeshSubdivisionCC(void);

    class DumpMeshSubdivisionCC : public DumpBase
    {
    public:
        DumpMeshSubdivisionCC();
        ~DumpMeshSubdivisionCC();

        virtual void LoadDumpFile(const std::string& fileName);
        virtual Int Run(void);
        virtual TriMesh* GetTriMesh(void);

        void DumpApiInfo(const ITriMesh* triMesh);

    private:
        TriMesh* mpTriMesh;
    }; 


    extern DumpBase* CreateDumpMeshSubdivisionRefine(void);

    class DumpMeshSubdivisionRefine : public DumpBase
    {
    public:
        DumpMeshSubdivisionRefine();
        ~DumpMeshSubdivisionRefine();

        virtual void LoadDumpFile(const std::string& fileName);
        virtual Int Run(void);
        virtual TriMesh* GetTriMesh(void);

        void DumpApiInfo(const ITriMesh* triMesh, Int targetVertexCount);

    private:
        TriMesh* mpTriMesh;
        Int mTargetVertexCount;
    }; 
}
