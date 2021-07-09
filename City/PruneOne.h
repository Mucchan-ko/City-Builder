/**
 * \file Prune.h
 *
 * \author Nick Katarzynski
 *
 * class to prune a selected garden
 */

#pragma once
#include "TileVisitor.h"
#include "TileGarden.h"


/**
 * Prune one tile visitor to CTileGarden
 */
class CPruneOne : public CTileVisitor
{
public:
    void VisitGarden(CTileGarden* garden);
};