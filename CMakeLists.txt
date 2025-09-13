# CMakeLists.txt: C++ 빌드 스크립트 예시
cmake_minimum_required(VERSION 3.16)
project(server LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Wconversion -O2)
add_executable(server
  src/main.cc
  src/server/accept_loop.cc
  src/server/conn_manager.cc
  src/server/event_select.cc
  src/http/request.cc
  src/http/response.cc
  src/http/pipeline_queue.cc
  src/http/mime_map.cc
  src/fs/docroot.cc
  src/fs/sendfile.cc
  src/util/strutil.cc
  src/util/log.cc
  src/util/timer.cc
)
target_include_directories(server PRIVATE include)
target_link_libraries(server PRIVATE pthread)