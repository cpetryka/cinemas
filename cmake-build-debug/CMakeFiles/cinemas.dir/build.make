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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Cezary Petryka\Desktop\cinemas"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Cezary Petryka\Desktop\cinemas\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\cinemas.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\cinemas.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\cinemas.dir\flags.make

CMakeFiles\cinemas.dir\main.cpp.obj: CMakeFiles\cinemas.dir\flags.make
CMakeFiles\cinemas.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Cezary Petryka\Desktop\cinemas\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cinemas.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\cinemas.dir\main.cpp.obj /FdCMakeFiles\cinemas.dir\ /FS -c "C:\Users\Cezary Petryka\Desktop\cinemas\main.cpp"
<<

CMakeFiles\cinemas.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cinemas.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe > CMakeFiles\cinemas.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Cezary Petryka\Desktop\cinemas\main.cpp"
<<

CMakeFiles\cinemas.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cinemas.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\cinemas.dir\main.cpp.s /c "C:\Users\Cezary Petryka\Desktop\cinemas\main.cpp"
<<

CMakeFiles\cinemas.dir\libs\sqlite3.c.obj: CMakeFiles\cinemas.dir\flags.make
CMakeFiles\cinemas.dir\libs\sqlite3.c.obj: ..\libs\sqlite3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Cezary Petryka\Desktop\cinemas\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/cinemas.dir/libs/sqlite3.c.obj"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\cinemas.dir\libs\sqlite3.c.obj /FdCMakeFiles\cinemas.dir\ /FS -c "C:\Users\Cezary Petryka\Desktop\cinemas\libs\sqlite3.c"
<<

CMakeFiles\cinemas.dir\libs\sqlite3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cinemas.dir/libs/sqlite3.c.i"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe > CMakeFiles\cinemas.dir\libs\sqlite3.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Cezary Petryka\Desktop\cinemas\libs\sqlite3.c"
<<

CMakeFiles\cinemas.dir\libs\sqlite3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cinemas.dir/libs/sqlite3.c.s"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\cinemas.dir\libs\sqlite3.c.s /c "C:\Users\Cezary Petryka\Desktop\cinemas\libs\sqlite3.c"
<<

CMakeFiles\cinemas.dir\connection\db_connection.cpp.obj: CMakeFiles\cinemas.dir\flags.make
CMakeFiles\cinemas.dir\connection\db_connection.cpp.obj: ..\connection\db_connection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Cezary Petryka\Desktop\cinemas\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cinemas.dir/connection/db_connection.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\cinemas.dir\connection\db_connection.cpp.obj /FdCMakeFiles\cinemas.dir\ /FS -c "C:\Users\Cezary Petryka\Desktop\cinemas\connection\db_connection.cpp"
<<

CMakeFiles\cinemas.dir\connection\db_connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cinemas.dir/connection/db_connection.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe > CMakeFiles\cinemas.dir\connection\db_connection.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Cezary Petryka\Desktop\cinemas\connection\db_connection.cpp"
<<

CMakeFiles\cinemas.dir\connection\db_connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cinemas.dir/connection/db_connection.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\cinemas.dir\connection\db_connection.cpp.s /c "C:\Users\Cezary Petryka\Desktop\cinemas\connection\db_connection.cpp"
<<

CMakeFiles\cinemas.dir\repository\sources\cinema_repository.cpp.obj: CMakeFiles\cinemas.dir\flags.make
CMakeFiles\cinemas.dir\repository\sources\cinema_repository.cpp.obj: ..\repository\sources\cinema_repository.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Cezary Petryka\Desktop\cinemas\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cinemas.dir/repository/sources/cinema_repository.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\cinemas.dir\repository\sources\cinema_repository.cpp.obj /FdCMakeFiles\cinemas.dir\ /FS -c "C:\Users\Cezary Petryka\Desktop\cinemas\repository\sources\cinema_repository.cpp"
<<

CMakeFiles\cinemas.dir\repository\sources\cinema_repository.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cinemas.dir/repository/sources/cinema_repository.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe > CMakeFiles\cinemas.dir\repository\sources\cinema_repository.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Cezary Petryka\Desktop\cinemas\repository\sources\cinema_repository.cpp"
<<

