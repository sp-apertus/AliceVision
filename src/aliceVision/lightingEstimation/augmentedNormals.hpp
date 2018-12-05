#include <Eigen/Dense>

namespace aliceVision {
namespace inverseRendering {

using eigen::MatrixXf;

struct Normals {
	MatrixXf nx; 
	MatrixXf ny; 
	MatrixXf nz;
};

struct AugmentedNormals {
	MatrixXf nx; 
	MatrixXf ny; 
	MatrixXf nz;
	MatrixXf ambiant; 
	MatrixXf nx_ny; 
	MatrixXf nx_nz;
	MatrixXf ny_nz; 
	MatrixXf nx2_ny2; 
	MatrixXf nz2;
};

void getAugmentedNormals(AugmentedNormals& agmNormals, const Normals& normals);

}
}
