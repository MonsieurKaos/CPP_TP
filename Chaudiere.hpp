/**
 *	@file	Chaudiere.hpp
 * 	@brief 	Header file for the Chaudiere interface and the 
 * 			DummyChaudiere concrete class
 * 	@author	
 * 	@date	
 * 
 */

#ifndef CHAUDIERE_H_
#define    CHAUDIERE_H_

#include <iostream>

//----------------------------------------------------------------------
class BoilerAlreadyONexception : public std::exception {
};            /**< Exception thrown if trying to set ON an already on boiler	*/
class BoilerAlreadyOFFexception : public std::exception {
};            /**< Exception thrown if trying to set OFF an already off boiler	*/
//----------------------------------------------------------------------
/**
 * 	Class Chaudiere
 * 
 * 	Interface to a "boiler" 
 */
class Chaudiere {
public:
    enum class Status {
        ON,            /**<	Boiler ON status value	*/
        OFF            /**<	Boiler OFF status value	*/
    };
private:
    Status status{Status::OFF};    /**<	Boiler status	*/
protected:
    /**
    *	Setter for the status field
    * 	@param[in] : new status
    *
    * 	noexcept : this function throws no exception
    *
    */
    void setStatus(Status status) noexcept { this->status = status; };
public:
    Chaudiere() = default;                    /**<	Defaulted default Ctor	*/
    virtual ~Chaudiere() = default;            /**<	Defaulted Dtor			*/

    /**
    *	getter for the status field
    *
    * 	noexcept : this function throws no exception
    *
    * 	@return : heater status
    */
    Status getStatus() { return this->status; };

    /**
    *	setON() function - pure virtual function
    * 		Sets the boiler on (if not)
    *
    * 	@throw	HeaterAlreadyONexception	if the boiler is already on
    *
    */
    virtual void setON() = 0;

    /**
    *	setOFF() function - pure virtual function
    * 		Sets the boiler off (if not)
    *
    * 	@throw	HeaterAlreadyOFFexception	if the boiler is already off
    *
    */
    virtual void setOFF() = 0;

};

//----------------------------------------------------------------------
class DummyChaudiere : public Chaudiere {
private:

public:
    DummyChaudiere() = default;                /**<	Defaulted default Ctor	*/
    ~DummyChaudiere() override = default;    /**<	Defaulted Dtor			*/

    /**
    *	setON() function
    * 		Sets the boiler on (if not)
    *
    * 	@throw	HeaterAlreadyONexception	if the boiler is already on
    *
    */
    void setON() override;

    /**
    *	setOFF() function
    * 		Sets the boiler off (if not)
    *
    * 	@throw	HeaterAlreadyOFFexception	if the boiler is already off
    *
    */
    void setOFF() override;

};
//----------------------------------------------------------------------

#endif    /* CHAUDIERE_H_ */

