#pragma once
#include "GppDefines.h"
#include <vector>
#include <string>

namespace GPP
{
    extern GPP_EXPORT Int AddVector(std::vector<Real>& originVector, const std::vector<Real>& refVector, Int refStartIndex);
    extern GPP_EXPORT Int SubVector(std::vector<Real>& originVector, const std::vector<Real>& refVector, Int refStartIndex);
    extern GPP_EXPORT void PrintVector(const std::vector<Real>& vec, std::string vecName);
}
