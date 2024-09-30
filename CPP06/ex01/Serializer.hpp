#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>
# include <iostream>

typedef struct s_Data
{
	int	someData;
}	Data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &other);
	~Serializer();

	Serializer &operator=(const Serializer &other);

public:
	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);
};

#endif