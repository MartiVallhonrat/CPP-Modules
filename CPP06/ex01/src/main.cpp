# include "../Serializer.hpp"

int main(void)
{
	Data	firstPtr;
	uintptr_t	somePtr;
	Data	*secondPtr;
	//Serializer test;

	firstPtr.someData = 3;

	somePtr = Serializer::serialize(&firstPtr);
	secondPtr = Serializer::deserialize(somePtr);

	std::cout << "firstPtr.someData: " << firstPtr.someData << '\n' \
	<< "secondPtr.someData: " << secondPtr->someData << '\n';

	return (0);
}
