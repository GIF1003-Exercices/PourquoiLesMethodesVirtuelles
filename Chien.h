//
// Created by etudiant on 21-04-30.
//

#ifndef METHODESVIRTUELLES_CHIEN_H
#define METHODESVIRTUELLES_CHIEN_H


#include "Animal.h"

class Chien : public Animal {
public:
    explicit Chien(const std::string&) ;

   std::string crier() const ;
};


#endif //METHODESVIRTUELLES_CHIEN_H
