# Makefile
# copyright 2013, Stefan Beller
# copyright 2019, Jongmin Kim
# This file is also public domain.

CXX = g++
# If you want to compile it faster try these options (gcc only)
# CPPFLAGS = -march=native -mtune=native -Ofast -g -flto -Wall -Wextra
# LDFLAGS = -march=native -mtune=native -Ofast -g -flto -fwhole-program

all: ready shelf guillotine maxrects skyline

ready:
	mkdir -p out

shelf: ShelfBinPackTest/BinPack.o ShelfBinPack.o ShelfNextFitBinPack.o GuillotineBinPack.o Rect.o
	$(CXX) $(CPPFLAGS) $(LDFLAGS) ShelfBinPackTest/BinPack.o ShelfBinPack.o ShelfNextFitBinPack.o GuillotineBinPack.o Rect.o -o out/ShelfBinPackTest

guillotine: GuillotineBinPackTest/BinPack.o GuillotineBinPack.o Rect.o
	$(CXX) $(CPPFLAGS) $(LDFLAGS) GuillotineBinPackTest/BinPack.o GuillotineBinPack.o Rect.o -o out/GuillotineBinPackTest

maxrects: MaxRectsBinPackTest/BinPack.o MaxRectsBinPack.o Rect.o
	$(CXX) $(CPPFLAGS) $(LDFLAGS) MaxRectsBinPackTest/BinPack.o MaxRectsBinPack.o Rect.o -o out/MaxRectsBinPackTest

skyline:  SkylineBinPackTest/BinPack.o SkylineBinPack.o GuillotineBinPack.o Rect.o
	$(CXX) $(CPPFLAGS) $(LDFLAGS) SkylineBinPackTest/BinPack.o SkylineBinPack.o GuillotineBinPack.o Rect.o -o out/SkylineBinPackTest

clean: 
	rm -f *.o
	rm -f *Test/*.o
	rm -f out/MaxRectsBinPackTest
	rm -f out/ShelfBinPackTest
	rm -rf out
