# generating c files from Bison and Flex files
if(WIN32)
	# Compiling Flex and Bison files to C files, and adding them to source files.
	set(BISON_PREFIX_OUTPUTS TRUE CACHE BOOL "activating Bison")
	set(FLEX_PREFIX_OUTPUTS TRUE CACHE BOOL "activating Flex")
elseif(UNIX)
	#find_package(BISON 0)
	#find_package(FLEX 0)
	include("${CMAKE_SOURCE_DIR}/CMakeUserUseBison.cmake")
	include("${CMAKE_SOURCE_DIR}/CMakeUserUseFlex.cmake")
endif(WIN32)


#include header files
include_directories("../include")
include_directories(".")
include_directories("..")
include_directories("../../elm/include")
include_directories("../../gel/include")


# subdirectories
add_subdirectory(prog)
add_subdirectory(branch)
#add_subdirectory(dynbranch)
add_subdirectory(etime)
add_subdirectory(ocpp)
add_subdirectory(odec)
add_subdirectory(odisplay)
#add_subdirectory(dcache)
#add_subdirectory(oslice)
add_subdirectory(icat3)
add_subdirectory(trivial)


# graphviz
if(DOT)
	add_subdirectory(graphviz)
endif()


# tools
add_subdirectory(bpred)
add_subdirectory(config)
add_subdirectory(dumpcfg)
add_subdirectory(mkff)
#add_subdirectory(odfa)
add_subdirectory(ostat)
add_subdirectory(opcg)
add_subdirectory(operform)
add_subdirectory(odisasm)
add_subdirectory(owcet)



# legacy code
if(USE_LEGACY)
	add_subdirectory(cat)
	add_subdirectory(ccg)
endif()
