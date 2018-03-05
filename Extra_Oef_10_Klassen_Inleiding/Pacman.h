#pragma once
#include "Positie.h"

class Pacman
{
public:
	Pacman(const int snelheid, const int kleur, Positie* positie);

	int getSnelheid() const;
	void setSnelheid(const int snelheid);
	int getKleur() const;
	void setKleur(const int kleur);
	Positie* getPositie() const;
	void setPositie(Positie* const positie);

private:
	int snelheid;
	int kleur;
	Positie *positie;
};
