#include "../GuillotineBinPack.h"
#include <cstdio>


int main(int argc, char **argv)
{
	
	if (argc < 5 || argc % 2 != 1)
	{
		printf("Usage: GuillotineBinPackTest binWidth binHeight w_0 h_0 w_1 h_1 w_2 h_2 ... w_n h_n\n");
		printf("       where binWidth and binHeight define the size of the bin.\n");
		printf("       w_i is the width of the i'th rectangle to pack, and h_i the height.\n");
		printf("Example: GuillotineBinPackTest 256 256 30 20 50 20 10 80 90 20\n");
		return 0;
	}
	
	using namespace rbp;
	
	// Create a bin to pack to, use the bin size from command line.
	GuillotineBinPack bin;
	int binWidth = atoi(argv[1]);
	int binHeight = atoi(argv[2]);
	printf("Initializing bin to size %dx%d.\n", binWidth, binHeight);
	bin.Init(binWidth, binHeight);
	
	// Pack each rectangle (w_i, h_i) the user inputted on the command line.
	for(int i = 3; i < argc; i += 2)
	{
		// Read next rectangle to pack.
		int rectWidth = atoi(argv[i]);
		int rectHeight = atoi(argv[i+1]);
		printf("Packing rectangle of size %dx%d: ", rectWidth, rectHeight);

		// Perform the packing.
		GuillotineBinPack::FreeRectChoiceHeuristic heuristicChoice = GuillotineBinPack::RectBestAreaFit; // This can be changed individually even for each rectangle packed.
		GuillotineBinPack::GuillotineSplitHeuristic heuristicSplit = GuillotineBinPack::SplitShorterLeftoverAxis; // This can be changed individually even for each rectangle packed.
                bool rectMerge = false;
		Rect packedRect = bin.Insert(rectWidth, rectHeight, rectMerge, heuristicChoice, heuristicSplit);

		// Test success or failure.
		if (packedRect.height > 0)
			printf("Packed to (x,y)=(%d,%d), (w,h)=(%d,%d). Free space left: %.2f%%\n", packedRect.x, packedRect.y, packedRect.width, packedRect.height, 100.f - bin.Occupancy()*100.f);
		else
			printf("Failed! Could not find a proper position to pack this rectangle into. Skipping this one.\n");
	}
	printf("Done. All rectangles packed.\n");
}
