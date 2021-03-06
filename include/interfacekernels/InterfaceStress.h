//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef INTERFACESTRESS_H
#define INTERFACESTRESS_H

#include "InterfaceKernel.h"
#include "RankTwoTensor.h"

// Forward Declarations
class InterfaceStress;

template <>
InputParameters validParams<InterfaceStress>();

/**
 * DG kernel for interfacing diffusion between two variables on adjacent blocks
 */
class InterfaceStress : public InterfaceKernel
{
public:
  InterfaceStress(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual(Moose::DGResidualType type);
  virtual Real computeQpJacobian(Moose::DGJacobianType type);

  const MaterialProperty<RankTwoTensor> & _stress0;
  const MaterialProperty<RankTwoTensor> & _stress1;
  const unsigned int _component;
};

#endif
