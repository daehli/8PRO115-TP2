#ifndef CLUB_H
#define CLUB_H

#include <vector>
#include <string>
#include "utils.h"
class Contrat;
class Palmares;
class Rupture;
class Joueur;
class Person;
class Calendrier;
class Ligue;
struct Date;


typedef std::vector<Palmares*>	VectorPal; // Une ensemble de vecteur de type Palmares
typedef std::vector<Contrat*> 	VectorCon; // Une ensemble de vecteur de type Contrat
typedef std::vector<Rupture*> 	VectorRup; // Une ensemble de vecteur de type Rupture
typedef std::vector<Person*>  	VectorPrs; // Une ensemble de vecteur de type Person


// Classe Club
class Club {

private:
	std::string 			histoireDuClub;
	std::string 			couleurDuClub;
	std::string 			adresseDuClub;
	std::string 			villeDuClub;
	Date 					anneeDeCreation;
	VectorPrs				effectif;
	VectorPal			 	unPalmares;
	VectorPrs			 	staffTechnique;
	VectorCon 				contratsdEngagement;
	VectorRup 				rupturesDeContrats;
	Calendrier*				_calendrier;
	Ligue*					_ligue;


public:
    Club(std::string history, std::string color, std::string address, std::string town, std::string year);

    ~Club();
    Club(const Club& other);
    Club(Club&& other);
    Club& operator=(const Club& other);
    Club& operator=(Club&& other);

//----------------------------------------------------------------- methods for HistoireDuClub
	std::string getHistoireDuClub();
	void setHistoireDuClub(std::string history);

//----------------------------------------------------------------- methods for CouleurDuClub
	std::string getCouleurDuClub();
	void setCouleurDuClub(std::string color);

//----------------------------------------------------------------- methods for AnneeDeCreation
	Date getAnneeDeCreation();
	void setAnneeDeCreation (Date year);

//----------------------------------------------------------------- methods for Effectif

	VectorPrs getEffectif();
	void addEffectif(Joueur *someone);
	void setEffectif(VectorPrs players);

//----------------------------------------------------------------- methods for unPalmares
	VectorPal getUnPalmares();

	void addUnPalmares(Palmares *trophy);

	void setUnPalmares(VectorPal trophies);

//----------------------------------------------------------------- methods for VilleDuClub
	std::string getVilleDuClub();
	void setVilleDuClub(std::string town);

//----------------------------------------------------------------- methods for VilleDuClub
	std::string getAdresseDuClub();
	void setAdresseDuClub(std::string address);

//----------------------------------------------------------------- methods for StaffTechnique
	VectorPrs getStaffTechnique() {
		return staffTechnique;
	}

	void addStaffTechnique(Person *someone);

	void deleteStaffTechnique(Person *someone);

	void setStaffTechnique(VectorPrs staff);

//----------------------------------------------------------------- methods for ContratsdEngagement
	VectorCon getContratsdEngagement(VectorCon &contrats) {
		return contratsdEngagement;
	}

	void addContratdEngagement(Contrat *contrats);

	void deleteContratdEngagement(Contrat *contrats);

	void afficherContratEngagement();

	Contrat* rechercherContratdEngagement(Joueur *joueur);

//----------------------------------------------------------------- methods for RupturesDeContrats
	VectorRup getRupturesDeContrats() {
		return rupturesDeContrats;
	}

	void addRuptureDeContrats(Rupture *ruptures);

	void deleteRupturesDeContrats(Rupture *ruptures);

	void setRupturesDeContrats(VectorRup ruptures);

//----------------------------------------------------------------- methods for Montant
	void montantEncaisseDepuisUneDate(std::string date);


//----------------------------------------------------------------- methods for calendrier
	Calendrier* getCalendrier() {
		return _calendrier;
	}

	void setCalendrier(Calendrier* schedul) {
		_calendrier = schedul;
	}
//----------------------------------------------------------------- methods for ligue
	Ligue* getLigue() {
		return _ligue;
	}

//----------------------------------------------------------------- methods of Club
    void CreerJoueur();
    void ModifierJoueur();
    void SupprimerJoueur(std::string name);
    void AfficherEffectif();

    void AfficherCalendrier();

    void TransfertJoueur(Joueur* joueur, Club* club);
	void AfficherMontantTransferts(std::string date);

};

#endif
