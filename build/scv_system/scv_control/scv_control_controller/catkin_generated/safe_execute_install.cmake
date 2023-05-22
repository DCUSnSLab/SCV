execute_process(COMMAND "/home/dong/Development/SCV/build/scv_system/scv_control/scv_control_controller/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/dong/Development/SCV/build/scv_system/scv_control/scv_control_controller/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
