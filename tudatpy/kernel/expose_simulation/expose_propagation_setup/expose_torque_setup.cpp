/*    Copyright (c) 2010-2019, Delft University of Technology
 *    All rights reserved
 *
 *    This file is part of the Tudat. Redistribution and use in source and
 *    binary forms, with or without modification, are permitted exclusively
 *    under the terms of the Modified BSD license. You should have received
 *    a copy of the license with this file. If not, please or visit:
 *    http://tudat.tudelft.nl/LICENSE.
 */

#include "expose_propagation_setup/expose_dependent_variable_setup.h"

#include <pybind11/chrono.h>
#include <pybind11/eigen.h>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

namespace py = pybind11;
namespace tba = tudat::basic_astrodynamics;
namespace tss = tudat::simulation_setup;
namespace tp = tudat::propagators;
namespace tinterp = tudat::interpolators;
namespace te = tudat::ephemerides;
namespace tni = tudat::numerical_integrators;
namespace trf = tudat::reference_frames;
namespace tmrf = tudat::root_finders;

namespace tudatpy {

    void expose_torque_setup(py::module &m) {

        py::enum_<tba::AvailableTorque>(m, "AvailableTorque")
                .value("torque_free_type", tba::AvailableTorque::torque_free)
                .value("underfined_type", tba::AvailableTorque::underfined_torque)
                .value("second_order_gravitational_type", tba::AvailableTorque::second_order_gravitational_torque)
                .value("aerodynamic_type", tba::AvailableTorque::aerodynamic_torque)
                .value("spherical_harmonic_gravitational_type",
                       tba::AvailableTorque::spherical_harmonic_gravitational_torque)
                .value("inertial_type", tba::AvailableTorque::inertial_torque)
                .value("dissipative_type", tba::AvailableTorque::dissipative_torque)
                .export_values();

        py::class_<tss::TorqueSettings,
                std::shared_ptr<tss::TorqueSettings>>(m, "AccelerationSettings");

        py::class_<tss::SphericalHarmonicTorqueSettings,
                std::shared_ptr<tss::SphericalHarmonicTorqueSettings>,
                tss::TorqueSettings>(m, "SphericalHarmonicTorqueSettings");

        m.def("aerodynamic", &tss::aerodynamicTorque);

        m.def("second_degree_gravitational", &tss::secondDegreeGravitationalTorque);

        m.def("spherical_harmonic_gravitational", &tss::sphericalHarmonicGravitationalTorque,
              py::arg("maximum_degree"),
              py::arg("maximum_order"));

        m.def("custom", &tss::customTorqueSettings,
              py::arg("torque_function"),
              py::arg("scaling_function") = nullptr);

    }

} // namespace tudatpy