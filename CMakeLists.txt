cmake_minimum_required(VERSION 3.16)
project(Gomoku)

# Ustawiamy typ kompilacji na Debug
set(CMAKE_BUILD_TYPE Debug)

# Dodajemy opcje kompilatora dla trybu debugowania
if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
endif()

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Ścieżki do folderów
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")


include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)
# Ścieżka do folderu zasobów
set(ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")

# Ustalenie zmiennych z plikami źródłowymi i nagłówkowymi
file(GLOB SRC_FILES "${SRC_DIR}/*.cpp")
file(GLOB HEADER_FILES "${INCLUDE_DIR}/*.h")


# Kopiowanie zasobów do folderu wyjściowego
file(COPY ${ASSETS_DIR} DESTINATION ${CMAKE_BINARY_DIR})

# Dodanie folderu include
include_directories(${INCLUDE_DIR})

# Dodanie plików źródłowych
add_executable(Gomoku ${SRC_FILES} ${HEADER_FILES})

# Linkowanie z bibliotekami SFML
target_link_libraries(Gomoku PRIVATE sfml-window sfml-graphics sfml-audio sfml-network sfml-system)
target_compile_features(Gomoku PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET Gomoku
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Gomoku>
        VERBATIM)
endif()

install(TARGETS Gomoku)