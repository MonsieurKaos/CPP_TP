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
    int16_t Tmin {DefaultTmin};
    int16_t Tmax {DefaultTmax};
    int16_t DeltaMax{DefaultDeltaMax};
    int16_t PrevTemp{DefaultPrevTemp};
    int16_t getTmin();
    int16_t getTmax();
    int16_t getDeltaMax();
    int16_t getPrevTemp();

    mutable std::default_random_engine generator{};

public:

    float getTemp(){
        float randomFloat = 0;
        uint16_t ecart;
        uint16_t randomNumber;

        do {
            std::random_device rd;
            int seed = rd();

            srand(seed);

            randomNumber = rand() % ((Tmax * 100) - (Tmin * 100) + 1) + (Tmin * 100);
            randomFloat = (float) randomNumber / 100;

            ecart = std::abs(randomFloat - this->PrevTemp);

        } while (ecart>this->DeltaMax);
        this->PrevTemp = randomNumber;

        return randomFloat;
    }
    

public:

    DummyCapteurTemp()=default;
    ~DummyCapteurTemp() override =default;

    //DummyCapteurTemp():DummyCapteurTemp(DefaultTmin, DefaultTmax, DefaultDeltaMax, DefaultPrevTemp){};
    DummyCapteurTemp(int16_t defaultTmin,int16_t defaulTmax,uint16_t defaultDeltaMax,uint16_t defaultPrevTemp);
    virtual float getTemp() const noexcept ;
};

#endif	/* __CAPTEUR_TEMP_H__ */
