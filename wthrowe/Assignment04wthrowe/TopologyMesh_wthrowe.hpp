#ifndef TopologyMesh_hpp
#define TopologyMesh_hpp

#include "Mesh_wthrowe.hpp"
#include "Topology_wthrowe.hpp"
template <typename> class MyVector;
class IndexMap;

class TopologyMesh: public Mesh, public Topology {
public:	
  TopologyMesh(const Mesh & ExistingMesh, 
	       const Topology & rTopology,
	       const MyVector<const IndexMap*> & rIndexMapVec);
  TopologyMesh(const TopologyMesh &);
  ~TopologyMesh();

  // Member functions would normally be declared here.

};  // class TopologyMesh

#endif  // TopologyMesh_hpp