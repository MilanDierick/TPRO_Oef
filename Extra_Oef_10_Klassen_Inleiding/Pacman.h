#pragma once
#include "Positie.h"

class Pacman
{
public:
	int snelheid;
	int kleur;
	Positie *positie;

	Pacman(const int snelheid, const int kleur, Positie* positie);
};
