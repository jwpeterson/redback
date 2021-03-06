/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef REDBACKMECHMATERIALJ2_H
#define REDBACKMECHMATERIALJ2_H

#include "RedbackMechMaterial.h"

// Forward Declarations
class RedbackMechMaterialJ2;

template <>
InputParameters validParams<RedbackMechMaterialJ2>();

class RedbackMechMaterialJ2 : public RedbackMechMaterial
{
public:
  RedbackMechMaterialJ2(const InputParameters & parameters);

protected:
  virtual void
  getJac(const RankTwoTensor &, const RankFourTensor &, Real, Real, Real, Real, Real, Real, RankFourTensor &) override;
  virtual void getFlowTensor(const RankTwoTensor &, Real, Real, Real, Real, Real, RankTwoTensor &) override;
  virtual Real getFlowIncrement(Real, Real, Real, Real, Real) override;
  virtual void get_py_qy(Real, Real, Real &, Real &, Real, bool &) override;
  Real getDerivativeFlowIncrement(const RankTwoTensor &, Real);
};

#endif // REDBACKMECHMATERIAL_H
