/**
 *	@file		Chaudiere.cpp
 * 	@brief 		Definition file for (concrete) Boiler
 * 	@author		
 * 	@date		
 * 
 */
#include "Chaudiere.hpp"

//----------------------------------------------------------------------
void DummyChaudiere::setON() {

    if (this->getStatus() == Status::ON) {

        throw BoilerAlreadyONexception();

    } else {
        this->setStatus(Status::ON);
        std::cout << "Chaudiere ON\n";
    }
}

//----------------------------------------------------------------------
void DummyChaudiere::setOFF() {
    if (this->getStatus() == Status::OFF) {

        throw BoilerAlreadyOFFexception();
    } else {
        this->setStatus(Status::OFF);
        std::cout << "Chaudiere OFF\n";
    }
}
//----------------------------------------------------------------------
