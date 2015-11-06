#ifndef CALENDRIER_H
#define CALENDRIER_H

#include <vector>

class Rencontre;
class Club;

typedef std::vector<Rencontre*> 	VectorRen; // Une ensemble de vecteur de type Contrat

class Calendrier
{
    VectorRen _rencontres;
public:
    Calendrier();

    ~Calendrier();
    Calendrier(const Calendrier& other);
    Calendrier& operator=(Calendrier&& other);

//----------------------------------------------------------------- methods for rencontres
    VectorRen getAllRencontre();

	void addRencontre(Rencontre* game);
	void AfficherResultat(Club *club, std::string date);
    void AfficherRencontreForAwayClub(Club *club);
    void AfficherRencontreForHomeClub(Club *club);


};





#endif
