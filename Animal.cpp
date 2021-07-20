/**
 * @file Animal.cpp
 * @author Pascal Charpentier
 * @version 0.1
 */

/**
 * @class Animal
 * @brief Classe de base représentant un animal générique
 */
#include "Animal.h"

Animal::Animal(const std::string& nom) : nom(nom) {}

const std::string& Animal::getNom() const {
    return nom ;
}

std::string Animal::crier() const {
    return "!!!" ;
}
