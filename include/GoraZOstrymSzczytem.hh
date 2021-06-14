#pragma once

#include "Bryla_Geometryczna.hh"

class GoraZOstrymSzczytem: public Bryla_Geometryczna {
  public:
    virtual ~GoraZOstrymSzczytem() {}
    virtual void wyswietlNazwe() const override;
    virtual void deformuj() override;
};