#include "pch.h"
#include "TileGarden.h"

using namespace std;
using namespace Gdiplus;


/// Image when the garden is pruned
const wstring PrunedImage = L"garden.png";

/// Image when the garden is at stage 1
const wstring OvergrownImage1 = L"garden1.png";

/// Image when the garden is at stage 2
const wstring OvergrownImage2 = L"garden2.png";

/// Image when the garden is at stage 3
const wstring OvergrownImage3 = L"garden3.png";

/// Image when the garden is at stage 4
const wstring OvergrownImage4 = L"garden4.png";

/** Constructor
* \param city The city this is a member of
*/
CTileGarden::CTileGarden(CCity* city) : CTile(city)
{
    SetImage(L"garden.png");
}

/**
*  Destructor
*/
CTileGarden::~CTileGarden()
{
}

/**  Save this item to an XML node
* \param node The node we are going to be a child of
* \returns Allocated node
*/
std::shared_ptr<xmlnode::CXmlNode> CTileGarden::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CTile::XmlSave(node);

    itemNode->SetAttribute(L"type", L"garden");

    return itemNode;
}

/**
 * Called before the image is drawn
 * \param elapsed Time since last draw
 */
void CTileGarden::Update(double elapsed)
{
    CTile::Update(elapsed);

    mSincePruning += elapsed;

    if (mSincePruning < 2)
    {
        mPruningState = PruningStates::Pruned;
        SetImage(L"garden.png");
    }

    else if (mSincePruning >= 2 && mSincePruning < 4)
    {
        mPruningState = PruningStates::Overgrown1;
        SetImage(L"garden1.png");
    }

    else if (mSincePruning >= 4 && mSincePruning < 7)
    {
        mPruningState = PruningStates::Overgrown2;
        SetImage(L"garden2.png");
    }

    else if (mSincePruning >= 7 && mSincePruning < 10)
    {
        mPruningState = PruningStates::Overgrown3;
        SetImage(L"garden3.png");
    }

    else
    {
        mPruningState = PruningStates::Overgrown4;
        SetImage(L"garden4.png");
    }
}