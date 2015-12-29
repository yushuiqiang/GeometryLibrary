#pragma once
#include "GppDefines.h"
#include <fstream>
#include <sstream>
#include <map>
#include <string>

namespace GPP
{
    enum GPP_EXPORT ApiName
    {
        MESH_CONSOLIDATION_MAKEMANIFOLD,
        MESH_CONSOLIDATION_GEOMETRY,
        MESH_FILLHOLE_FIND,
        MESH_FILLHOLE_FILL,
        MESH_FILTER_LAPLACESMOOTH,
        MESH_FILTER_ENHANCEDETAIL,
        MESH_FILTER_COMPRESSHEIGHTFIELD,
        Mesh_MEASURE_SECTION_APPROXIMATE,
        MESH_PARAMETERIZATION_ABF,
        MESH_SUBDIVISION_LOOP,
        MESH_SUBDIVISION_CC,
        MESH_SUBDIVISION_REFINE,
        MESH_SIMPLIFICATION_QUADRIC,
        POINT_CONSOLIDATION_NORMALSMOOTHING,
        POINT_CONSOLIDATION_NORMALCALCULATION,
        POINT_CONSOLIDATION_SMOOTHBYNORMAL,
        POINT_CONSOLIDATION_ISOLATIONCALCULATION,
        POINT_RECONSTRUCTION_POISSON,
        POINT_REGISTRATION_ALIGNPOINTPAIR,
        POINT_REGISTRATION_ICP,
        POINT_REGISTRATION_GLOBAL,
        POINT_SAMPLING_UNIFORM,
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

        virtual ApiName GetApiName(void) = 0;
        virtual void LoadDumpFile(const std::string& fileName) = 0;
        virtual ErrorCode Run(void) = 0;
        virtual TriMesh* GetTriMesh(Int id = 0);
        virtual PointCloud* GetPointCloud(Int id = 0);

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

    extern GPP_EXPORT void DumpOnce(void);

    extern bool GetDumpOnce(void);

    extern void SetDumpOnce(bool dump);
}
