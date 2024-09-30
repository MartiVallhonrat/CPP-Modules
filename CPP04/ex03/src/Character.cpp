# include "../Character.hpp"
# include <cstring>

Character::Character(): _name("default")
{
	for (size_t i = 0; i < 4; i++)
		this->_ineventory[i] = NULL;
	
	std::cout << "Character " << _name \
	<< " constructor called!" << std::endl; 
}

Character::Character(std::string name): _name(name)
{
	for (size_t i = 0; i < 4; i++)
		this->_ineventory[i] = NULL;
	
	std::cout << "Character " << _name \
	<< " constructor called!" << std::endl; 
}

Character::Character(const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		std::memcpy(this->_ineventory,\
		other._ineventory, sizeof(other._ineventory));
	}
	std::cout << "Character " << _name \
	<< " constructor called!" << std::endl;
}

Character	&Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		std::memcpy(this->_ineventory,\
		other._ineventory, sizeof(other._ineventory));
	}
	std::cout << "Character " << _name \
	<< " constructor called!" << std::endl;
	return (*this);
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_ineventory[i] != NULL)
			delete this->_ineventory[i];
	}
	
	std::cout << "Character " << _name \
	<< " destructor called!" << std::endl;
}

std::string	const &Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria *m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_ineventory[i] == NULL)
		{
			for (int j = 0; j < 4; j++)
			{
				if (_ineventory[j] == m)
				{
					std::cerr << "Error: " << &_ineventory[j] << " " << &_ineventory[i] << '\n';
					std::cout << _name << " was unable to equip " << m->getType()\
					<< ", this materia is alredy equiped." << std::endl;
					delete m;
					return;
				}
			}
			
			_ineventory[i] = m;
			std::cout << _name \
			<< " equiped with material " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << _name << " was unable to equip " << m->getType()\
	<< ", the inventory is full." << std::endl;
	delete m;
}

void	Character::unequip(int	idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid idx!" << std::endl;
		return;
	}
	if (_ineventory[idx] != NULL)
	{
		std::cout << _name \
		<< " unequiped " << _ineventory[idx]->getType() \
		<< std::endl;
		AMateria* tmp = _ineventory[idx];
		_ineventory[idx] = NULL;
		delete tmp;
	}
	else
	{
		std::cout\
		<< "There isn't a materia stored in the inventory index "\
		<< idx << std::endl;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid idx!" << std::endl;
		return;
	}
	if (_ineventory[idx] != NULL)
	{
		std::cout << _name << ": ";
		_ineventory[idx]->use(target);
	}
	else
	{
		std::cout\
		<< "There isn't a materia stored in the inventory index "\
		<< idx << std::endl;
	}
}