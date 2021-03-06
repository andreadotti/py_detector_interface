/*
 * This file provides the source code to export the c++ classes and function
 *
 * File:    pythonExtension.cc
 * Author:  jburchert
 * Date:    27 August 2017
 */


#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/python/register_ptr_to_python.hpp>
#include <boost/python/init.hpp>

// Interfaces
#include "PhotonEntry.hh"
#include "InteractionEntry.hh"
#include "ChargeEntry.hh"
#include "PhotonData.hh"
#include "InteractionData.hh"
#include "ChargeMatrix.hh"
#include "ParticleSim.hh"
#include "ChargeSim.hh"

using namespace boost::python;



BOOST_PYTHON_MODULE(libpy_detector_interface){
// PhotonEntry 
    class_<XCSIT::XPhotonEntry,boost::noncopyable>("XPhotonEntry", no_init);

    class_<DSIM::PhotonEntry,bases<XCSIT::XPhotonEntry> >("PhotonEntry")
		.def("getPositionX",&DSIM::PhotonEntry::getPositionX)
		.def("getPositionY",&DSIM::PhotonEntry::getPositionY)
		.def("getPositionZ",&DSIM::PhotonEntry::getPositionZ)
		.def("getDirectionX",&DSIM::PhotonEntry::getDirectionX)
		.def("getDirectionY",&DSIM::PhotonEntry::getDirectionY)
		.def("getDirectionZ",&DSIM::PhotonEntry::getDirectionZ)
		.def("getEnergy",&DSIM::PhotonEntry::getEnergy)
		.def("setPositionX",&DSIM::PhotonEntry::setPositionX)
		.def("setPositionY",&DSIM::PhotonEntry::setPositionY)
		.def("setPositionZ",&DSIM::PhotonEntry::setPositionZ)
		.def("setDirectionX",&DSIM::PhotonEntry::setDirectionX)
		.def("setDirectionY",&DSIM::PhotonEntry::setDirectionY)
		.def("setDirectionZ",&DSIM::PhotonEntry::setDirectionZ)
		.def("setEnergy",&DSIM::PhotonEntry::setEnergy)
		.def("set",&DSIM::PhotonEntry::set)
		.def("toString",&DSIM::PhotonEntry::toString)
    ;

// InteractionEntry
    class_<XCSIT::XInteractionEntry,boost::noncopyable>("XInteractionEntry", no_init);    

    class_<DSIM::InteractionEntry, bases<XCSIT::XInteractionEntry> >("InteractionEntry")
		.def("getPositionX",&DSIM::InteractionEntry::getPositionX)
		.def("getPositionY",&DSIM::InteractionEntry::getPositionY)
		.def("getPositionZ",&DSIM::InteractionEntry::getPositionZ)
		.def("getTime",&DSIM::InteractionEntry::getTime)
		.def("getEnergy",&DSIM::InteractionEntry::getEnergy)
		.def("setPositionX",&DSIM::InteractionEntry::setPositionX)
		.def("setPositionY",&DSIM::InteractionEntry::setPositionY)
		.def("setPositionZ",&DSIM::InteractionEntry::setPositionZ)
		.def("setTime",&DSIM::InteractionEntry::setTime)
		.def("setEnergy",&DSIM::InteractionEntry::setEnergy)
		.def("set",&DSIM::InteractionEntry::set)
		.def("toString",&DSIM::InteractionEntry::toString)
	;

// ChargeEntry
    class_<XCSIT::XChargeEntry, boost::noncopyable>("XChargeEntry",no_init);

    class_<DSIM::ChargeEntry, bases<XCSIT::XChargeEntry> >("ChargeEntry")
		.def("getCharge",&DSIM::ChargeEntry::getCharge)
		.def("setCharge",&DSIM::ChargeEntry::setCharge)
		.def("addCharge",&DSIM::ChargeEntry::addCharge)
		.def("toString",&DSIM::ChargeEntry::toString)
    ;

// PhotonData
	class_<XCSIT::XPhotonData, boost::shared_ptr<XCSIT::XPhotonData>, boost::noncopyable>("XPhotonData", no_init);

    class_<DSIM::PhotonData, boost::shared_ptr<DSIM::PhotonData>, bases<XCSIT::XPhotonData> >("PhotonData", init<>())
		.def("getEntry",&DSIM::PhotonData::getEntry)
		.def("addEntry",&DSIM::PhotonData::addEntry)
		.def("size",&DSIM::PhotonData::size)
		.def("clear",&DSIM::PhotonData::clear)
    ;
	
	register_ptr_to_python<boost::shared_ptr<XCSIT::XPhotonEntry> >();	

// InteractionData
	class_<XCSIT::XInteractionData, boost::shared_ptr<XCSIT::XInteractionData>, boost::noncopyable >("XInteractionData", no_init);

    class_<DSIM::InteractionData, boost::shared_ptr<DSIM::InteractionData>, bases<XCSIT::XInteractionData> >("InteractionData", init<>())
		.def("getEntry",&DSIM::InteractionData::getEntry)
		.def("addEntry",&DSIM::InteractionData::addEntry)
		.def("size",&DSIM::InteractionData::size)
		.def("clear",&DSIM::InteractionData::clear)
    ;

	register_ptr_to_python<boost::shared_ptr<XCSIT::XInteractionEntry> >();

// ChargeMatrix
	class_<XCSIT::XChargeData, boost::shared_ptr<XCSIT::XChargeData>, boost::noncopyable>("XChargeData", no_init);	

    class_<DSIM::ChargeMatrix, boost::shared_ptr<DSIM::ChargeMatrix>, bases<XCSIT::XChargeData> >("ChargeMatrix", init<>())
		.def("setSize",&DSIM::ChargeMatrix::setSize)
		.def("getEntry",&DSIM::ChargeMatrix::getEntry)
		.def("width",&DSIM::ChargeMatrix::width)
		.def("height",&DSIM::ChargeMatrix::height)
		.def("clear",&DSIM::ChargeMatrix::clear)
    ;
	
	register_ptr_to_python<boost::shared_ptr<XCSIT::XChargeEntry> >();	

// Constants
    class_<DSIM::Constants>("Constants")
        .def("size",&DSIM::Constants::size)
        .def("varValue",&DSIM::Constants::varValue)
    ;


// ParticleSim
    class_<DSIM::ParticleSim>("ParticleSim")
		.def("setInput",&DSIM::ParticleSim::setInput)
		.def("setOutput",&DSIM::ParticleSim::setOutput)
		.def("initialization",&DSIM::ParticleSim::initialization)
		.def("runSimulation",&DSIM::ParticleSim::runSimulation)
    ;


// ChargeSim
    class_<DSIM::ChargeSim>("ChargeSim")
		.def("setInput",&DSIM::ChargeSim::setInput)
		.def("setOutput",&DSIM::ChargeSim::setOutput)
		.def("setComponents",&DSIM::ChargeSim::setComponents)
		.def("runSimulation",&DSIM::ChargeSim::runSimulation)
    ;

	register_ptr_to_python<boost::shared_ptr<DSIM::ChargeMatrix> >();	

}

