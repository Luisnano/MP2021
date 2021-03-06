<<<<<<< HEAD
<<<<<<< Updated upstream
# Install script for directory: D:/MP/MP2021/PROYECTO
=======
<<<<<<< Updated upstream
# Install script for directory: C:/Users/Luis Fernando/Desktop/ESI/MP/POXD/MP2021/PROYECTO
=======
# Install script for directory: C:/Users/aleja/Desktop/MP2021/PROYECTO
>>>>>>> Stashed changes
>>>>>>> Stashed changes
=======
# Install script for directory: D:/ESI/CONTENIDO/MP/Liga_cancerigena/PROYECTO/MP2021/PROYECTO
>>>>>>> master

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/PROYECTO")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< HEAD
<<<<<<< Updated upstream
file(WRITE "D:/MP/MP2021/PROYECTO/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
=======
<<<<<<< Updated upstream
file(WRITE "C:/Users/Luis Fernando/Desktop/ESI/MP/POXD/MP2021/PROYECTO/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "C:/Users/aleja/Desktop/MP2021/PROYECTO/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> Stashed changes
>>>>>>> Stashed changes
=======
file(WRITE "D:/ESI/CONTENIDO/MP/Liga_cancerigena/PROYECTO/MP2021/PROYECTO/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> master
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
