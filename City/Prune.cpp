#include "pch.h"
#include "Prune.h"

/** Visit a CTileGarden object
* \param garden Garden we are visiting */
void CPrune::VisitGarden(CTileGarden* garden)
{
	garden->SetTime(0);
}
