cmake_minimum_required (VERSION 3.0.2)
project (myproj VERSION 1.0)

find_package (glog 0.6.0 REQUIRED)

add_executable (basic basic.cc)
target_link_libraries (basic glog::glog)
