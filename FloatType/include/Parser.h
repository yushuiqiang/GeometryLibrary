#pragma once
#include "GppDefines.h"
#include <string>

namespace GPP
{
    class PointCloud;
    class IPointCloud;
    class TriMesh;
    class ITriMesh;
    class GPP_EXPORT Parser
    {
    public:
        Parser();
        ~Parser();

        static PointCloud* ImportPointCloud(std::string fileName);
        static TriMesh*    ImportTriMesh(std::string fileName);

        static void ExportPointCloud(std::string fileName, const IPointCloud* pointCloud);
        static void ExportTriMesh(std::string fileName, const ITriMesh* triMesh);
    };
}