#include "stdlib.h"
#include "stdio.h"
#include <string>
#include "string.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <openrave/openrave.h>
#include <exception>
#include <stdexcept>
#include "voxel_grid.h"

#ifndef DVXL_H_
#define DVXL_H_

namespace DVXL
{

typedef struct dvxl
{
    float deformability;
    float sensitivity;
    uint8_t R;
    uint8_t G;
    uint8_t B;
    uint8_t A;
} dvxl_t;

class DVXL_GRID
{

protected:

    void LoadLegacyFiletype(std::string filename, double legacy_resolution);

    void LoadCurrentFiletype(std::string filename);

    void SetValues(float deformability, float sensitivity, uint8_t R, uint8_t G, uint8_t B, uint8_t A);

    bool WriteLegacyFiletype(std::string filename);

    bool WriteCurrentFiletype(std::string filename);

    float default_deformability_;
    float default_sensitivity_;

public:

    DVXL_GRID(std::string filename, double legacy_resolution=-1.0);

    DVXL_GRID(double Xdim, double Ydim, double Zdim, double resolution, float default_deformability, float default_sensitivity, OpenRAVE::Transform origin);

    ~DVXL_GRID()
    {
    }

    bool ConvertToLegacyFiletype(std::string filename);

    std::vector<float> GetDefaults();

    void SetNewDefaults(float deformability, float sensitivity);

    void Reset();

    bool Save(std::string filename);

    distance_field::VoxelGrid<dvxl_t> grid_;
};

}

#endif // DVXL_H_