CMakeFiles\cinemas.dir\repository\sources\cinema_repository.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cinemas.dir/repository/sources/cinema_repository.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\cinemas.dir\repository\sources\cinema_repository.cpp.s /c "C:\Users\Cezary Petryka\Desktop\cinemas\repository\sources\cinema_repository.cpp"
<<

CMakeFiles\cinemas.dir\repository\sources\cinema_room_repository.cpp.obj: CMakeFiles\cinemas.dir\flags.make
CMakeFiles\cinemas.dir\repository\sources\cinema_room_repository.cpp.obj: ..\repository\sources\cinema_room_repository.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Cezary Petryka\Desktop\cinemas\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/cinemas.dir/repository/sources/cinema_room_repository.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\cinemas.dir\repository\sources\cinema_room_repository.cpp.obj /FdCMakeFiles\cinemas.dir\ /FS -c "C:\Users\Cezary Petryka\Desktop\cinemas\repository\sources\cinema_room_repository.cpp"
<<

CMakeFiles\cinemas.dir\repository\sources\cinema_room_repository.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cinemas.dir/repository/sources/cinema_room_repository.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe > CMakeFiles\cinemas.dir\repository\sources\cinema_room_repository.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Cezary Petryka\Desktop\cinemas\repository\sources\cinema_room_repository.cpp"
<<

CMakeFiles\cinemas.dir\repository\sources\cinema_room_repository.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cinemas.dir/repository/sources/cinema_room_repository.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\cinemas.dir\repository\sources\cinema_room_repository.cpp.s /c "C:\Users\Cezary Petryka\Desktop\cinemas\repository\sources\cinema_room_repository.cpp"
<<

CMakeFiles\cinemas.dir\repository\sources\seat_repository.cpp.obj: CMakeFiles\cinemas.dir\flags.make
CMakeFiles\cinemas.dir\repository\sources\seat_repository.cpp.obj: ..\repository\sources\seat_repository.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Cezary Petryka\Desktop\cinemas\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/cinemas.dir/repository/sources/seat_repository.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\cinemas.dir\repository\sources\seat_repository.cpp.obj /FdCMakeFiles\cinemas.dir\ /FS -c "C:\Users\Cezary Petryka\Desktop\cinemas\repository\sources\seat_repository.cpp"
<<

CMakeFiles\cinemas.dir\repository\sources\seat_repository.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cinemas.dir/repository/sources/seat_repository.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe > CMakeFiles\cinemas.dir\repository\sources\seat_repository.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Cezary Petryka\Desktop\cinemas\repository\sources\seat_repository.cpp"
<<

CMakeFiles\cinemas.dir\repository\sources\seat_repository.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cinemas.dir/repository/sources/seat_repository.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\cinemas.dir\repository\sources\seat_repository.cpp.s /c "C:\Users\Cezary Petryka\Desktop\cinemas\repository\sources\seat_repository.cpp"
<<

CMakeFiles\cinemas.dir\repository\sources\movie_repository.cpp.obj: CMakeFiles\cinemas.dir\flags.make
CMakeFiles\cinemas.dir\repository\sources\movie_repository.cpp.obj: ..\repository\sources\movie_repository.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Cezary Petryka\Desktop\cinemas\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/cinemas.dir/repository/sources/movie_repository.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\cinemas.dir\repository\sources\movie_repository.cpp.obj /FdCMakeFiles\cinemas.dir\ /FS -c "C:\Users\Cezary Petryka\Desktop\cinemas\repository\sources\movie_repository.cpp"
<<

CMakeFiles\cinemas.dir\repository\sources\movie_repository.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cinemas.dir/repository/sources/movie_repository.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe > CMakeFiles\cinemas.dir\repository\sources\movie_repository.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Cezary Petryka\Desktop\cinemas\repository\sources\movie_repository.cpp"
<<

CMakeFiles\cinemas.dir\repository\sources\movie_repository.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cinemas.dir/repository/sources/movie_repository.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\cinemas.dir\repository\sources\movie_repository.cpp.s /c "C:\Users\Cezary Petryka\Desktop\cinemas\repository\sources\movie_repository.cpp"
<<

