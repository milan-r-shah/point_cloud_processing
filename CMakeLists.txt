cmake_minimum_required(VERSION 2.8.3)
project(point_cloud_processing)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include/point_cloud_processing
  CATKIN_DEPENDS roscpp rospy std_msgs
)

include_directories(
  include/point_cloud_processing
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node src/point_cloud_processing.cpp src/point_cloud_processing_node.cpp)

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)