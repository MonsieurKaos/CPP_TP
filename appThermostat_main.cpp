/**
 *	@file		appThermostat_main.cpp
 * 	@brief 		main for the Thermostat App 
 * 	@author		
 * 	@date		
 * 
 */

#include <iostream>
#include <memory>

#include "appThermostat.hpp"
#include "Chaudiere.hpp"
#include "CapteurTemp.hpp"

int main() {

    // start tests

    try {
        DummyChaudiere mehdiChaudasse{};
        std::cout << "Default status: " << static_cast<int>(mehdiChaudasse.getStatus()) << std::endl;

        mehdiChaudasse.setON();
        mehdiChaudasse.setOFF();

    } catch (std::exception const& e){
        std::cout << "Exception\n";
    }


    try {
        DummyCapteurTemp capteurTest {};

        // std::cout << "Default capteur value " << (capteurTest.getTemp())<< std::endl;
        float temp  = capteurTest.getTemp();
        std::cout << "Temperature capteur: "<< temp << std::endl;

    } catch (std::exception const& e) {
        std::cout << "Exception\n";
    }

    // end tests

    return 0;
}


