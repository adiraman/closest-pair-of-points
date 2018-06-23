#include <cstdlib>
#include <ctime>
#include "closestPair.h"

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <no. of points> <low val> <high val>" << std::endl;
        return 0;
    }

	srand (static_cast <unsigned> (time(nullptr)));

	double LO = atof(argv[2]);
	double HI = atof(argv[3]);
	int n = atoi(argv[1]);
	pointVec a(n);
	for(int i=0; i<n; ++i)
	{
	    a[i].x = LO + static_cast<double> (rand()/(static_cast<double> (RAND_MAX/(HI-LO))));
	    a[i].y = LO + static_cast<double> (rand()/(static_cast<double> (RAND_MAX/(HI-LO))));
	}

	std::cout << "---------------------------------------------------------------" << std::endl;
	ptDistPair b = closestPair(a);

    std::cout << " Given Points: ";
    printPoints(a);
    std::cout << std::endl;

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "O(nlogn) Algorithm ..." << std::endl;
	std::cout << " The closest pair is : ";
	std::cout << "(" << b.first.first.x << ", " << b.first.first.y << ")" << " and " << "(" << b.first.second.x << ", " << b.first.second.y << ")" << std::endl;
	std::cout << "With distance : " << b.second << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "Brute force O(n2) ..." << std::endl;

	//pointVec c = bruteForce(a);
	ptDistPair c = bruteForce(a);
	std::cout << " The closest pair is : ";
	std::cout << "(" << c.first.first.x << ", " << c.first.first.y << ")" << " and " << "(" << c.first.second.x << ", " << c.first.second.y << ")" << std::endl;
	std::cout << "With distance : " << c.second << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

    return 0;
}

