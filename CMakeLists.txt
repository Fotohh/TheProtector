cmake_minimum_required(VERSION 3.25)
project(TheProtector LANGUAGES CXX)

add_executable(TheProtector src/main.cpp)

target_compile_features(
	TheProtector
	PRIVATE
	cxx_std_20
)
if(MSVC)
	target_compile_options(
		TheProtector
		PRIVATE
		/W4
		/permissive-
	)
endif()