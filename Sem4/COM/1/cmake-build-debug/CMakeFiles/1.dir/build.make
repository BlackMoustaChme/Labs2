# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\Chernousov\labs2\Sem4\COM\1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\1.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\1.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\1.dir\flags.make

CMakeFiles\1.dir\main.cpp.obj: CMakeFiles\1.dir\flags.make
CMakeFiles\1.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1.dir/main.cpp.obj"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\1.dir\main.cpp.obj /FdCMakeFiles\1.dir\ /FS -c F:\Chernousov\labs2\Sem4\COM\1\main.cpp
<<

CMakeFiles\1.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1.dir/main.cpp.i"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe > CMakeFiles\1.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Chernousov\labs2\Sem4\COM\1\main.cpp
<<

CMakeFiles\1.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1.dir/main.cpp.s"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\1.dir\main.cpp.s /c F:\Chernousov\labs2\Sem4\COM\1\main.cpp
<<

CMakeFiles\1.dir\servs\serv.cpp.obj: CMakeFiles\1.dir\flags.make
CMakeFiles\1.dir\servs\serv.cpp.obj: ..\servs\serv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/1.dir/servs/serv.cpp.obj"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\1.dir\servs\serv.cpp.obj /FdCMakeFiles\1.dir\ /FS -c F:\Chernousov\labs2\Sem4\COM\1\servs\serv.cpp
<<

CMakeFiles\1.dir\servs\serv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1.dir/servs/serv.cpp.i"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe > CMakeFiles\1.dir\servs\serv.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Chernousov\labs2\Sem4\COM\1\servs\serv.cpp
<<

CMakeFiles\1.dir\servs\serv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1.dir/servs/serv.cpp.s"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\1.dir\servs\serv.cpp.s /c F:\Chernousov\labs2\Sem4\COM\1\servs\serv.cpp
<<

CMakeFiles\1.dir\servs\serv2.cpp.obj: CMakeFiles\1.dir\flags.make
CMakeFiles\1.dir\servs\serv2.cpp.obj: ..\servs\serv2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/1.dir/servs/serv2.cpp.obj"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\1.dir\servs\serv2.cpp.obj /FdCMakeFiles\1.dir\ /FS -c F:\Chernousov\labs2\Sem4\COM\1\servs\serv2.cpp
<<

CMakeFiles\1.dir\servs\serv2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1.dir/servs/serv2.cpp.i"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe > CMakeFiles\1.dir\servs\serv2.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Chernousov\labs2\Sem4\COM\1\servs\serv2.cpp
<<

CMakeFiles\1.dir\servs\serv2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1.dir/servs/serv2.cpp.s"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\1.dir\servs\serv2.cpp.s /c F:\Chernousov\labs2\Sem4\COM\1\servs\serv2.cpp
<<

CMakeFiles\1.dir\dll\IUnknown.cpp.obj: CMakeFiles\1.dir\flags.make
CMakeFiles\1.dir\dll\IUnknown.cpp.obj: ..\dll\IUnknown.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/1.dir/dll/IUnknown.cpp.obj"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\1.dir\dll\IUnknown.cpp.obj /FdCMakeFiles\1.dir\ /FS -c F:\Chernousov\labs2\Sem4\COM\1\dll\IUnknown.cpp
<<

CMakeFiles\1.dir\dll\IUnknown.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1.dir/dll/IUnknown.cpp.i"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe > CMakeFiles\1.dir\dll\IUnknown.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Chernousov\labs2\Sem4\COM\1\dll\IUnknown.cpp
<<

CMakeFiles\1.dir\dll\IUnknown.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1.dir/dll/IUnknown.cpp.s"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\1.dir\dll\IUnknown.cpp.s /c F:\Chernousov\labs2\Sem4\COM\1\dll\IUnknown.cpp
<<

CMakeFiles\1.dir\servs\ServerFactory.cpp.obj: CMakeFiles\1.dir\flags.make
CMakeFiles\1.dir\servs\ServerFactory.cpp.obj: ..\servs\ServerFactory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/1.dir/servs/ServerFactory.cpp.obj"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\1.dir\servs\ServerFactory.cpp.obj /FdCMakeFiles\1.dir\ /FS -c F:\Chernousov\labs2\Sem4\COM\1\servs\ServerFactory.cpp
<<

