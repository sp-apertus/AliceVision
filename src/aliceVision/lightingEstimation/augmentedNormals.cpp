#include <math.h>

#include "augmentedNormals.h"

namespace aliceVision {
namespace inverseRendering {

void getAugmentedNormals(AugmentedNormals& agmNormals, const Normals& normals)
{
	agmNormals.nx = normals.nx;
	agmNormals.ny = normals.ny;
	agmNormals.nz = normals.nz;
	agmNormals.ambiant = 1;
	agmNormals.nx_ny = normals.nx*normals.ny;
	agmNormals.nx_nz = normals.nx*normals.nz;
	agmNormals.ny_nz = normals.ny*normals.nz;
	agmNormals.nx2_ny2 = pow(normals.nx,2) - pow(normals.ny,2);
	agmNormals.nz2 = 3*pow(normals.nz,2) - 1;
}

}
}
