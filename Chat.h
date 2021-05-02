//
// Created by etudiant on 21-04-30.
//

#ifndef METHODESVIRTUELLES_CHAT_H
#define METHODESVIRTUELLES_CHAT_H


#include "Animal.h"

class Chat : public Animal {

public:
    explicit Chat(std::string) ;

    std::string crier()    const ;
};


#endif //METHODESVIRTUELLES_CHAT_H
