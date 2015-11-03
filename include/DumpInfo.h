#pragma once
#include "GppDefines.h"
#include <fstream>
#include <sstream>
#include <map>
#include <string>

namespace GPP
{
    enum ApiName
    {
        MESH_CONSOLIDATION_LAPLACESMOOTH,
        MESH_CONSOLIDATION_MAKEMANIFOLD,
        MESH_CONSOLIDATION_GEOMETRY,
        MESH_PARAMETERIZATION_ABF,
        MESH_SUBDIVISION_LOOP,
        MESH_SUBDIVISION_CC,
        MESH_SUBDIVISION_REFINE,
        MESH_SIMPLIFICATION_QUADRIC,
        MESH_DECOMPOSE_HEIGHTFIELD,
        POINT_CONSOLIDATION_LAPLACESMOOTH,
        POINT_CONSOLIDATION_NORMALCALCULATION,
        POINT_RECONSTRUCTION_POISSON,
        POINT_SAMPLING_UNIFORM
    };

    class ITriMesh;
    class TriMesh;
    class IPointCloud;
    class PointCloud;
    class GPP_EXPORT DumpBase
    {
    public:
        DumpBase();
        ~DumpBase();

        virtual void LoadDumpFile(const std::string& fileName) = 0;
        virtual Int Run(void) = 0;
        virtual TriMesh* GetTriMesh(void);
        virtual PointCloud* GetPointCloud(void);

        static Int APICalledTime;
    
    protected:
        virtual void DumpTriMesh(const ITriMesh* triMesh, std::ofstream& dumpOut);
        virtual void DumpPointCloud(const IPointCloud* pointCloud, bool dumpNormal, std::ofstream& dumpOut);
    };

    typedef DumpBase* (*CreateDump)(void);

    class GPP_EXPORT DumpManager
    {
    private:
        static DumpManager* mpDumpManager;
        DumpManager();

    public:
        static DumpManager* Get(void);
        
        DumpBase* GetDumpInstance(int dumpClassName);
        bool RegisterDumpClass(int dumpClassName, CreateDump method);
        ~DumpManager();

    private:
        std::map<int, CreateDump> mDumpClassMap;
    };

    extern GPP_EXPORT void RegisterDumpInfo(void);

    extern const bool GppDumpApi;
}
