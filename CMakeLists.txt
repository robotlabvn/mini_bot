cmake_minimum_required(VERSION 2.8.3)
project(mini_bot)

## Find catkin ROS dependence
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)
## Generate added messages
generate_messages (DEPENDENCIES std_msgs)
## Declare a catkin package
catkin_package()
## Add excutable 
add_executable(mini_bot_talker src/mini_bot_talker.cpp)
target_link_libraries(mini_bot_talker ${catkin_LIBRARIES})
