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

        // fileName should contains the path name and fileName, like ../Models/PointCloud.asc or C:/Models/PointCloud.asc
        // Support format: asc, obj
        static PointCloud* ImportPointCloud(std::string fileName);

        // fileName should contains the path name and fileName, like ../Models/PointCloud.asc or C:/Models/PointCloud.asc
        // Support format: obj, stl, off, ply
        static TriMesh*    ImportTriMesh(std::string fileName);

        // fileName should contains the path name and fileName, like ../Models/PointCloud.asc or C:/Models/PointCloud.asc
        // Support format: obj, ply
        static void ExportPointCloud(std::string fileName, const IPointCloud* pointCloud);

        // fileName should contains the path name and fileName, like ../Models/PointCloud.asc or C:/Models/PointCloud.asc
        // Support format: obj, stl, ply
        static void ExportTriMesh(std::string fileName, const ITriMesh* triMesh);
    };
}
