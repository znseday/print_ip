cmake_minimum_required(VERSION 3.2)

if(WIN32 OR WIN64)
	message(STATUS "My Windows detected")
	project(print_ip VERSION 0.0.1000)
	#set(BOOST_ROOT "C:/Boost")
else()
	project(print_ip VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
endif()

# find_package(Threads REQUIRED)
# find_package(Boost COMPONENTS unit_test_framework REQUIRED)

# add_executable(print_ip main.cpp )

# add_executable(my_tests my_test.cpp)

if(WIN32 OR WIN64)
	#add_library(my_aux my_aux.cpp my_aux.h)
	add_executable(print_ip main.cpp my_aux.h)
else()
	#add_library(my_aux my_aux.cpp)
	add_executable(print_ip main.cpp )
endif()

if(WIN32 OR WIN64)
        set_target_properties(print_ip PROPERTIES
		CXX_STANDARD 17
		CXX_STANDARD_REQUIRED ON)
else()
        set_target_properties(print_ip PROPERTIES
		CXX_STANDARD 17
		CXX_STANDARD_REQUIRED ON
		COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra")
endif()

#set_target_properties(my_tests PROPERTIES
#    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
#    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
#)

#target_link_libraries(print_ip
#	my_aux
#    Threads::Threads
#)

#target_link_libraries(my_tests
#    ${Boost_LIBRARIES}
#    my_aux
#)

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT znseday@yandex.com)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

#enable_testing()

#add_test(my_tests_ my_tests)
