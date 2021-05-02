//
// Created by etudiant on 21-04-30.
//

#include "Chat.h"

Chat::Chat(std::string nom) : Animal(nom) {

}

std::string Chat::crier() const {
    return "Miaou!!! Miaou!!!";
}
