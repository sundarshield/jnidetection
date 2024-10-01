# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html.
# For more examples on how to use CMake, see https://github.com/android/ndk-samples.

# Sets the minimum CMake version required for this project.


#cmake_minimum_required(VERSION 3.22.1)
#
#project("jnidetection")
#
#add_library(${CMAKE_PROJECT_NAME} SHARED
#
#        native-lib.cpp)
#
#target_link_libraries(${CMAKE_PROJECT_NAME}
#
#        android
#        log)


# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.22.1)

# Define the project name
project("jnidetection")

# Add the native library (the name of the library will match the project name)
add_library(
        ${CMAKE_PROJECT_NAME}  # Use the project name as the library name
        SHARED                 # Build as a shared library
        native-lib.cpp         # Source file(s)
)

# Find and link Android and log libraries
find_library(
        log-lib               # Variable to store the log library
        log                   # Log library (part of Android NDK)
)

# Link libraries to the native library
target_link_libraries(
        ${CMAKE_PROJECT_NAME}  # The native library (project name)
        android                # Android native library
        ${log-lib}             # Log library from the NDK
)






#
#cmake_minimum_required(VERSION 3.22.1)
#
## Create a shared library from native-lib.cpp
#add_library(
#        jnidetection
#        SHARED
#        src/main/cpp/native-lib.cpp
#)
#
## Link log library (if needed)
#find_library(
#        log-lib
#        log
#)
#
## Link the log library to jnidetection
#target_link_libraries(
#        jnidetection
#        ${log-lib}
#)
