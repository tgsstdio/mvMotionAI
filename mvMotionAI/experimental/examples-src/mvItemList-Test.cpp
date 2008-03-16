#include <mv/mvMotionAI.h>
#include MV_POINTER_LIST_HEADER_FILE_H_
#include <iostream>

int main()
{
	char* pointer = "STRING";
	char* pt2 = "BRA";

	mvPointerList<char*,const char*> items;

	items.addItem(pointer);

	std::cout << "No of Items : " << items.getNoOfItems() << std::endl;

	char testLetter = 'A';

	items.setAutoConvertIndex(false);
	for (int i = -5; i < 10; i++)
	{
		std::cout << testLetter  << ": Auto Index [" << items.getAutoConvertFlag() << "] conversion (" << i
			<< ") = " <<  items.convertIndex(i) << std::endl;
	}

	testLetter = 'B';
	items.setAutoConvertIndex(true);
	for (int i = -5; i < 10; i++)
	{
		std::cout << testLetter  << ": Auto Index [" << items.getAutoConvertFlag() << "] conversion (" << i
			<< ") = " <<  items.convertIndex(i) << std::endl;
	}
	std::cout << "B : No of Items : " << items.getNoOfItems() << std::endl;
	items.addItem(pt2);
	std::cout << "C : No of Items : " << items.getNoOfItems() << std::endl;

	testLetter = 'C';
	items.setAutoConvertIndex(false);
	for (int i = -5; i < 10; i++)
	{
		std::cout << testLetter  << ": Auto Index [" << items.getAutoConvertFlag() << "] conversion (" << i
			<< ") = " <<  items.convertIndex(i) << std::endl;
	}

	testLetter = 'D';
	items.setAutoConvertIndex(true);
	for (int i = -5; i < 10; i++)
	{
		std::cout << testLetter  << ": Auto Index [" << items.getAutoConvertFlag() << "] conversion (" << i
			<< ") = " <<  items.convertIndex(i) << std::endl;
	}

	testLetter = 'E';
	items.setAutoConvertIndex(false);
	for (int i = -5; i < 10; i++)
	{
		std::cout << testLetter  << ": Auto Index [" << items.getAutoConvertFlag() << "] conversion (" << i
			<< ") = ";
		std::cout << (items.getClassPtr(i) ? "VALID"  : "NULL") << std::endl;

	}

	testLetter = 'F';
	items.setAutoConvertIndex(true);
	for (int i = -5; i < 10; i++)
	{
		std::cout << testLetter  << ": Auto Index [" << items.getAutoConvertFlag() << "] conversion (" << i
			<< ") = ";
		std::cout << (items.getClassPtr(i) ? "VALID"  : "NULL") << std::endl;
	}

	std::cout << "F : No of Items : " << items.getNoOfItems() << std::endl;
	items.deleteItem(-1);
	std::cout << "G : No of Items : " << items.getNoOfItems() << std::endl;

	testLetter = 'G';
	items.setAutoConvertIndex(false);
	for (int i = -5; i < 10; i++)
	{
		std::cout << testLetter  << ": Auto Index [" << items.getAutoConvertFlag() << "] conversion (" << i
			<< ") = ";
		std::cout << (items.getClassPtr(i) ? "VALID"  : "NULL") << std::endl;

	}

	testLetter = 'H';
	items.setAutoConvertIndex(true);
	for (int i = -5; i < 10; i++)
	{
		std::cout << testLetter  << ": Auto Index [" << items.getAutoConvertFlag() << "] conversion (" << i
			<< ") = ";
		std::cout << (items.getClassPtr(i) ? "VALID"  : "NULL") << std::endl;
	}


   return EXIT_SUCCESS;
}
