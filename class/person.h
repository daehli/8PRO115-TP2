#ifndef PERSON_H
#define PERSON_H

//http://stackoverflow.com/questions/18335861/why-is-enum-class-preferred-over-plain-enum
//http://stackoverflow.com/questions/18026877/does-not-name-a-type-error-but-class-pointer-already-has-forward-declaration
#include "contract.h"
#include "rupture.h"
class Palmares;
class Contract;

typedef std::vector<Palmares*>	VectorPal; // Une ensemble de vecteur de type Palmares


class Person {

protected:
    std::string     _prenom;
    std::string     _nom;
    int             _age;
    Role            _role;


public:
    Person(std::string prenom,std::string nom, int age,Role role): _prenom(prenom),_nom(nom),_age(age),_role(role){};

    virtual ~Person();
    Person(const Person& other);
    Person(Person&& other);
    virtual Person& operator=(const Person& other);
    virtual Person& operator=(Person&& other);


//----------------------------------------------------------------- methods of prenom
    virtual std::string getFirstName(){
        return _prenom;
    }

	virtual void setFirstName(std::string firstName){
		_prenom = firstName;
    }

//----------------------------------------------------------------- methods of nom
    virtual std::string getLastName(){
        return _nom;
    }

    virtual void setLastName(std::string lastName){
		_nom = lastName;
    }
//----------------------------------------------------------------- methods of age
	virtual int getAge() {
		return _age;
	}

	virtual void setAge(int nb){
		_age = nb;
	}

//----------------------------------------------------------------- methods of role
	virtual Role getRole() {
		return _role;
	}

	virtual void setRole(Role choix){
		_role = choix;
	}

//----------------------------------------------------------------- methods for Person
	virtual std::string obtenirNP() {
		return _prenom+" "+_nom;
	}
};



class Joueur : public Person {

protected:
    float _taille;
    float _poids;
    std::string _emplacementNaissance;

public:
	Joueur(std::string prenom,std::string nom, int age,float taille,float poids,std::string emplacementNaissance):
        Person(prenom,nom,age,JOUEUR),_taille(taille),_poids(poids),_emplacementNaissance(emplacementNaissance){};

    Joueur(std::string prenom,std::string nom, int age):Person(prenom,nom,age,JOUEUR){};

    virtual ~Joueur();
    Joueur(const Joueur& other);
    Joueur(Joueur&& other);
    virtual Joueur& operator=(const Joueur& other);
    virtual Joueur& operator=(Joueur&& other);

//----------------------------------------------------------------- methods for FirstName



        std::string getFirstName(){

            return _prenom;
        }

        void setFirstName(std::string firstName){

            _prenom = firstName;

        }

//----------------------------------------------------------------- methods for LastName

        std::string getLastName(){

            return _nom;
        }

        void setLastName(std::string lastName){

           _prenom = lastName;

        }
//----------------------------------------------------------------- methods for Taille
    float getTaille(){
        return _taille;
    }

    void setTaille(float grandeur){
        _taille = grandeur;
    }

//----------------------------------------------------------------- methods of poids
    float getPoids(){
        return _poids;
    }

    void setPoids(float grosseur){
        _poids = grosseur;
    }

//----------------------------------------------------------------- methods of emplacementNaissance
    std::string getEmplacementNaissance(){
        return _emplacementNaissance;
    }


    void setEmplacementNaissance(std::string birthPlace){
        _emplacementNaissance = birthPlace;
    }
};


class Joueur_Autonome : public Joueur{

public:
	Joueur_Autonome(std::string prenom,std::string nom, int age,float taille,float poids,std::string emplacementNaissance):
		Joueur(prenom, nom, age, taille, poids, emplacementNaissance) {}

    virtual ~Joueur_Autonome();
    Joueur_Autonome(const Joueur_Autonome& other);
    Joueur_Autonome(Joueur_Autonome&& other);
    virtual Joueur_Autonome& operator=(const Joueur_Autonome& other);
    virtual Joueur_Autonome& operator=(Joueur_Autonome&& other);

//----------------------------------------------------------------- methods of Joueur_Autonome
	void RompreSonContrat(Contract* leContrat){
		std::string raisonDuDepart, choisirClub;
        float penalite;

        if(this == leContrat->getJoueurContractant()){
            std::string raisonDuDepart;
            float penalite;

            std::cout << "*******************ROMPRE LE CONTRAT DU JOUEUR*******************" << std::endl;
            std::cout << std::endl <<  "//		RAISON DU DEPART : "; std::cin >> raisonDuDepart;
            std::cout << std::endl <<  "//		PENALITE DE DEPART : "; std::cin >> penalite;
			std::cout << std::endl << "//		CHOISIR NOUVELLE EQUIPE : ";  std::cin >> choisirClub;

            std::string rupture =  "rupture";

            std::string contract = "contract";

            // Construction de la rupture
            Rupture newRuptureName(this,leContrat->getClubContractant(),raisonDuDepart,penalite);

            // Supprimer le contrat du joueur
            leContrat->getClubContractant->deleteContratsdEngagement(leContrat);

            // Le joueur n'est plus liée au Contract

            // Delete contract d'entende dans Club (recherche)
            int dureeDuContract, choisirClub;
            std::string datedEntree, dateDuContrat;
            float seuilTransfert;


            std::cout << "*******************LE NOUVEAU CONTRAT DU JOUEUR*******************" << std::endl;
            std::cout << std::endl <<  "//		DUREE DU CONTRACT : "; std::cin >> dureeDuContract;
            std::cout << std::endl <<  "//		DATE D\'ENTREE DU JOUEUR : "; std::cin >> datedEntree;
            std::cout << std::endl <<  "//		QUELLE DATE FINI LE CONTRACT : "; std::cin >> dateDuContrat;
            std::cout << std::endl <<  "//		PRIX DU TRANSFERT : "; std::cin >> seuilTransfert;
            std::cout << std::endl <<  "//		CHOISIR NOUVELLE EQUIPE : " <<std::endl;
            std::cout << std::endl << leContrat->getClubContractant()->getAllClub();  std::cin >> choisirClub;

            Club *club;

            *club = Club::getClub(choisirClub);

            std::string contractName = rupture + this->getFirstName() + this->getLastName(); // Obtenir un Constructeur Différent


            Contract newContractName(this,club,leContrat->getClubContractant,dureeDuContract,datedEntree,dateDuContrat,seuilTransfert);
        }
        else {
            std::cout << "Le contrat n\'existe pas pour le joueur !" << std::endl;
        }
    }

