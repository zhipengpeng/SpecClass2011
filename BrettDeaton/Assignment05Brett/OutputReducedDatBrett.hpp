#include "Utils/IO/OneDimDataWriter.hpp"
#include "Utils/IO/CachedOfStream.hpp"
#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/ErrorHandling/Require.hpp"

#include <fstream>

using std::string;
using std::ofstream;

namespace OneDimDataWriters {

  /// Output standard x,y data for y-vs-x plots,
  ///   with capability to reduce the data.
  class OutputReducedDatBrett: public OneDimDataWriter,
			       Factory::Register<OutputReducedDatBrett> {
  public:
    static string ClassID() { return "reduceddatbrett"; }
    static string Help() {
      return ClassID()+"\n"
	"Output for gnuplot, suitable for a x-y plot. But instead of       \n"
	"outputting at fixed intervals in x, a simple evaluation is done to\n"
	"reduce nearly-linear data. The hardness of the reduction is dialed\n"
	"with the option MinAngle. The ith data point is discarded if the deviation \n"
	"angle between the (i-1)th and the ith segment is less than MinAngle.\n"
	"Where We have defined the ith segment as the line between (x_{i-1},y_{i-1})\n"
	"and (x_i,y_i)."
	"OPTIONS:                                                          \n"
	"  MinAngle = double                                               \n";
    };
    OutputReducedDatBrett(const string& opts, const string& BaseName):
      mFileName(BaseName+".dat"), mOut(mFileName)
    {
      OptionParser p(opts, Help());
      mMinAngle = p.Get<double>("MinAngle");
    };
    void TruncateFile() const {
      ofstream out(mFileName.c_str(), std::ios::trunc);
    };
  private:
    const string mFileName;
    double mMinAngle;
    mutable CachedOfStream mOut;
 
    void AppendToFileImpl(const double time,
			  const MyVector<double>& x,
			  const MyVector<double>& y) const;
    double ComputeAngleFromHorizon(const double xi, const double xii,
				   const double yi, const double yii) const;
  };

}