CMakeFiles\1.dir\servs\ServerFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1.dir/servs/ServerFactory.cpp.i"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe > CMakeFiles\1.dir\servs\ServerFactory.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Chernousov\labs2\Sem4\COM\1\servs\ServerFactory.cpp
<<

CMakeFiles\1.dir\servs\ServerFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1.dir/servs/ServerFactory.cpp.s"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\1.dir\servs\ServerFactory.cpp.s /c F:\Chernousov\labs2\Sem4\COM\1\servs\ServerFactory.cpp
<<

CMakeFiles\1.dir\servs\ClientServerWrapper.cpp.obj: CMakeFiles\1.dir\flags.make
CMakeFiles\1.dir\servs\ClientServerWrapper.cpp.obj: ..\servs\ClientServerWrapper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/1.dir/servs/ClientServerWrapper.cpp.obj"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\1.dir\servs\ClientServerWrapper.cpp.obj /FdCMakeFiles\1.dir\ /FS -c F:\Chernousov\labs2\Sem4\COM\1\servs\ClientServerWrapper.cpp
<<

CMakeFiles\1.dir\servs\ClientServerWrapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1.dir/servs/ClientServerWrapper.cpp.i"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe > CMakeFiles\1.dir\servs\ClientServerWrapper.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Chernousov\labs2\Sem4\COM\1\servs\ClientServerWrapper.cpp
<<

CMakeFiles\1.dir\servs\ClientServerWrapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1.dir/servs/ClientServerWrapper.cpp.s"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\1.dir\servs\ClientServerWrapper.cpp.s /c F:\Chernousov\labs2\Sem4\COM\1\servs\ClientServerWrapper.cpp
<<

CMakeFiles\1.dir\dll\Vector_.cpp.obj: CMakeFiles\1.dir\flags.make
CMakeFiles\1.dir\dll\Vector_.cpp.obj: ..\dll\Vector_.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/1.dir/dll/Vector_.cpp.obj"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\1.dir\dll\Vector_.cpp.obj /FdCMakeFiles\1.dir\ /FS -c F:\Chernousov\labs2\Sem4\COM\1\dll\Vector_.cpp
<<

CMakeFiles\1.dir\dll\Vector_.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1.dir/dll/Vector_.cpp.i"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe > CMakeFiles\1.dir\dll\Vector_.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Chernousov\labs2\Sem4\COM\1\dll\Vector_.cpp
<<

CMakeFiles\1.dir\dll\Vector_.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1.dir/dll/Vector_.cpp.s"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\1.dir\dll\Vector_.cpp.s /c F:\Chernousov\labs2\Sem4\COM\1\dll\Vector_.cpp
<<

CMakeFiles\1.dir\dll\VectorFactory_.cpp.obj: CMakeFiles\1.dir\flags.make
CMakeFiles\1.dir\dll\VectorFactory_.cpp.obj: ..\dll\VectorFactory_.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/1.dir/dll/VectorFactory_.cpp.obj"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\1.dir\dll\VectorFactory_.cpp.obj /FdCMakeFiles\1.dir\ /FS -c F:\Chernousov\labs2\Sem4\COM\1\dll\VectorFactory_.cpp
<<

CMakeFiles\1.dir\dll\VectorFactory_.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1.dir/dll/VectorFactory_.cpp.i"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe > CMakeFiles\1.dir\dll\VectorFactory_.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Chernousov\labs2\Sem4\COM\1\dll\VectorFactory_.cpp
<<

CMakeFiles\1.dir\dll\VectorFactory_.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1.dir/dll/VectorFactory_.cpp.s"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\1.dir\dll\VectorFactory_.cpp.s /c F:\Chernousov\labs2\Sem4\COM\1\dll\VectorFactory_.cpp
<<

CMakeFiles\1.dir\dll\ClientVectorWrapper.cpp.obj: CMakeFiles\1.dir\flags.make
CMakeFiles\1.dir\dll\ClientVectorWrapper.cpp.obj: ..\dll\ClientVectorWrapper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/1.dir/dll/ClientVectorWrapper.cpp.obj"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\1.dir\dll\ClientVectorWrapper.cpp.obj /FdCMakeFiles\1.dir\ /FS -c F:\Chernousov\labs2\Sem4\COM\1\dll\ClientVectorWrapper.cpp
<<

