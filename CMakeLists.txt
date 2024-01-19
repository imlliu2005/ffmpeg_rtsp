cmake_minimum_required(VERSION 3.5) # CMake install : https://cmake.org/download/
project(main_window LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "c:/Qt/Qt5.14.2/5.14.2/msvc2017_64") # Qt Kit Dir
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5 COMPONENTS Widgets REQUIRED) # Qt COMPONENTS
aux_source_directory(./src srcs)

# Specify MSVC UTF-8 encoding   
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

include_directories(
    ${PROJECT_SOURCE_DIR}/include 
)
message(STATUS "lkmao:PROJECT_SOURCE_DIR -- ${PROJECT_SOURCE_DIR}")
link_directories(${PROJECT_SOURCE_DIR}/lib)


add_executable(${PROJECT_NAME}
    WIN32 # If you need a terminal for debug, please comment this statement 
    ${srcs} 
) 
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets avcodec avformat avutil swresample swscale avfilter) # Qt5 Shared Library


#设置编译链接的 FFMPEG 库 , 需要把 FFMPEG 的库都配置到下面
#注意 使用 002_FFMPEG 的前提是 , 该项目必须在 002_FFMPEG 配置后面进行配置
target_link_libraries(
	${PROJECT_NAME} PRIVATE	#本项目的解决方案名称
    Qt5::Widgets    #qt Widget
	avcodec		    #音视频编码核心库 , 用于音视频或图片编解码
	avdevice	    #硬件采集 , 加速 , 显示 库
	avfilter	    #音视频滤波器
	avformat	    #音视频封装格式生成或解析 
	avutil		    #该库中封装了一些公共的工具函数
	postproc	    #封装了同步, 时间计算的简单算法
	swresample	    #音视频编解码格式预设
	swscale		    #原始视频格式转换库
)