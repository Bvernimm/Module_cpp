#include "easyfind.hpp"

int	main(void)
{
	std::list<int>	lst;
	std::list<int>::iterator ite;

	lst.push_back(10);
	lst.push_back(23);
	lst.push_back(3);
	lst.push_back(17);
	lst.push_back(20);

	ite = easyfind(lst, 3);
	if (ite != lst.end())
		std::cout << "Element found in lst: " << *ite << std::endl;
	else
		std::cout << "Element not found in lst" << std::endl;
	

	int myints[] = { 10, 23, 3, 17, 20 };
	std::vector<int> myvector (myints,myints+5);
	std::vector<int>::iterator it;

	it = easyfind (myvector, 20);
	if (it != myvector.end())
		std::cout << "Element found in myvector: " << *it << std::endl;
	else
		std::cout << "Element not found in myvector" << std::endl;

	return 0;
}