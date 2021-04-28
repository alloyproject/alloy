cmake_minimum_required(VERSION 2.8.6)

execute_process(
  COMMAND git log -1 --pretty=format:%h
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE VERSION
  )

add_definitions(-DGIT_REVISION="${VERSION}")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_SKIP_INSTALL_RULES ON)
set(CMAKE_SKIP_PACKAGE_ALL_DEPENDENCY ON)
set(CMAKE_SUPPRESS_REGENERATION ON)

project(Alloy)

find_package(Boost REQUIRED COMPONENTS program_options filesystem )
find_package (Threads)
find_library(ROCKS_CFG_LIBRARIES rocksdb)
find_package(PkgConfig REQUIRED)

#pkg_check_modules(UPNPC_CFG libupnpp)
pkg_check_modules(UPNPC_CFG miniupnpc)
#pkg_check_modules(SQLITE_CFG sqlite3)
#pkg_check_modules(SQLITECPP_CFG libSQLiteCpp)
#pkg_check_modules(GUTID_CFG libgutid)
#pkg_check_modules(PLOG_CFG plogger)
#pkg_check_modules(PILGTH_CFG pilgthreads)
#add_executable(messagebussrv ${MESSAGEBUS_SERVER_SOURCE} )
#target_include_directories(messagebussrv PUBLIC ${RPCGEN_CFG_INCLUDE_DIRS} ${SQLITECPP_CFG_INCLUDE_DIRS} ${GUTID_CFG_INCLUDE_DIRS} ${SQLITE_CFG_INCLUDE_DIRS})
#target_link_libraries(messagebussrv ${RPCGEN_CFG_LIBRARIES} ${LOG4CXX_CFG_LIBRARIES} ${SQLITECPP_CFG_LIBRARIES} ${GUTID_CFG_LIBRARIES} ${SQLITE_CFG_LIBRARIES})
#target_compile_options(messagebussrv PUBLIC ${RPCGEN_CFG_CFLAGS} ${LOG4CXX_CFG_CFLAGS} ${CMAKE_CXX_FLAGS} ${SQLITECPP_CFG_CFLAGS} ${GUTID_CFG_CFLAGS} ${SQLITE_CFG_CFLAGS})
#target_link_directories(messagebussrv PUBLIC ${GUTID_CFG_LIBRARY_DIRS} ${SQLITECPP_CFG_LIBRARY_DIRS} ${SQLITE_CFG_LIBRARY_DIRS})


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -maes -fno-inline")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -maes -fno-inline")

include_directories(include src external "${CMAKE_CURRENT_BINARY_DIR}/version")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/Linux)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/Posix)

add_definitions("-D_DEFAULT_SOURCE -D_GNU_SOURCE")

set(COMMIT_ID_IN_VERSION ON CACHE BOOL "Include commit ID in version")
file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/version")

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in" "${CMAKE_CURRENT_BINARY_DIR}/version/version.h")
add_custom_target(version ALL)

add_subdirectory(src)
