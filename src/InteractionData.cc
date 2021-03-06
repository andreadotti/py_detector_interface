/*
 * File:   	InteractionData.cc
 * Author: 	jburchert
 * Date:	10 August 2017
 */

#include <boost/make_shared.hpp>
#include "InteractionData.hh"
#include <stdexcept>

namespace DSIM {

    InteractionData::InteractionData(){
        if(DEBUG){
            std::cout << "InteractionData::InteractionData" << std::endl;
		}
        // clear init
		clear();
    }

    InteractionData::~InteractionData(){
        if(DEBUG){
            std::cout << "InteractionData::~InteractionData" << std::endl;
        }
    }


	boost::shared_ptr<XCSIT::XInteractionEntry> InteractionData::getEntry(size_t entry){
        if(DEBUG){
            std::cout << "InteractionData::getEntry" << std::endl;
        }
		if(entry < 0 || entry >= iaNum){
			throw std::invalid_argument("value does not fit to number of elements in this instance");
		}

		return iaVec[entry];
	}


    boost::shared_ptr<XCSIT::XInteractionEntry> InteractionData::addEntry(){
        if(DEBUG){
            std::cout << "InteractionData::addEntry" << std::endl;
		}
        // Create the new instance
		// smart pointer will deal with the Destructor call if necessary
		boost::shared_ptr<XCSIT::XInteractionEntry> ne(new InteractionEntry());

		// Add it to the vector at the end of the of the ArrayList
		iaVec.push_back(ne);

		iaNum++;
		
		// Return the created instance
		return ne;
	}

    size_t InteractionData::size() const {
        if(DEBUG){
            std::cout << "InteractionData::size >> " << iaNum << std::endl;
		}
        return iaNum;
	}

	// Clears the structure and sets its size to 0, the shared_ptr will deal
	// with calling the Destructor of the contained instances
    void InteractionData::clear(){
        if(DEBUG){
            std::cout << "InteractionData::clear" << std::endl;
		}
        iaVec.clear();
		iaVec.resize(0);
		iaNum = 0;
	}

}
