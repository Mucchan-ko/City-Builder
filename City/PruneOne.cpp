#include "pch.h"
#include "PruneOne.h"

/** Visit a CTileGarden object
* \param garden Garden we are visiting */
void CPruneOne::VisitGarden(CTileGarden* garden)
{
	garden->SetTime(0);
}
