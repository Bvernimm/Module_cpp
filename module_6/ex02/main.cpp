#include "Identify.hpp"

int	main(void)
{
	Base	*RandomClass;

	RandomClass = generate();
	identify (RandomClass);
	identify (*RandomClass);

	delete	RandomClass;

	return (0);
}