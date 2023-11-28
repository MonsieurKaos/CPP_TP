/**
 *	@file		appThermostat.cpp
 * 	@brief 		appThermostat definition file
 * 	@author		
 * 	@date		
 * 
 */

#include "appThermostat.hpp"



//----------------------------------------------------------------------
void	ThermostatApp::Init(){
    DummyChaudiere Chaudiere{};
    DummyCapteurTemp capteurTemp {};
}
//----------------------------------------------------------------------
void	ThermostatApp::Run(){

    float temp = float getTemp{};
	/**<	 Nothing to do in the main task	*/
}
//----------------------------------------------------------------------
//----------------------------------------------------------------------

