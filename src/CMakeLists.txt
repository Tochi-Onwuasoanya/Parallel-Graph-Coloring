cmake_minimum_required(VERSION 3.16)
project(src)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-pthread")

find_package(Boost REQUIRED)
find_package(OpenMP REQUIRED)

include_directories(
    Helpers
    Algorithms

)

add_executable(main
        main.cpp
        Helpers/Graph.cpp Helpers/Graph.h Helpers/Loaders.cpp
        Helpers/Node.cpp Helpers/Node.h
        Helpers/GraphColor.cpp Helpers/GraphColor.h
        Helpers/Helper.cpp Helpers/Helper.h
        Helpers/Performance.h
        Helpers/TimeLog.h
        Helpers/Split_Range.h
        Helpers/ParallelProcessing.hpp
        Algorithms/compute.h
        Algorithms/JP.cpp Algorithms/JP.h
        Algorithms/Luby.cpp Algorithms/Luby.h
        Algorithms/SeqAlg.cpp Algorithms/SeqAlg.h
)