CMakeFiles\cinemas.dir\repository\sources\seance_repository.cpp.obj: CMakeFiles\cinemas.dir\flags.make
CMakeFiles\cinemas.dir\repository\sources\seance_repository.cpp.obj: ..\repository\sources\seance_repository.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Cezary Petryka\Desktop\cinemas\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/cinemas.dir/repository/sources/seance_repository.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\cinemas.dir\repository\sources\seance_repository.cpp.obj /FdCMakeFiles\cinemas.dir\ /FS -c "C:\Users\Cezary Petryka\Desktop\cinemas\repository\sources\seance_repository.cpp"
<<

CMakeFiles\cinemas.dir\repository\sources\seance_repository.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cinemas.dir/repository/sources/seance_repository.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe > CMakeFiles\cinemas.dir\repository\sources\seance_repository.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Cezary Petryka\Desktop\cinemas\repository\sources\seance_repository.cpp"
<<

CMakeFiles\cinemas.dir\repository\sources\seance_repository.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cinemas.dir/repository/sources/seance_repository.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\cinemas.dir\repository\sources\seance_repository.cpp.s /c "C:\Users\Cezary Petryka\Desktop\cinemas\repository\sources\seance_repository.cpp"
<<

# Object files for target cinemas
cinemas_OBJECTS = \
"CMakeFiles\cinemas.dir\main.cpp.obj" \
"CMakeFiles\cinemas.dir\libs\sqlite3.c.obj" \
"CMakeFiles\cinemas.dir\connection\db_connection.cpp.obj" \
"CMakeFiles\cinemas.dir\repository\sources\cinema_repository.cpp.obj" \
"CMakeFiles\cinemas.dir\repository\sources\cinema_room_repository.cpp.obj" \
"CMakeFiles\cinemas.dir\repository\sources\seat_repository.cpp.obj" \
"CMakeFiles\cinemas.dir\repository\sources\movie_repository.cpp.obj" \
"CMakeFiles\cinemas.dir\repository\sources\seance_repository.cpp.obj"

# External object files for target cinemas
cinemas_EXTERNAL_OBJECTS =

cinemas.exe: CMakeFiles\cinemas.dir\main.cpp.obj
cinemas.exe: CMakeFiles\cinemas.dir\libs\sqlite3.c.obj
cinemas.exe: CMakeFiles\cinemas.dir\connection\db_connection.cpp.obj
cinemas.exe: CMakeFiles\cinemas.dir\repository\sources\cinema_repository.cpp.obj
cinemas.exe: CMakeFiles\cinemas.dir\repository\sources\cinema_room_repository.cpp.obj
cinemas.exe: CMakeFiles\cinemas.dir\repository\sources\seat_repository.cpp.obj
cinemas.exe: CMakeFiles\cinemas.dir\repository\sources\movie_repository.cpp.obj
cinemas.exe: CMakeFiles\cinemas.dir\repository\sources\seance_repository.cpp.obj
cinemas.exe: CMakeFiles\cinemas.dir\build.make
cinemas.exe: CMakeFiles\cinemas.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Cezary Petryka\Desktop\cinemas\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable cinemas.exe"
	"C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\cinemas.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\Preview\VC\Tools\MSVC\1427~1.288\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\cinemas.dir\objects1.rsp @<<
 /out:cinemas.exe /implib:cinemas.lib /pdb:"C:\Users\Cezary Petryka\Desktop\cinemas\cmake-build-debug\cinemas.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\cinemas.dir\build: cinemas.exe

.PHONY : CMakeFiles\cinemas.dir\build

CMakeFiles\cinemas.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cinemas.dir\cmake_clean.cmake
.PHONY : CMakeFiles\cinemas.dir\clean

CMakeFiles\cinemas.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\Cezary Petryka\Desktop\cinemas" "C:\Users\Cezary Petryka\Desktop\cinemas" "C:\Users\Cezary Petryka\Desktop\cinemas\cmake-build-debug" "C:\Users\Cezary Petryka\Desktop\cinemas\cmake-build-debug" "C:\Users\Cezary Petryka\Desktop\cinemas\cmake-build-debug\CMakeFiles\cinemas.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\cinemas.dir\depend

