#    Copyright (c) 2010-2018, Delft University of Technology
#    All rigths reserved
#
#    This file is part of the Tudat. Redistribution and use in source and
#    binary forms, with or without modification, are permitted exclusively
#    under the terms of the Modified BSD license. You should have received
#    a copy of the license with this file. If not, please or visit:
#    http://tudat.tudelft.nl/LICENSE.
#

PYTHON_ADD_MODULE(constants Constants.cpp)
FILE(COPY constants.py DESTINATION .)
ADD_TEST(NAME src COMMAND ${PYTHON_EXECUTABLE} constants.py)

#PYTHON_ADD_MODULE(simulation_setup SimulationSetup.cpp)
#FILE(COPY simulation_setup.py DESTINATION .)
#ADD_TEST(NAME SimulationSetup COMMAND ${PYTHON_EXECUTABLE} simulation_setup.py)
#

#set(ESTIMATIONSETUPSDIR "${SIMULATIONSETUPDIR}/EstimationSetup")
#set(ENVIRONMENTSETUPDIR "${SIMULATIONSETUPDIR}/EnvironmentSetup")

#INCLUDE_DIRECTORIES("${ESTIMATIONSETUPSDIR}" "${ENVIRONMENTSETUPDIR}")

# Include the top-level directories.
#include_directories(AFTER
#        "${CODEROOT}"
#        )

## Specify project name.



#
## Find Tudat library on local system.

#include_directories(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS} "/usr/include/python2.7")

#link_directories(${Boost_LIBRARY_DIR})

#set(SOURCE_FILES SimulationSetup.cpp)

#add_library(TudatPy SHARED ${SOURCE_FILES})
#
#target_link_libraries(
#        TudatPy ${PYTHON_LIBRARIES} ${Boost_LIBRARIES}
#)

#
## Set compiler based on preferences (e.g. USE_CLANG) and system.

# CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
#
# project(TudatPy)
#
# #message("CHAAAA ${CMAKE_SOURCE_DIR}")
# include_directories ("${CMAKE_SOURCE_DIR}/tudat")
# include_directories ("${CMAKE_SOURCE_DIR}/eigen")
# include_directories ("${CMAKE_SOURCE_DIR}/cspice")
# find_package(Spice)
# find_package(Tudat 2.0 REQUIRED)
# include(tudatLinkLibraries)
#
# include_directories(SYSTEM AFTER "${SPICE_INCLUDE_DIR}")
#
#IF(NOT CMAKE_BUILD_TYPE)
#    SET(CMAKE_BUILD_TYPE "DEBUG")
#    #SET(CMAKE_BUILD_TYPE "RELEASE")
#    #SET(CMAKE_BUILD_TYPE "RELWITHDEBINFO")
#    #SET(CMAKE_BUILD_TYPE "MINSIZEREL")
#ENDIF()
#
#FIND_PACKAGE(Boost 1.45.0)
#IF(Boost_FOUND)
#    INCLUDE_DIRECTORIES("${Boost_INCLUDE_DIRS}" "/usr/include/python2.7")
#    SET(Boost_USE_STATIC_LIBS OFF)
#    SET(Boost_USE_MULTITHREADED ON)
#    SET(Boost_USE_STATIC_RUNTIME OFF)
#    FIND_PACKAGE(Boost 1.45.0 COMPONENTS python)
#
#    ADD_LIBRARY(simulation_setup SHARED SimulationSetup.cpp)
#    TARGET_LINK_LIBRARIES(simulation_setup ${Boost_LIBRARIES})
#    TARGET_LINK_LIBRARIES(simulation_setup ${PYTHON_LIBRARIES})
#    target_link_libraries(
#            simulation_setup ${PYTHON_LIBRARIES} ${Boost_LIBRARIES}
#    )
#
#ELSEIF(NOT Boost_FOUND)
#    MESSAGE(FATAL_ERROR "Unable to find correct Boost version. Did you set BOOST_ROOT?")
#ENDIF()
#
#IF(CMAKE_COMPILER_IS_GNUCXX)
#    ADD_DEFINITIONS("-Wall")
#ELSE()
#    MESSAGE(FATAL_ERROR "CMakeLists.txt has not been tested/written for your compiler.")
#ENDIF()
#
#FILE(COPY simulation_setup.py DESTINATION .)
#PYTHON_ADD_MODULE(simulation_setup SimulationSetup.cpp)
#FILE(COPY hello.py DESTINATION .)
#ADD_TEST(NAME 01-HelloWorld COMMAND ${PYTHON_EXECUTABLE} hello.py)
