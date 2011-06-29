#include <iostream>
#include <cstdlib>
 
#include "MyLibAssignment01Maxim.hpp"

// for parsing 
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"

using namespace std;

int main(int /*argc*/, char** /*argv*/) {
 	/*
    double a = 1;
    double b = 2;
	double c = 3;
 	*/

    string opts = ReadFileIntoString("MultiplyAdd.input");
    OptionParser parser(opts);
    double a = parser.Get<double>("A");
    double b = parser.Get<double>("B");
	double c = parser.Get<double>("C");
	
    double res = MultiplyAdd(a, b, c);
    cout << "Performing " << a << "x" << b << " + " << c << " = " << res << endl;
 
    return EXIT_SUCCESS;
}
