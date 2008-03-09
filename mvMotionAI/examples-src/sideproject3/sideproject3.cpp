#include <mv/mvMotionAI.h>
#include <lf/Lightfeather.h>
#include <iostream>

int main()
{
	mvVec3 temp;

	std::cout << "HELLO WORLD" << std::endl;
	temp.components = lf::core::UNIT_X;
	std::cout << "HELLO WORLD " << temp.getX()
		<< " " << temp.getY()
		<< " " << temp.getZ() << std::endl;

	return 0;
}
