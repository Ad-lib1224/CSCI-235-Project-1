/******************************************************************************
Title           : Customer.cpp
Author          : Starasia Wright
Created on      : 2018-08-30
Description     : Provides the interface to access customer information
******************************************************************************/

#include "Customer.hpp"
#include <iostream>
using namespace std;

//Default contructor for Customer which initializes values

Customer::Customer() {
    
    string name;
    
    string device = "unknown";
    
    int wait_time = 0;
}

//Assigns private values to default values

Customer::Customer(string name, string device, int wait_time) {
    
    name_ = name;
    
    defective_device_ = device;
    
    wait_time_ = wait_time;

}

//Accessor for name_

string Customer::getName() {
    
    return name_;
 
}

//Accessor for defective_device_

string Customer::getDevice() {
    
    return defective_device_;
}

//Accessor for wait_time_

int Customer::getWaitTime() {
    
    return wait_time_;
 
}

void Customer::updateWaitTime(int new_wait_time) {
    
    wait_time_ = new_wait_time;

}