CMakeFiles\1.dir\dll\ClientVectorWrapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1.dir/dll/ClientVectorWrapper.cpp.i"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe > CMakeFiles\1.dir\dll\ClientVectorWrapper.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Chernousov\labs2\Sem4\COM\1\dll\ClientVectorWrapper.cpp
<<

CMakeFiles\1.dir\dll\ClientVectorWrapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1.dir/dll/ClientVectorWrapper.cpp.s"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\1.dir\dll\ClientVectorWrapper.cpp.s /c F:\Chernousov\labs2\Sem4\COM\1\dll\ClientVectorWrapper.cpp
<<

CMakeFiles\1.dir\dll\Client.cpp.obj: CMakeFiles\1.dir\flags.make
CMakeFiles\1.dir\dll\Client.cpp.obj: ..\dll\Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/1.dir/dll/Client.cpp.obj"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\1.dir\dll\Client.cpp.obj /FdCMakeFiles\1.dir\ /FS -c F:\Chernousov\labs2\Sem4\COM\1\dll\Client.cpp
<<

CMakeFiles\1.dir\dll\Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1.dir/dll/Client.cpp.i"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe > CMakeFiles\1.dir\dll\Client.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Chernousov\labs2\Sem4\COM\1\dll\Client.cpp
<<

CMakeFiles\1.dir\dll\Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1.dir/dll/Client.cpp.s"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\1.dir\dll\Client.cpp.s /c F:\Chernousov\labs2\Sem4\COM\1\dll\Client.cpp
<<

CMakeFiles\1.dir\ManagerDLL.cpp.obj: CMakeFiles\1.dir\flags.make
CMakeFiles\1.dir\ManagerDLL.cpp.obj: ..\ManagerDLL.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/1.dir/ManagerDLL.cpp.obj"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\1.dir\ManagerDLL.cpp.obj /FdCMakeFiles\1.dir\ /FS -c F:\Chernousov\labs2\Sem4\COM\1\ManagerDLL.cpp
<<

CMakeFiles\1.dir\ManagerDLL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1.dir/ManagerDLL.cpp.i"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe > CMakeFiles\1.dir\ManagerDLL.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Chernousov\labs2\Sem4\COM\1\ManagerDLL.cpp
<<

CMakeFiles\1.dir\ManagerDLL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1.dir/ManagerDLL.cpp.s"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\1.dir\ManagerDLL.cpp.s /c F:\Chernousov\labs2\Sem4\COM\1\ManagerDLL.cpp
<<

CMakeFiles\1.dir\dll\VectorPotenoteTask_.cpp.obj: CMakeFiles\1.dir\flags.make
CMakeFiles\1.dir\dll\VectorPotenoteTask_.cpp.obj: ..\dll\VectorPotenoteTask_.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/1.dir/dll/VectorPotenoteTask_.cpp.obj"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\1.dir\dll\VectorPotenoteTask_.cpp.obj /FdCMakeFiles\1.dir\ /FS -c F:\Chernousov\labs2\Sem4\COM\1\dll\VectorPotenoteTask_.cpp
<<

CMakeFiles\1.dir\dll\VectorPotenoteTask_.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1.dir/dll/VectorPotenoteTask_.cpp.i"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe > CMakeFiles\1.dir\dll\VectorPotenoteTask_.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Chernousov\labs2\Sem4\COM\1\dll\VectorPotenoteTask_.cpp
<<

CMakeFiles\1.dir\dll\VectorPotenoteTask_.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1.dir/dll/VectorPotenoteTask_.cpp.s"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\1.dir\dll\VectorPotenoteTask_.cpp.s /c F:\Chernousov\labs2\Sem4\COM\1\dll\VectorPotenoteTask_.cpp
<<

