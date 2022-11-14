#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice
{
protected:
	
public:
	Ice (void);
	Ice (const Ice &other);
	Ice &operator=(const Ice &other);
	~Ice (void);

	Ice* clone() const;
	void use(ICharacter& target);
};

#endif