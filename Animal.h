//
// Created by etudiant on 21-04-30.
//

#ifndef METHODESVIRTUELLES_ANIMAL_H
#define METHODESVIRTUELLES_ANIMAL_H

#include <string>


class Animal {
public:

    explicit Animal(std::string) ;
    std::string getNom() const ;
    virtual std::string crier() const ;

private:
    std::string nom ;

};


#endif //METHODESVIRTUELLES_ANIMAL_H
