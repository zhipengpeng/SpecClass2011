#include "Utils/MyContainers/MyVector.hpp"
#include "StudentProjects/SpecClass2011/Bohn/Assignment02Bohn/Assignment02Bohn.hpp"
#include "Utils/ErrorHandling/Require.hpp"

MyVector<double> SumVectors(const MyVector<double>& A,
                            const MyVector<double>& B) {

  //Make a new MyVector<double> of the same size as the addends
  //Fill each element with zero.
  const int vectorSize = A.Size();

  //Initialize to A.Size() for efficiency
  MyVector<double> sum = A;

  //Add the vectors component-by-component
  //Use the MyVector member function operator[](int i) which returns the
  //the ith component of the vector.
  for(int i=0; i<vectorSize; ++i) {
    sum[i] += B[i];
  }

  //Return the result
  return sum;
}

MyVector<double> DivideVectors(const MyVector<double>& numerator,
								const double& denominator) {
	//Make a new MyVector<double> of the same size as the divisors
	//Fill each element with zero

	const int vectorSize = numerator.Size();

	// Division for vectors which aren't the same size shouldn't take place
	MyVector<double> quotient(MV::Size(vectorSize), 0.);

	//Divide the vectors component-by-component
	for (int i=0; i < vectorSize; ++i) {
		quotient[i] = numerator[i] / denominator;
	}

	return quotient;
}
