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
CMAKE_SOURCE_DIR = F:\Chernousov\labs2\6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Chernousov\labs2\6\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\6.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\6.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\6.dir\flags.make

CMakeFiles\6.dir\main.cpp.obj: CMakeFiles\6.dir\flags.make
CMakeFiles\6.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Chernousov\labs2\6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/6.dir/main.cpp.obj"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\6.dir\main.cpp.obj /FdCMakeFiles\6.dir\ /FS -c F:\Chernousov\labs2\6\main.cpp
<<

CMakeFiles\6.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/6.dir/main.cpp.i"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe > CMakeFiles\6.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Chernousov\labs2\6\main.cpp
<<

CMakeFiles\6.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/6.dir/main.cpp.s"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\6.dir\main.cpp.s /c F:\Chernousov\labs2\6\main.cpp
<<

# Object files for target 6
6_OBJECTS = \
"CMakeFiles\6.dir\main.cpp.obj"

# External object files for target 6
6_EXTERNAL_OBJECTS =

6.exe: CMakeFiles\6.dir\main.cpp.obj
6.exe: CMakeFiles\6.dir\build.make
6.exe: CMakeFiles\6.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Chernousov\labs2\6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 6.exe"
	"C:\Program Files\JetBrains\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\6.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100162~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100162~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1411~1.255\bin\HostX86\x86\link.exe /nologo @CMakeFiles\6.dir\objects1.rsp @<<
 /out:6.exe /implib:6.lib /pdb:F:\Chernousov\labs2\6\cmake-build-debug\6.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\6.dir\build: 6.exe

.PHONY : CMakeFiles\6.dir\build

CMakeFiles\6.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\6.dir\cmake_clean.cmake
.PHONY : CMakeFiles\6.dir\clean

CMakeFiles\6.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" F:\Chernousov\labs2\6 F:\Chernousov\labs2\6 F:\Chernousov\labs2\6\cmake-build-debug F:\Chernousov\labs2\6\cmake-build-debug F:\Chernousov\labs2\6\cmake-build-debug\CMakeFiles\6.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\6.dir\depend

