
#include "Problem3ComputeItemKeith.hpp"

// #include "Utils/DataMesh/DataMesh.hpp"
// #include "Utils/Tensor/Tensor.hpp"
#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/StringParsing/OptionParser.hpp"

namespace ComputeItems {

  Problem3ComputeItemKeith::Problem3ComputeItemKeith(const std::string& opts)
    : mResult(3, "1", DataMesh::Empty)
  {
    OptionParser p(opts);
    mOutput = p.Get<std::string>("Output");
  }

  void Problem3ComputeItemKeith::
  RecomputeData(const DataBoxAccess& box) const {
    
    const MyVector<DataMesh>& x = box.Get<MyVector<DataMesh> >("GlobalCoords");

//     REQUIRE(x.Size() == 3,
//             "Problem3ComputeItemKeith only works in 3 dimensions, not "
//             << x.Size() << ".\n");

    const int dim = x.Size();

    const Mesh& mesh = x[0];

    DataMesh r2(mesh, 0.);
    for(int i=0; i<dim; ++i)
      r2 += x[i]*x[i];

    for(int i=0; i<dim; ++i)
      mResult(i) = x[i]/(sqrt(r2)*r2);
  }

} // end Namespace ComputeItems

