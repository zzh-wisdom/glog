cmake_minimum_required (VERSION 3.0.2)
project (myproj VERSION 1.0)

find_package (glog 0.6.0 REQUIRED)

add_definitions(-D GLOG_CUSTOM_PREFIX_SUPPORT)

add_executable (basic basic.cc)
add_executable (custom_prefix custom_prefix.cc)

target_link_libraries (basic glog::glog)
target_link_libraries (custom_prefix glog::glog)
