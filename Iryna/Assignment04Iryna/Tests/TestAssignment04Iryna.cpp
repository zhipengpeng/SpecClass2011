#include <iostream>
#include <cstdlib>

#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/StringParsing/ReadFileIntoString.hpp"
#include "Utils/ErrorHandling/UtilsForTesting.hpp"
#include "Utils/ErrorHandling/Require.hpp"
#include "StudentProjects/SpecClass2011/Iryna/Assignment04Iryna/Volume_Iryna.hpp"

int main(int /*argc*/, char** /*argv*/) {

 // First, make a vector of Radii to test
 const MyVector<double> Radii(MV::fill, 1.1, 2.2, 3.3);

 // Next, make a vector to store the result                                     

  double TotalVolume = 0;

  // Find the volumes using the radii                                                    

  TotalVolume = TotalVolumeOfSpheresFromRadii(Radii);
  const double expectedTotalVolume =  200.71007145254467; 

  IS_TRUE(TotalVolume == expectedTotalVolume, "ERROR: The \
	calculated total volume does not match the expected"); 

  // Print out the results                                                       

  std::cout << "Radii = " << Radii << std::endl;
  std::cout << "Total Volume = " << TotalVolume << std::endl;

  //Return success                                                              
  return UtilsForTesting::NumberOfTestsFailed();
}

