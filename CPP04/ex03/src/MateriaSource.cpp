# include "../MateriaSource.hpp"
# include <string.h>

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		_materias[i] = NULL;

	std::cout << "Materia source constructed!" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	if (this != &other)
	{
		memcpy(this->_materias,\
		other._materias, sizeof(other._materias));
	}

	std::cout << "Materia source constructed!" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		memcpy(this->_materias,\
		other._materias, sizeof(other._materias));
	}
	std::cout << "Materia source constructed!" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	}

	std::cout << "Materia source destroyed!" << std::endl;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_materias[i] == NULL)
		{
			_materias[i] = m;
			std::cout << m->getType() << \
			" materia learned!" << std::endl;
			return;
		}
	}
	std::cout << "No space to learn a new materia " \
	<< m->getType() << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{	
	for (size_t i = 0; i < 4; i++)
	{
		if (_materias[i] != NULL && _materias[i]->getType() == type)
		{
			std::cout << "Creating materia type: "\
			<< _materias[i]->getType() << std::endl;	
			return (_materias[i]->clone());
		}
	}
	std::cout << "Invalid type of materia!" << std::endl;
	return (0);
}