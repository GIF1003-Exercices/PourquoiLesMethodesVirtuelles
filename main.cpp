#include <iostream>
#include <vector>


#include "Chien.h"
#include "Chat.h"

int MAX_CARACTERES = 256 ;
int saisirUnEntierPositifAvecLimite(int limite) ;

int main() {
    Chien monChien("Fido") ;
    Chat  monChat("Noiraud") ;
    Animal monAnimal("Zorgplouk") ;

    std::cout << "*** Appel de la méthode crier() sur des objets déclarés dans main()***" << std::endl ;
    std::cout << "Mon nom est: " << monAnimal.getNom() << ". Voici mon cri: " << monAnimal.crier() << std::endl ;
    std::cout << "Mon nom est: " << monChien.getNom() << ". Voici mon cri: " << monChien.crier() << std::endl ;
    std::cout << "Mon nom est: " << monChat.getNom() << ". Voici mon cri: " << monChat.crier() << std::endl  ;

    std::cout << "*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***" << std::endl ;
    // ATTENTION: Analysez attentivement ces trois initialisations
    Animal& fido = monChien ;
    Animal& noiraud = monChat ;
    Animal& zorgplouk = monAnimal ;

    std::cout << "*** Appel de la méthode crier() sur des références à Animal ***" << std::endl ;
    std::cout << "Mon nom est: " << fido.getNom() << ". Voici mon cri: " << fido.crier() << std::endl ;
    std::cout << "Mon nom est: " << noiraud.getNom() << ". Voici mon cri: " << noiraud.crier() << std::endl ;
    std::cout << "Mon nom est: " << zorgplouk.getNom() << ". Voici mon cri: " << zorgplouk.crier() << std::endl ;
    std::cout << "*** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***" << std::endl ;

    // ATTENTION: Analysez attentivement cette déclaration
    std::vector<Animal*> animaux {&monAnimal, &monChien, &monChat};

    std::cout << "*** Nous allons maintenant appeler la méthode crier() sur un pointeur à Animal qui n'est pas connu d'avance ***" << std::endl ;
    std::cout << "Voici la liste des animaux disponibles.  Choisissez celui que vous voulez entendre" << std::endl ;
    for (size_t i = 0 ; i < animaux.size(); ++i) std::cout << i << ": " << animaux.at(i)->getNom() << std::endl ;
    std::cout << "Veuillez saisir un numéro: " ;
    int choix = saisirUnEntierPositifAvecLimite(animaux.size()) ;
    Animal* animalChoisi = animaux.at(choix) ;

    std::cout << "Allo,mon nom est: " << animalChoisi->getNom() << ". Voici mon cri: " << animalChoisi->crier() << std::endl ;


    return 0;
}

/**
 * Valide la saisie d'un nombre entier positif inférieur à une limite
 * Donc on aura: 0 <= saisie < limite
 * Une saisie comme "abcd" ou "2.345" est ignorée et l'utilisateur est invité
 * à recommencer.
 * @param limite borne supérieure des saisies acceptées
 * @return l'entier saisi
 * @pre limite est un nombre strictement positif
 * @except logic_error si limite est un nombre nul ou négatif
 */
int saisirUnEntierPositifAvecLimite(int limite) {
    if (limite <= 0) throw std::invalid_argument("Limite négative dans saisirUnEntierPositifAvecLimite") ;

    char saisie[MAX_CARACTERES] ;

    int valeurRetournee = 0 ;
    bool saisieValide = false ;
    while (!saisieValide) {
        std::cin.getline(saisie, MAX_CARACTERES) ;
        try {
            valeurRetournee = std::stoi(saisie) ;
            if ( (valeurRetournee < 0) or (valeurRetournee >= limite) ) {
                std::cout << "Veuillez saisir un nombre positif inférieur à " << limite << std::endl ;
            } else {
                saisieValide = true ;
            }
        }
        catch (std::invalid_argument &e) {
            std::cout << "Veuillez saisir un nombre entier valide svp!" << std::endl;
        }
    }
    return valeurRetournee;
}
