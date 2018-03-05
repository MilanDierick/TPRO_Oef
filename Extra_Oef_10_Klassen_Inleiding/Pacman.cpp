#include "Pacman.h"

Pacman::Pacman(const int snelheid, const int kleur, Positie* positie): snelheid(snelheid),
                                                                       kleur(kleur),
                                                                       positie(positie)
{}

int Pacman::getSnelheid() const
{
	return snelheid;
}

void Pacman::setSnelheid(const int snelheid)
{
	this->snelheid = snelheid;
}

int Pacman::getKleur() const
{
	return kleur;
}

void Pacman::setKleur(const int kleur)
{
	this->kleur = kleur;
}

Positie* Pacman::getPositie() const
{
	return positie;
}

void Pacman::setPositie(Positie* const positie)
{
	this->positie = positie;
}
