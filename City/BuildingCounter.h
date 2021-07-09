/**
 * \file BuildingCounter.h
 *
 * \author Nick Katarzynski
 *
 * class to count buldings in city
 */

#pragma once
#include "TileVisitor.h"


/**
 * Class to count CTiles that are buildings
 */
class CBuildingCounter : public CTileVisitor
{
public:
    /** Get the number of buildings
    * \returns Number of buildings */
    int GetNumBuildings() const { return mNumBuildings; }

    void VisitBuilding(CTileBuilding* building);

private:
    /// Buildings counter
    int mNumBuildings = 0;
};

