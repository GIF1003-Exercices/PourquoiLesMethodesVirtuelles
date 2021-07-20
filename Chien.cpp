//
// Created by etudiant on 21-04-30.
//

#include "Chien.h"

Chien::Chien(const std::string& nom) : Animal(nom) {}

std::string Chien::crier() const  {
return "Wouf! wouf!!!" ;
}