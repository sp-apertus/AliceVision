#include <iostream>
#include <Eigen/Dense>

#include "lightingEstimation.h"
#include "augmentedNormals.h"

namespace aliceVision {
namespace inverseRendering {

void estimateLigthing(LightingVector& lighting, const eigen::VectorXf albedo, const eigen::VectorXf picture, const eigen::Vector<Normals>& normals)
{
	const Vector<AugmentedNormals> augmentedNormals;
	int nbPoints = augmentedNormals.size();
	for (int i = 0; i < nbPoints; ++i)
	{
		getAugmentedNormals(augmentedNormals(i), normals(i));
	}
	
	MatrixXf rhoTimesN(nb_points, 9);
	albedoNormalsProduct(rhoTimesN, albedo, augmentedNormals);
	
	lighting = albedoNormalsProduct.colPivHouseholderQr().solve(picture);
}

void albedoNormalsProduct(MatrixXf& rhoTimesN, const MatrixXf& albedo, const eigen::Vector<AugmentedNormals> augmentedNormals)
{
	for (int currentPoint = 0; currentPoint < augmentedNormals.size(); ++currentPoint)
	{
		rhoTimesN(currentPoint,1) = albedo(currentPoint)*augmentedNormals.nx;
		rhoTimesN(currentPoint,2) = albedo(currentPoint)*augmentedNormals.ny;
		rhoTimesN(currentPoint,3) = albedo(currentPoint)*augmentedNormals.nz;
		rhoTimesN(currentPoint,4) = albedo(currentPoint)*augmentedNormals.ambiant;
		rhoTimesN(currentPoint,5) = albedo(currentPoint)*augmentedNormals.nx_ny;
		rhoTimesN(currentPoint,6) = albedo(currentPoint)*augmentedNormals.nx_nz;
		rhoTimesN(currentPoint,7) = albedo(currentPoint)*augmentedNormals.ny_nz;
		rhoTimesN(currentPoint,8) = albedo(currentPoint)*augmentedNormals.nx2_ny2;
		rhoTimesN(currentPoint,9) = albedo(currentPoint)*augmentedNormals.nz2;
	}
}

}
}
