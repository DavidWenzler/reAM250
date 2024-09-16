##########################################################################################
### Change the next line for making new plugins
##########################################################################################
cmake_minimum_required(VERSION 3.5)

project("reAM250")

include (DevTools/CMakeLists_Distrib.txt)

##########################################################################################
### Add Custom CMake Code after here
##########################################################################################
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT libmcplugin_main)