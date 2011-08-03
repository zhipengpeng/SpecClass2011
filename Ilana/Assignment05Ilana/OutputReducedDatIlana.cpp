#include "OutputReducedDatIlana.hpp"
#include "Utils/MyContainers/MyVector.hpp"
#include "OneDimDataWriter.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "NdData.hpp"
#include "Utils/StringParsing/StringUtils.hpp"
#include "OneDimDataWriter.hpp"

#include <cmath>
#include <fstream>
#include <string>

namespace OneDimDataWriters {

  \\ Same as OutputDat, but it can reduce data as well

  class OutputReducedDatIlana: public OneDimDataWriter, Factory::Register<OutputReducdedDatIlana> {
  public:
    static string ClassID() {return "reduceddatIlana";}
    static string Help() {
      return ClassID()+"\n"
	"Generates a separate file each time AppendToFileImp1 is called,\n"
	"and outputs x_i and y_i as too columns in to each file. \n"
	"The i-th data-point is omitted if the angle calculated between \n"
	"the line-segment connecting and the i-th and (i+1)-st gridpoint \n"
	"is less than some user-specifiable minimum angle. \n"
	"OPTIONS \n"
	" MinAngle = double\n";
    }

    OutputReducedDatIlana(const string& opts, const string& BaseName) {
      mFileName(BaseName+"."+ClassID()) {
	REQUIRE(opts.empty(), Help());
      };
    void TruncateFile() const;
  private:
    const string mFileName;
    double mMinAngle;
    void AppendToFileImp1(const double time, const MyVector<double>& x, 
				  const MyVector<double>& y) const;
  };

}
