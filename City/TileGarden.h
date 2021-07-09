/**
 * \file TileGarden.h
 *
 * \author Nick Katarzynski
 *
 * Class that implements a Garden tile
 */

#pragma once
#include "Tile.h"


/**
 * Garden tile to go in CCity
 */
class CTileGarden : public CTile
{
public:
    CTileGarden(CCity* city);

    ///  Default constructor (disabled)
    CTileGarden() = delete;

    ///  Copy constructor (disabled)
    CTileGarden(const CTileGarden&) = delete;

    ~CTileGarden();

    virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    /** Accept a visitor
    * \param visitor The visitor we accept */
    virtual void Accept(CTileVisitor* visitor) override { visitor->VisitGarden(this); }

    void Update(double elapsed);

    /// The supported pruning states
    enum class PruningStates { Pruned, Overgrown1, Overgrown2, Overgrown3, Overgrown4 };

    /** Set Pruning time
     * \param time Time to set pruning time to
     */
    void SetTime(double time) { mSincePruning = time; }


private:
    /// Time it has been since garden was last pruned
    double mSincePruning = 0;

    /// The current garden pruning state
    PruningStates mPruningState = PruningStates::Pruned;
};

