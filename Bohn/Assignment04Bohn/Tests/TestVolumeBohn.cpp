#include "StudentProjects/SpecClass2011/Bohn/Assignment04Bohn/Volume_Bohn.hpp"
#include <iostream>
#include <cstdlib>

#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/StringParsing/ReadFileIntoString.hpp"
#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/ErrorHandling/Require.hpp"
#include "Utils/ErrorHandling/UtilsForTesting.hpp"

#include <cmath>

int main(int /*argc*/, char** /*argv*/) {
  std::string opts = ReadFileIntoString("Radii.input");
  OptionParser parser(opts);

  double totalVolume = 0.0;
  //
  const double correctVolume = parser.Get<double>("correctVolumeOverPi") * M_PI;

  {
    const double radius_A = parser.Get<double>("radius_A");
    const double radius_B = parser.Get<double>("radius_B");
    const double radius_C = parser.Get<double>("radius_C");
    const double radius_D = parser.Get<double>("radius_D");

    REQUIRE(radius_A >= 0.0, "radius_A should be non-negative");
    REQUIRE(radius_B >= 0.0, "radius_B should be non-negative");
    REQUIRE(radius_C >= 0.0, "radius_C should be non-negative");
    REQUIRE(radius_D >= 0.0, "radius_D should be non-negative");

    std::cout << "Radius of Sphere A: " << radius_A << std::endl;
    std::cout << "Radius of Sphere B: " << radius_B << std::endl;
    std::cout << "Radius of Sphere C: " << radius_C << std::endl;
    std::cout << "Radius of Sphere D: " << radius_D << std::endl;

    const MyVector<double> radii(MV::fill, radius_A, radius_B, radius_C,
                                 radius_D);

    totalVolume = TotalVolumeOfSpheresFromRadii(radii);
  }

    std::cout << "Total volume of spheres: " << totalVolume << std::endl;

    IS_EQUAL_EPS(totalVolume, correctVolume, "Wrong volume. Correct answer: "
        << correctVolume);

    return UtilsForTesting::NumberOfTestsFailed();
}

