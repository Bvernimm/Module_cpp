#include "data.hpp"

int	main(void)
{
	Data		*dataPtr = new Data;;
	Data		*newDataPtr;
	uintptr_t	raw;

	dataPtr->intDataMember = 42;
	dataPtr->strDataMember = "Hello !";

	std::cout << "Data int member = " << dataPtr->intDataMember << std::endl;
	std::cout << "Data str member = " << dataPtr->strDataMember << std::endl;
	raw = serialize(dataPtr);
	newDataPtr = deserialize(raw);
	std::cout << "NewData int member = " << newDataPtr->intDataMember << std::endl;
	std::cout << "NewData str member = " << newDataPtr->strDataMember << std::endl;

	delete dataPtr;
	//delete newDataPtr;

	return (0);
}