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
#include "CapteurTemp.hpp"
#include "Chaudiere.hpp"


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
    DummyCapteurTemp capteur;
    Chaudiere* pchaudiere;

    std::array<float,5>tabTemp={};

    unsigned int ptr;
    std::mutex arrayMutex;
    float Consigne=0;
    float Hysteresis=0;

    std::jthread mesureThread;
    std::jthread processingThread;

    void addTemp(float);
    float gettemp();

    void _measureThread();
    float _processingThread();



public:
    ThermostatApp() = delete;											/**< Deleted default Ctor		*/
    virtual ~ThermostatApp() = default;
    explicit ThermostatApp(Chaudiere* pchaudiere);


    /**
     * 	Init function
     * 		This function :
     * 			MUST be called once.
     * 			Checks the pChaudiere pointer
     * 			Creates and starts the threads
     * 	@throw	NoBoilerException if pChaudiere is a nullptr
     *
     */
    virtual void	Init();

    /**
     * 	Run function
     * 		main task
     * 		May be empty (multithreaded app)
     */
    virtual void	Run();




};

#endif	/* __APP_THERMOSTAT_H__ */
