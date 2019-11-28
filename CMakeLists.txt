cmake_minimum_required(VERSION 3.15)
project(RectangleBinPack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(ShelfBinPackTest ShelfBinPackTest/BinPack.cpp ShelfBinPack.cpp ShelfNextFitBinPack.cpp GuillotineBinPack.cpp Rect.cpp)
add_executable(GuillotineBinPackTest GuillotineBinPackTest/BinPack.cpp GuillotineBinPack.cpp Rect.cpp)
add_executable(MaxRectsBinPackTest MaxRectsBinPackTest/BinPack.cpp MaxRectsBinPack.cpp Rect.cpp)
add_executable(SkylineBinPackTest SkylineBinPackTest/BinPack.cpp SkylineBinPack.cpp GuillotineBinPack.cpp Rect.cpp)
