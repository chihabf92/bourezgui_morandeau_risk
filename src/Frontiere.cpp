#include "Frontiere.hpp"
#include "Territoire.hpp"

Frontiere::Frontiere()
{
}
Frontiere::Frontiere(Territoire a, Territoire b)
{	
	pays1=a;
	pays2=b;
	type=0;

}
Frontiere::~Frontiere()
{
}
