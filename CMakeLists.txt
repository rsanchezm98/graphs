cmake_minimum_required(VERSION 2.6)
project(graph)

# .cpp files
set(MY_PROGRAM_REQUIRED_FILES
    src/main.cpp
    src/graph.cpp
)

include_directories(include)
include_directories(graphs)

# executable
add_executable(graph ${MY_PROGRAM_REQUIRED_FILES})

install(DIRECTORY include/
  DESTINATION include/
)

install(DIRECTORY graph/
  DESTINATION graph/
)