#/// \dir
#/// Contains a minimal set of files for adding a new executable to SpEC

# Where is SPEC_HOME relative to this directory
CODE_HOME = ../../../../..

# What libraries does this executable depend on
LINKED_LIBS =  \
    Domain Slice Subdomain CoordMap Topology DataMesh IndexMap \
    Vars StringParsing DataBox IO Math Tensor MiscUtils \
    MpiWrappers MyContainers LowLevelUtils ErrorHandling \

# What .cpp files containing a main function should be compiled (remove .cpp)
EXECUTABLES = Problem0Example0 Problem0Example1 DataMeshMemory

##############################################################################
# Nothing below here needs to be changed
##############################################################################
include $(CODE_HOME)/MakefileRules/this_machine.def
include $(CODE_HOME)/MakefileRules/Rules

