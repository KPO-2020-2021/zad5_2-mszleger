#pragma once

#include "Bryla_Geometryczna.hh"

class Plaskowyz: public Bryla_Geometryczna {
  public:
    virtual ~Plaskowyz() {}
    virtual void wyswietlNazwe() const override;
    virtual void deformuj() override;
};