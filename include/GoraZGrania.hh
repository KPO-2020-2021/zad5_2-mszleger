#pragma once

#include "Bryla_Geometryczna.hh"

class GoraZGrania: public Bryla_Geometryczna {
  public:
    virtual ~GoraZGrania() {}
    virtual void wyswietlNazwe() const override;
    virtual void deformuj() override;
};