/******************************************************************************
Title           : GeniusBar.cpp
Author          : Starasia Wright
Created on      : 2018-08-30
Description     : Provides interface to manage GeniusBar
******************************************************************************/
#include "GeniusBar.hpp"
#include <iostream>
using namespace std;


//Default contructor for GeniusBar which initializes values

GeniusBar::GeniusBar() {
    current_wait_time_ = 0;
    number_of_customers_ = 0;
    number_of_available_geniuses_ = 3;
}

//Adds customer to Genius Bar if there's space and updates the waiting time

bool GeniusBar::addWaitingCustomer(Customer &new_customer){ 
    
    //Checks that the Genius Bar is not full
    
    if (number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS) {
        
        //fills the next available spot in Genius Bar with new customer
        
        genius_bar_[number_of_customers_] = new_customer;
    
        //increases wait time by WAIT_TIME_INCREMENT, which is 5 minutes
        
        current_wait_time_ += WAIT_TIME_INCREMENT;
        
         //assigns current wait time to newly added customer
       
       new_customer.updateWaitTime(current_wait_time_);
        
        //increments the number of customers to keep track of filled spots
        
        number_of_customers_ += 1;
        
        return true;
    
    } else {
        
        return false;
    }
}

//Assigns an available Genius to waiting customer

bool GeniusBar::assignGeniusToCustomer() {
    
    //Checks if Genius is available for waiting customer
    
    if ((number_of_customers_ > 0) && (number_of_available_geniuses_ > 0)) {
        
        //removes a customer from number of waiting customers
        number_of_customers_ -= 1;
        
        //removes a Genius from the bumber of available Geniuses
        number_of_available_geniuses_ -= 1;
      
        return true;
    } else {
        
        return false;
    }
}

//If Geniuses are currently unavilable, geniuses are made avialable, again

bool GeniusBar::releaseGenius() {
    
    //Checks if all Geniuses are already available
    
    if (number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES) {
    
        //increments the enumber of available Geniuses by 1
        number_of_available_geniuses_ += 1;
        
    return true;
        
   } else {
    
        return false;
   }
}

//If there are customers, wait time is updated

bool GeniusBar::updateCustomersWaitTime(){
    
    //checks if there are customers
    
    if (number_of_customers_ > 0) {
        for (int i = 0; i < number_of_customers_; i++) {
            //reduces wait time, for each customer in genius_bar_, by WAIT_TIME_INCREMENT
            genius_bar_[i].updateWaitTime(current_wait_time_-WAIT_TIME_INCREMENT);
            
        }
        
        return true;
        
    } else {
        
        return false;
    }
}