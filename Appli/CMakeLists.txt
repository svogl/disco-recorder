cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Compiler options
set(STM32_MCU_FLAGS  "-mcpu=cortex-m55 -mfpu=fpv5-d16 -mfloat-abi=hard -mcmse " )

#Linker options
set(STM32_LINKER_SCRIPT STM32N657XX_LRUN.ld)
set(STM32_LINKER_OPTION  )

# Set the project name
set(CMAKE_PROJECT_NAME disco-rec_Appli)
project(${CMAKE_PROJECT_NAME})

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Include mx-generated
include("mx-generated.cmake")

# In order to use CMake for cross-compiling
set(CMAKE_CXX_COMPILER_FORCED "true")

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
)

# middlewares and libraries
# main include path for common library header configs 
add_definitions( -DSTM32N657xx )
# Order: make sure the updated headers are used before the CubeMX ones
include_directories( BEFORE
    ${CMAKE_CURRENT_SOURCE_DIR}/drv/stm32n6xx-hal-driver/Inc
    # isp headers have been dropped from this directory as it's 1.3 now:
    ${CMAKE_CURRENT_SOURCE_DIR}/drv/stm32n6570-dk-bsp-local
    ${CMAKE_CURRENT_SOURCE_DIR}/drv/stm32n6570-dk-bsp 
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/stm32-mw-venc-ewl
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/VideoEncoder/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/stm32-mw-fatfs/source
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/app
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/stm32-mw-camera
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/stm32-mw-camera/sensors
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/stm32-mw-isp/isp/Inc
     ${MX_Include_Dirs}
    )

add_subdirectory(drv)
add_subdirectory(libs)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # STM additional sources
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/app_camerapipeline.c
    # Add user sources here
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/app/fsm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/app/camera_subsys.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/app/venc_interface.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/app/sd_interface.c
)

#
# .. remove the 'PRIVATE' keyword...
# 

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

target_link_libraries(${CMAKE_PROJECT_NAME} 
    hal bsp isp-mw camera-mw venc
)

# Remove wrong libob.a library dependency when using cpp files
list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

# Validate that STM32CubeMX code is compatible with C standard
if((CMAKE_C_STANDARD EQUAL 90) OR (CMAKE_C_STANDARD EQUAL 99))
    message(ERROR "Generated code requires C11 or higher")
endif()









