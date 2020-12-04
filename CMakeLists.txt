cmake_minimum_required(VERSION 3.5)

project(FastFourierTransform)

file(GLOB HEADERS "${PROJECT_SOURCE_DIR}/*.h")
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/*.cpp")

add_executable(fft_multiply ${SOURCES} ${HEADERS})
set_target_properties(
	fft_multiply PROPERTIES
	CXX_STANDART 17
	CXX_STANDART_REQUIRED ON
)
