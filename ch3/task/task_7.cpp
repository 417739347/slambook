#include <iostream>
#include <cmath>
using namespace std;
#include <Eigen/Core>
#include <Eigen/Geometry>

int main( int argc, char** argv )
{
	Eigen::Quaterniond q1 (0.35, 0.2, 0.3, 0.1);
	Eigen::Quaterniond q2 (-0.5, 0.4, -0.1, 0.2);

	Eigen::AngleAxisd rotation_vector1 = Eigen::AngleAxisd ( q1 );
	Eigen::Isometry3d T1 = Eigen::Isometry3d::Identity();
	T1.rotate ( rotation_vector1 );
	T1.pretranslate ( Eigen::Vector3d (0.3, 0.1, 0.1));
	cout << "Transform matrix1 = \n" << T1.matrix() << endl;

	Eigen::AngleAxisd rotation_vector2 = Eigen::AngleAxisd ( q2 );
        Eigen::Isometry3d T2 = Eigen::Isometry3d::Identity();
        T2.rotate ( rotation_vector2 );
        T2.pretranslate ( Eigen::Vector3d (-0.1, 0.5, 0.3));
        cout << "Transform matrix1 = \n" << T2.matrix() << endl;
	
	Eigen::Vector4d p1 (0.5, 0, 0.2, 1);
	Eigen::Vector4d p =T1.inverse() * p1;
	cout << "p = \n" << p.transpose() << endl;
	
	Eigen::Vector4d p2 = T2 * p;
	cout << "p2 = \n" << p2.transpose() << endl;

	return 0;
}
