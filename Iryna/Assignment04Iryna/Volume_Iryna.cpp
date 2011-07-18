#include "Volume_Iryna.hpp"
double TotalVolumeOfSpheresFromRadii(const MyVector<double>& radii) {
  const double Pi = 3.1415926535897932;
  double result = 0.0;
  for(int i=0;i<radii.Size();++i) 
     result += (4/3)*Pi*radii[i]*radii[i]*radii[i];
  return result;
}
