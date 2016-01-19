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
        MESH_CONSOLIDATION_MAKEMANIFOLD = 1,
        MESH_CONSOLIDATION_GEOMETRY = 2,
        MESH_FILLHOLE_FIND = 3,
        MESH_FILLHOLE_FILL = 4,
        MESH_FILTER_LAPLACESMOOTH = 5,
        MESH_FILTER_ENHANCEDETAIL = 6,
        MESH_FILTER_COMPRESSHEIGHTFIELD = 7,
        MESH_MEASURE_SECTION_APPROXIMATE = 8,
        MESH_PARAMETERIZATION_ABF = 9,
        MESH_SUBDIVISION_LOOP = 10,
        MESH_SUBDIVISION_CC = 11,
        MESH_SUBDIVISION_REFINE = 12,
        MESH_SIMPLIFICATION_QUADRIC = 13,
        MESH_MEASURE_SECTION_EXACT = 14,
        MESH_CONSOLIDATION_REMOVEGEOMETRYNOISE = 15,

        POINT_CONSOLIDATION_NORMALSMOOTHING = 101,
        POINT_CONSOLIDATION_NORMALCALCULATION = 102,
        POINT_CONSOLIDATION_SMOOTHBYNORMAL = 103,
        POINT_CONSOLIDATION_ISOLATIONCALCULATION = 104,
        POINT_RECONSTRUCTION_POISSON = 105,
        POINT_REGISTRATION_ALIGNPOINTPAIR = 106,
        POINT_REGISTRATION_ICP = 107,
        POINT_REGISTRATION_ALIGNPOINTCLOUD = 108,
        POINT_SAMPLING_UNIFORM = 109,
        POINT_REGISTRATION_ALIGNPOINTCLOUD_MARK = 110,
        POINT_MEASURE_DISTANCE_ONESIDE = 111,
        POINT_CONSOLIDATION_UNIFORMITYCALCULATION = 112,
        POINT_CONSOLIDATION_RAWSCANDATA = 113
    };

    class ITriMesh;
    class TriMesh;
    class IPointCloud;
    class PointCloud;
    class IPointList;
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
        virtual void DumpPointList(const IPointList* pointList, bool dumpNormal, std::ofstream& dumpOut);
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
