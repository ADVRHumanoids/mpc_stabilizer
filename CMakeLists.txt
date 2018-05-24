project(mpc_stabilizer)
cmake_minimum_required(VERSION 3.5)

find_package(XBotInterface REQUIRED)
find_package(OpenSoT REQUIRED)
find_package(OpenMpC REQUIRED)

include_directories(codegen/dll/mpcmoveCodeGeneration/ 	
		    include/ 
		    ${XBotInterface_INCLUDE_DIRS}
		    ${OpenMpC_INCLUDE_DIRS}
		    )
		    
		    
# C++ 11
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_CXX11)
check_cxx_compiler_flag("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()


# Compile MPC
include_directories(MpcController_grt_rtw/ 
                    /usr/local/MATLAB/R2017b/extern/include/
                    /usr/local/MATLAB/R2017b/simulink/include/)
# set(MpcController_SRC
#         MpcController_grt_rtw/MpcController_data.cpp
#         MpcController_grt_rtw/MpcController.cpp
#         MpcController_grt_rtw/
# )

file(GLOB MpcController_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} MpcController_grt_rtw/*.cpp)

add_library(MpcController ${MpcController_SRC})


add_library(MpcStabilizer STATIC src/MpcStabilizer.cpp)
target_link_libraries(MpcStabilizer PUBLIC ${XBotInterface_LIBRARIES} ${OpenMpC_LIBRARIES}
                                    PRIVATE MpcController
        )

add_executable(test_mpc src/mpc_test.cpp)

target_link_libraries(test_mpc ${XBotInterface_LIBRARIES} ${OpenMpC_LIBRARIES}
	    MpcController
	    )
	    
add_subdirectory(MPCPlugin)

