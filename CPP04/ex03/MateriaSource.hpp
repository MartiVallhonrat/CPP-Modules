#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource: IMateriaSource
{
private:
	AMateria *_materias[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	~MateriaSource();

	MateriaSource	&operator=(const MateriaSource &other);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif
