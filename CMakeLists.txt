cmake_minimum_required(VERSION 3.23)
project(http_server)

add_executable(server)

target_sources(server
  PRIVATE
    src/server.c
)

add_executable(client)

target_sources(client
  PRIVATE
    src/client.c
)

add_executable(test)

target_sources(test
  PRIVATE
    src/sketches/test.c
)

add_library(tools)

target_sources(tools
  PRIVATE
    src/tools/tools.c

  PUBLIC
    FILE_SET myHeaders
    TYPE HEADERS
    BASE_DIRS
      src/tools
    FILES
      src/tools/tools.h
)

target_link_libraries(server tools wsock32 ws2_32)
target_link_libraries(client tools wsock32 ws2_32)