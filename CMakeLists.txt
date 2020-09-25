#
# Created by vmodev on 18/02/2020.
#
cmake_minimum_required(VERSION 3.15)
project(twain_rabbitmq_client)

set(TWAIN_CLIENT twain)
set(TWAIN_SERVICE twain_service)
set(TWAIN_TEST TWAIN_TEST)

set(CMAKE_CXX_STANDARD 14)

set(PACKAGE_AUTHOR "Chung Hoang")

add_definitions(-DHAVE_CONFIG_H)

if (APPLE)
    # This is a bug in CMake that causes it to prefer the system version over
    # the one in the specified ROOT folder.
    set(OPENSSL_ROOT_DIR ${OPENSSL_ROOT_DIR} /usr/local/Cellar/openssl@1.1/1.1.1g/)
    set(OPENSSL_CRYPTO_LIBRARY ${OPENSSL_ROOT_DIR}/lib/libcrypto.dylib CACHE FILEPATH "" FORCE)
    set(OPENSSL_SSL_LIBRARY ${OPENSSL_ROOT_DIR}/lib/libssl.dylib CACHE FILEPATH "" FORCE)
endif ()

find_package(cpprestsdk)

# Do not build rabbitmq-c example
#set(BUILD_EXAMPLES OFF)
# Do not build rbbitmq-c test
#set(BUILD_TESTS OFF)
#Do not build test for json lib
#set(JSON_BuildTests OFF)
#Dot not build install for json lib
#set(JSON_Install OFF)

# Add rabbitmq-c and json library to project
add_subdirectory(rabbitmq-c)

# Load header files from include folder and rabbitmq-c library
include_directories(${CMAKE_SOURCE_DIR}/twain/include ${CMAKE_SOURCE_DIR}/rabbitmq-c/librabbitmq ${CMAKE_SOURCE_DIR}/twain_service/include ${CMAKE_SOURCE_DIR}/twain_rabbitmq_service/include ${CMAKE_SOURCE_DIR}/twain_rest_service/include)
#link_directories(${CMAKE_SOURCE_DIR}/cpprestsdk/Release/include)
# Load all files .cpp and .c to build
file(GLOB TWAIN_RABBITMQ_SOURCES ${CMAKE_SOURCE_DIR}/twain_rabbitmq_service/src/**.cpp ${CMAKE_SOURCE_DIR}/twain_rabbitmq_service/src/**.c)

file(GLOB TWAIN_SERVICE_SOURCES ${CMAKE_SOURCE_DIR}/twain_service/src/**.cpp ${CMAKE_SOURCE_DIR}/twain_service/src/**.c)

file(GLOB TEST_TWAIN_SERVICE_SOURCES ${CMAKE_SOURCE_DIR}/test/src/**.cpp ${CMAKE_SOURCE_DIR}/test/src/**.c)

file(GLOB TWAIN_CLIENT_SOURCES ${CMAKE_SOURCE_DIR}/twain/src/**.cpp ${CMAKE_SOURCE_DIR}/twain/src/**.c)

file(GLOB TWAIN_REST_SERVICE_SOURCES ${CMAKE_SOURCE_DIR}/twain_rest_service/src/**.cpp ${CMAKE_SOURCE_DIR}/twain_rest_service/src/**.c)

add_executable(${TWAIN_CLIENT} ${TWAIN_REST_SERVICE_SOURCES} ${TWAIN_CLIENT_SOURCES})
add_executable(${TWAIN_SERVICE} ${TWAIN_RABBITMQ_SOURCES} ${TWAIN_SERVICE_SOURCES})
add_executable(${TWAIN_TEST} ${TEST_TWAIN_SERVICE_SOURCES} ${TWAIN_RABBITMQ_SOURCES})
# Link rabbitmq-c library to project

target_link_libraries(${TWAIN_CLIENT} cpprest rabbitmq)
target_link_libraries(${TWAIN_SERVICE} cpprest rabbitmq)
target_link_libraries(${TWAIN_TEST} cpprest rabbitmq)

install(TARGETS ${TWAIN_CLIENT} ${TWAIN_SERVICE}
        RUNTIME DESTINATION bin
        )
