cmake_minimum_required(VERSION 3.25)
project(TheProtector LANGUAGES CXX)

find_package(SDL3 CONFIG REQUIRED)

add_executable(TheProtector src/main.cc)

target_compile_features(
	TheProtector
	PRIVATE
	cxx_std_20
)
target_link_libraries(
    TheProtector
    PRIVATE
    SDL3::SDL3
)
if(MSVC)
	target_compile_options(
		TheProtector
		PRIVATE
		/W4
		/permissive-
	)
endif()