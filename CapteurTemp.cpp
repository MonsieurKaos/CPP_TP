//
// Created by mael on 24/11/23.
//

#include "CapteurTemp.hpp"

DummyCapteurTemp::DummyCapteurTemp(int16_t defaultTmin,int16_t defaulTmax,uint16_t defaultDeltaMax,uint16_t defaultPrevTemp){
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();	/**<  obtain a seed from the system clock */
    this->generator.seed(seed);
}

int16_t DummyCapteurTemp::getTmin(){
    return this->Tmin;

};
int16_t DummyCapteurTemp::getTmax(){
    return this->Tmax;

};
int16_t DummyCapteurTemp::getDeltaMax(){
    return this ->DeltaMax;
};
int16_t DummyCapteurTemp::getPrevTemp(){
    return this->PrevTemp;

};

float DummyCapteurTemp::getTemp() const noexcept{

    std::uniform_int_distribution<uint16_t> distribution(this->DefaultTmin, this->DefaultTmax);


    return distribution(this->generator);
};