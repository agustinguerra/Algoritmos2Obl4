#pragma once

#include "Costos.h"
#include "Comparacion.h"

class ComparacionCMB : public Comparacion<Costos>
{
public:
	ComparacionCMB();
	~ComparacionCMB(){}

	CompRetorno Comparar(const Costos& t1, const Costos& t2) const override;
};