#include <iostream>
#include <cstdlib>
 
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/StringParsing/ReadFileIntoString.hpp"
#include "StudentProjects/SpecClass2011/Ilana/Assignment01Ilana/Assignment01Ilana.hpp"
 
int main(int /*argc*/, char** /*argv*/) {
    std::string opts = ReadFileIntoString("MultiplyAdd.input");
    OptionParser parser(opts);
    double a = parser.Get<double>("A");
    double b = parser.Get<double>("B");
    double c = parser.Get<double>("C");
    double answer = MultiplyAdd(a, b, c);
    std::cout << "a is " << a << ", b is " << b << ", c is " << c << std::endl;
    std::cout << "The answer to a time b plus c is " << answer << std::endl;
 
    return EXIT_SUCCESS;
}
