#/// \dir
#/// Contains a minimal set of files for adding a new executable to SpEC

# Where is SPEC_HOME relative to this directory
CODE_HOME = ../../../../..

# What libraries does this executable depend on
LINKED_LIBS = Tensor DataMesh MyContainers ErrorHandling \
	 LowLevelUtils

# What .cpp files containing a main function should be compiled (remove .cpp)
EXECUTABLES = MyClass1 MyClass2 MyMeshExec MyDM_Exec MyTensorStructureExec \
	MyTensorExec MyTDM_Exec MyTDM_Exec2  MyTTDM_Exec MyTTDM_Exec2

##############################################################################
# Nothing below here needs to be changed
##############################################################################
include $(CODE_HOME)/MakefileRules/this_machine.def
include $(CODE_HOME)/MakefileRules/Rules

