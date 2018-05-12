
cmake_minimum_required(VERSION 2.8)

# determine if jetson-utils is being built as a submodule inside another repo,
# or if it's being build standalone (if the later, we need to do some configuration)
get_directory_property(hasParent PARENT_DIRECTORY)

if(hasParent)
	message("-- botlink:  building as submodule, ${hasParent}")
	
	# configure Qt
	find_package(Qt4 REQUIRED)
	include(${QT_USE_FILE})
	add_definitions(${QT_DEFINITIONS})
else()
	message("-- botlink:  building as standalone")
	
	# standalone project
	project(botlink)
  
	# -std=gnu++11
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")	
  
	# Qt is used to load images (installed by ubuntu-desktop)
	find_package(Qt4 REQUIRED)
	include(${QT_USE_FILE})
	add_definitions(${QT_DEFINITIONS})
	
	# setup CUDA
	find_package(CUDA)

	set(
		CUDA_NVCC_FLAGS
		${CUDA_NVCC_FLAGS}; 
		-O3 
		-gencode arch=compute_37,code=sm_37
		-gencode arch=compute_53,code=sm_53
		-gencode arch=compute_60,code=sm_60
		-gencode arch=compute_61,code=sm_61
		-gencode arch=compute_62,code=sm_62
	)
	
	# setup project output paths
	set(PROJECT_OUTPUT_DIR  ${PROJECT_BINARY_DIR}/${CMAKE_SYSTEM_PROCESSOR})
	set(PROJECT_INCLUDE_DIR ${PROJECT_OUTPUT_DIR}/include)

	file(MAKE_DIRECTORY ${PROJECT_INCLUDE_DIR})
	file(MAKE_DIRECTORY ${PROJECT_INCLUDE_DIR}/botlink)
	file(MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR}/bin)

	message("-- system arch:  ${CMAKE_SYSTEM_PROCESSOR}")
	message("-- output path:  ${PROJECT_OUTPUT_DIR}")

	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR}/bin)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR}/lib)
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR}/lib)
	
	# build C/C++ interface
	include_directories(${PROJECT_INCLUDE_DIR})
endif()


# build library
file(GLOB botlinkSources *.cpp *.cu msgs/*.cpp ui/*.cpp)
file(GLOB botlinkIncludes *.h msgs/*.h ui/*.h)

cuda_add_library(botlink SHARED ${botlinkSources})
target_link_libraries(botlink jetson-utils)	


# transfer all headers to the include directory
foreach(include ${botlinkIncludes})
	message("-- Copying ${include}")
	configure_file(${include} ${PROJECT_INCLUDE_DIR}/botlink COPYONLY)
endforeach()
	
	
# post-build standalone steps
if(hasParent)
	# nop
else()	
	# setup `make install` stuff
	foreach(include ${botlinkIncludes})
		install(FILES "${include}" DESTINATION include/botlink)
	endforeach()

	# install the shared library
	install(TARGETS botlink DESTINATION lib/botlink EXPORT botlinkConfig)

	# install the cmake project, for importing
	#install(EXPORT jetson-utilityConfig DESTINATION share/jetson-utility/cmake)
endif()


# build tests/sample executables
#add_subdirectory(msgs)
#add_subdirectory(ui)
add_subdirectory(utils)