CMakeFiles\1.dir\dll\VectorPotenoteTaskFactory_.cpp.obj: CMakeFiles\1.dir\flags.make
CMakeFiles\1.dir\dll\VectorPotenoteTaskFactory_.cpp.obj: ..\dll\VectorPotenoteTaskFactory_.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/1.dir/dll/VectorPotenoteTaskFactory_.cpp.obj"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\1.dir\dll\VectorPotenoteTaskFactory_.cpp.obj /FdCMakeFiles\1.dir\ /FS -c F:\Chernousov\labs2\Sem4\COM\1\dll\VectorPotenoteTaskFactory_.cpp
<<

CMakeFiles\1.dir\dll\VectorPotenoteTaskFactory_.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1.dir/dll/VectorPotenoteTaskFactory_.cpp.i"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe > CMakeFiles\1.dir\dll\VectorPotenoteTaskFactory_.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Chernousov\labs2\Sem4\COM\1\dll\VectorPotenoteTaskFactory_.cpp
<<

CMakeFiles\1.dir\dll\VectorPotenoteTaskFactory_.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1.dir/dll/VectorPotenoteTaskFactory_.cpp.s"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\1.dir\dll\VectorPotenoteTaskFactory_.cpp.s /c F:\Chernousov\labs2\Sem4\COM\1\dll\VectorPotenoteTaskFactory_.cpp
<<

# Object files for target 1
1_OBJECTS = \
"CMakeFiles\1.dir\main.cpp.obj" \
"CMakeFiles\1.dir\servs\serv.cpp.obj" \
"CMakeFiles\1.dir\servs\serv2.cpp.obj" \
"CMakeFiles\1.dir\dll\IUnknown.cpp.obj" \
"CMakeFiles\1.dir\servs\ServerFactory.cpp.obj" \
"CMakeFiles\1.dir\servs\ClientServerWrapper.cpp.obj" \
"CMakeFiles\1.dir\dll\Vector_.cpp.obj" \
"CMakeFiles\1.dir\dll\VectorFactory_.cpp.obj" \
"CMakeFiles\1.dir\dll\ClientVectorWrapper.cpp.obj" \
"CMakeFiles\1.dir\dll\Client.cpp.obj" \
"CMakeFiles\1.dir\ManagerDLL.cpp.obj" \
"CMakeFiles\1.dir\dll\VectorPotenoteTask_.cpp.obj" \
"CMakeFiles\1.dir\dll\VectorPotenoteTaskFactory_.cpp.obj"

# External object files for target 1
1_EXTERNAL_OBJECTS =

1.exe: CMakeFiles\1.dir\main.cpp.obj
1.exe: CMakeFiles\1.dir\servs\serv.cpp.obj
1.exe: CMakeFiles\1.dir\servs\serv2.cpp.obj
1.exe: CMakeFiles\1.dir\dll\IUnknown.cpp.obj
1.exe: CMakeFiles\1.dir\servs\ServerFactory.cpp.obj
1.exe: CMakeFiles\1.dir\servs\ClientServerWrapper.cpp.obj
1.exe: CMakeFiles\1.dir\dll\Vector_.cpp.obj
1.exe: CMakeFiles\1.dir\dll\VectorFactory_.cpp.obj
1.exe: CMakeFiles\1.dir\dll\ClientVectorWrapper.cpp.obj
1.exe: CMakeFiles\1.dir\dll\Client.cpp.obj
1.exe: CMakeFiles\1.dir\ManagerDLL.cpp.obj
1.exe: CMakeFiles\1.dir\dll\VectorPotenoteTask_.cpp.obj
1.exe: CMakeFiles\1.dir\dll\VectorPotenoteTaskFactory_.cpp.obj
1.exe: CMakeFiles\1.dir\build.make
1.exe: CMakeFiles\1.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable 1.exe"
	"C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\1.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100162~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100162~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\link.exe /nologo @CMakeFiles\1.dir\objects1.rsp @<<
 /out:1.exe /implib:1.lib /pdb:F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug\1.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\1.dir\build: 1.exe

.PHONY : CMakeFiles\1.dir\build

CMakeFiles\1.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\1.dir\cmake_clean.cmake
.PHONY : CMakeFiles\1.dir\clean

CMakeFiles\1.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" F:\Chernousov\labs2\Sem4\COM\1 F:\Chernousov\labs2\Sem4\COM\1 F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug F:\Chernousov\labs2\Sem4\COM\1\cmake-build-debug\CMakeFiles\1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\1.dir\depend

