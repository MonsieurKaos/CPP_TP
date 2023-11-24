/**
 *	@file	CapteurTemp.hpp
 * 	@brief 	Header file for temperature sensor interface
 * 	@author		
 * 	@date	
 * 
 */

#ifndef __CAPTEUR_TEMP_H__
#define	__CAPTEUR_TEMP_H__

#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <random>
#include <chrono>

#include <cstdint>
/**
 * 	CapteurTemp Class (Interface)
 * 
 * 
 */
class CapteurTemp{
public:
    CapteurTemp() = default;
    virtual ~CapteurTemp() = default;


    virtual float 	getTemp() = 0;
    // virtual cette methode late binding
    // = 0 cette methode doit etre obligatoirement définie


};

class   DummyCapteurTemp:public CapteurTemp{

private:

    int16_t DefaultTmin=0;
    int16_t DefaultTmax=70;
    int16_t DefaultDeltaMax=5;
    int16_t DefaultPrevTemp=20;
    int16_t Tmin;
    int16_t Tmax;
    int16_t DeltaMax;
    int16_t PrevTemp;
    int16_t getTmin();
    int16_t getTmax();
    int16_t getDeltaMax();
    int16_t getPrevTemp();


    mutable std::default_random_engine generator{};

public:
    float getTemp(){
        return (Tmin*100 + (rand() % (Tmax*100 - Tmin*100 + 1)))/100;
    }

public:

    DummyCapteurTemp()=default;

    virtual ~DummyCapteurTemp()=default;

    //DummyCapteurTemp():DummyCapteurTemp(DefaultTmin, DefaultTmax, DefaultDeltaMax, DefaultPrevTemp){};
    DummyCapteurTemp(int16_t defaultTmin,int16_t defaulTmax,uint16_t defaultDeltaMax,uint16_t defaultPrevTemp);
    virtual float getTemp() const noexcept ;



};

#endif	/* __CAPTEUR_TEMP_H__ */
