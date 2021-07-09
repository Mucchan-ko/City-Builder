/**
 * \file Prune.h
 *
 * \author Nick Katarzynski
 *
 * class to prune gardens
 */

#pragma once
#include "TileVisitor.h"
#include "TileGarden.h"


/**
 * visitor to prune all CTileGarden tiles
 */
class CPrune : public CTileVisitor
{
public:
    void VisitGarden(CTileGarden* garden);
};