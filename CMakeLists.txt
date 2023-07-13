cmake_minimum_required(VERSION 3.8)
project(pure_pursuit_r2wrapper)
#debug the find package
# set pure_pursuit_core_DIR to /usr/lib/p
#add_library(lart_common SHARED IMPORTED)
#set_target_properties(lart_common PROPERTIES IMPORTED_LOCATION /usr/lib/lart_common/liblart_common.so)
#add_library(pure_pursuit_core SHARED IMPORTED)
#set_target_properties(pure_pursuit_core PROPERTIES IMPORTED_LOCATION /usr/lib/path_tracker/libpure_pursuit_core.so)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(library_name pure_pursuit_r2wrapper)
set(lib_srcs src/pursuit_node.cpp)
set(dep_targets rclcpp std_msgs geometry_msgs ) #pure_pursuit_core
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
#print CMAKE_MODULE_PATH


# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_cpplint REQUIRED)
find_package(ament_cmake_uncrustify REQUIRED)
# ros2 
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
#find_library(pure_pursuit_core REQUIRED)
#find_package(lart_common REQUIRED)
#include shared lib located in /usr/lib/path_tracker/libpure_pursuit_core.so


# TODO add cmake_prefix_path... 

add_library(${library_name} ${lib_srcs})
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

ament_target_dependencies(${library_name} ${dep_targets}) 

#if(BUILD_TESTING)
 # find_package(ament_lint_auto REQUIRED)
  # TODO implement testing 
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  #set(ament_cmake_cpplint_FOUND TRUE)
  #ament_lint_auto_find_test_dependencies()
#else()
#	ament_uncrustify(${library_name} ${lib_srcs})
#endif()

target_include_directories(${library_name} PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
$<INSTALL_INTERFACE:include>)

add_executable(${library_name}_node src/main.cpp src/pursuit_node.cpp)

ament_target_dependencies(${library_name}_node ${dep_targets})
target_link_libraries(${library_name}_node ${library_name} ${pure_pursuit_core} ${lart_common})

target_compile_features(${library_name} PUBLIC c_std_99 cxx_std_17)

install(TARGETS ${library_name}
  DESTINATION lib/${PROJECT_NAME})
  
install(TARGETS ${library_name}_node
  DESTINATION lib/${PROJECT_NAME})
# add config folder
install(DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)
ament_package()
