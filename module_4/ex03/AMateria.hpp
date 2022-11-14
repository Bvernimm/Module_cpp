#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class AMateria
{
protected:
	std::string const	_type;
public:
	AMateria (void);
	AMateria (std::string const &type);
	AMateria (const AMateria &other);
	AMateria &operator=(const AMateria &other);
	~AMateria (void);

	std::string const &getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif