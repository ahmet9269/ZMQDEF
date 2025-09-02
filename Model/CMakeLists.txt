cmake_minimum_required(VERSION 3.12)
project(SimpleTrackModels)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

# Source files
set(SOURCES
    DelayCalcTrackData.cpp
    ExtrapTrackData.cpp
    FinalCalcTrackData.cpp
    ProcessedTrackData.cpp
    TrackStatics.cpp
    main.cpp
)

# Example executable
add_executable(model_example ${SOURCES})
