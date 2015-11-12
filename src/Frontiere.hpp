#ifndef FRONTIERE_H
#define FRONTIERE_H

#include <iostream>
#include "Territoire.hpp"

class Frontiere
{
	public :
		Territoire pays1;
		Territoire pays2;
		int type;
		Frontiere();
		Frontiere(Territoire a, Territoire b);
		~Frontiere();
};

#endif