    std::string getEmplacementNaissance(){
        return _emplacementNaissance;
    }

    void setEmplacementNaissance(std::string birthDay){

        _emplacementNaissance = birthDay;
    }
    /*
=======
			Club *newClub;
			//newClub = Ligue->getClub(choisirClub(couleur));

            // Construction de la rupture
			Rupture newRupture = new Rupture(this,newClub,raisonDuDepart,penalite);
			leContrat->getClubContractant()->getRupturesDeContrats().push_back(newRupture);

			//Creation du nouveau contrat du joueur
			leContrat->getClubContractant()->TransfertJoueur(this, newClub);
		}
        else
		{
			std::cout << "Le joueur " << obtenirNP() << " n'a pas de contrat." << std::endl;
        }
    }
>>>>>>> b15bd5be0336fa826133cd589b4f448e35f93581
*/
};

class Joueur_NonAutonome : public Joueur{

private:
	int    _anneeCumulee;
	bool   _avisFavorable;

public:
    // Avec Avis Favorable
	Joueur_NonAutonome(std::string prenom,std::string nom, int age,float taille,float poids,std::string emplacementNaissance,int anneecumulee,bool avisFavorable):
        Joueur(prenom, nom, age, taille, poids, emplacementNaissance),_anneeCumulee(anneecumulee),_avisFavorable(avisFavorable) {}
    // Sans AvisFavorable
	Joueur_NonAutonome(std::string prenom,std::string nom, int age,float taille,float poids,std::string emplacementNaissance):
        Joueur(prenom, nom, age, taille, poids, emplacementNaissance), _anneeCumulee(0),_avisFavorable(false) {}

    virtual ~Joueur_NonAutonome();
    Joueur_NonAutonome(const Joueur_NonAutonome& other);
    Joueur_NonAutonome(Joueur_NonAutonome&& other);
    virtual Joueur_NonAutonome& operator=(const Joueur_NonAutonome& other);
    virtual Joueur_NonAutonome& operator=(Joueur_NonAutonome&& other);

//----------------------------------------------------------------- methods for AnneeCumulee
	int getAnneeCumulee() {
		return _anneeCumulee;
	}

	bool DemandeDeTransfert(){
        if (this->_avisFavorable == true){
            return true;
        }
        else return false;
    }
	void setAnneeCumulee(int annee) {
		_anneeCumulee = annee;
	}

//----------------------------------------------------------------- methods for avisFavorable
	bool getAvisFavorable(){
		return _avisFavorable;
    }

	void getAvisFavorable(bool avis) {
		_avisFavorable = avis;
	}

//----------------------------------------------------------------- methods of Joueur_NonAutonome

};


class Entraineur : protected Person{

protected:
    std::string _placeGrade;
    VectorPal   _TitreGagne;

public:

    Entraineur(std::string prenom,std::string nom, int age, std::string place) :
		Person(prenom, nom, age, ENTRAINEUR), _placeGrade(place) {}
    virtual ~Entraineur();
    Entraineur(const Entraineur& other);
    Entraineur(Entraineur&& other);
    virtual Entraineur& operator=(const Entraineur& other);
    virtual Entraineur& operator=(Entraineur&& other);


    std::string getFirstName(){

        return _prenom;
    }

    void setFirstName(std::string firstName){

       _prenom = firstName;

    }

    std::string getLastName(){
        return _nom;
    }

    void setLastName(std::string nom){
        _nom = nom;
    }

//----------------------------------------------------------------- methods of placeGrade
    std::string getPlaceGrade(){
        return _placeGrade;
    }

    void setPlaceGrade(std::string Grade){
		_placeGrade = Grade;
	}

//----------------------------------------------------------------- methods of TitresGagnes


    VectorPal getTitreGagne(){
        for (int i = 0; i < _TitreGagne.size();i++){
            std::cout << "Voici la Position du TitreGagne: " << i << " - "<< _TitreGagne[i]->getTitre() << std::endl;
        }
    }

    Titre selectTitreGagne(int j){
        for(int i = 0; i < _TitreGagne.size();i++){
            if (_TitreGagne[j]==_TitreGagne[i]){
                return _TitreGagne[i]->getTitre();
            }
            else {
                std::cout << "Le Titre selectionne n\'existe pas" << std::endl;
            }
        }
    }

    int getNumberOfTitre(){
        int nbTitre;

        for(int i = 0;i<_TitreGagne.size();i++){
            nbTitre++;
        }

        return nbTitre;
    }
};

#endif
