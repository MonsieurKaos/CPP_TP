/**
 *	@file		appThermostat.hpp
 * 	@brief 		header file for the Application Interface and ThermostatApp class
 * 	@author		
 * 	@date		
 * 
 */
#ifndef APP_THERMOSTAT_H_
#define	APP_THERMOSTAT_H_

#include <iostream>
#include <thread>
#include <array>
#include <mutex>


//----------------------------------------------------------------------
/**
 * 	Class Application
 * 
 * 	Interface to a "classic" embedded (or not) app 
 */
class Application{
	public:
		Application() = default;			/**<	Defaulted default Ctor	*/
		virtual ~Application() = default;	/**<	Defaulted Dtor	*/
		
		virtual void	Init() = 0;			/**<	Pure virtual function - Must include all init stuff	*/
		virtual void	Run() = 0;			/**<	Pure virtual function - Could include some code (or not...)	*/
};
//----------------------------------------------------------------------
/**
 * 	Class ThermostatApp
 * 
 * 	Concrete Thermostat app 
 */



class	ThermostatApp:public Application{

	private:
	
	public:
		ThermostatApp() = delete;											/**< Deleted default Ctor		*/
		~ThermostatApp() override = default;
		
		/**
		 * 	Init function
		 * 		This function : 
		 * 			MUST be called once.
		 * 			Checks the pChaudiere pointer
		 * 			Creates and starts the threads 
		 * 	@throw	NoBoilerException if pChaudiere is a nullptr
		 * 
		 */
		void	Init() override;
		
		/**
		 * 	Run function
		 * 		main task
		 * 		May be empty (multithreaded app)
		 */
		void	Run() override;
	
	
};

#endif	/* __APP_THERMOSTAT_H__ */

