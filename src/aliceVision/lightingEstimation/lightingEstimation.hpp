#include <iostream>
#include <Eigen/Dense>

#include "augmentedNormals.h"

namespace aliceVision {
namespace inverseRendering {

using eigen::MatrixXf;

using LightingVector = eigen::Matrix<float, 9, 1>;

void estimateLigthing(LightingVector& lighting, const MatrixXf& albedo, const MatrixXf& picture, const Normals& normals);

void albedoNormalsProduct(MatrixXf& rhoTimesN, const MatrixXf& albedo, const eigen::Vector<AugmentedNormals> augmentedNormals);

}
}
