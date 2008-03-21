#include <mv/mvMotionAI.h>
#include <iostream>
#include <mvWorldInterface.h>

void printBeta()
{
	std::cout << "Beta" << std::endl;
}


DECLARE_WORLD_FUNC(Alpha);

int main(void)
{
	WORLD_FUNC("BROWN");
	printBeta();

   return EXIT_SUCCESS;
}
