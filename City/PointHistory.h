/**
* \file PointHistory.cpp
*
* \author Charles Owen
*
* Class that maintains a collection of Point objects in order.
*/

#pragma once
#include <memory>
#include <random>


/**
 * Class that maintains a collection of Point objects in order.
 */
class CPointHistory
{
public:
    /// The number of potato lists.
    const static int NumLists = 2;

    CPointHistory();
    virtual ~CPointHistory();

    void Add(Gdiplus::Point p);

    /** Iterator that iterates over the city tiles */
    class Iter
    {
    public:
        /** Constructor
         * \param history History to make into iterator
         * \param index Index to set for iterator
         * \param list List to put point into
         */
        Iter(CPointHistory* history, int index, int list) : 
            mHistory(history), mIndex(index), mList(list) {}

        /** Test for end of the iterator
         * \param other Other iterator to compare to
         * \returns True if this position equals not equal to the other position 
         */
        bool operator!=(const Iter& other) const
        {
            return (mIndex != other.mIndex || mList != other.mList);
        }

        /** Get value at current position
         * \returns Value at mIndex in the collection */
        Gdiplus::Point operator *() const
        { 
            return mHistory->mPotatoLists[mList][mIndex]; 
        }

        /** Increment the iterator
         * \returns Reference to this iterator */
        const Iter& operator++()
        {
            mList++;
            mList = mList % NumLists;

            if (mList == 0)
                mIndex++;

            return *this;
        }


    private:
        CPointHistory* mHistory;   ///< History we are iterating over
        int mIndex = 0;       ///< Position in the collection
        int mList = 0;       ///< Which list in collection
    };

    /** Get an iterator for the beginning of the collection
     * \returns Iter object at position 0 */
    Iter begin() { return Iter(this, 0, 0); }

    /** Get an iterator for the end of the collection
     * \returns Iter object at position past the end */
    Iter end() { return Iter(this, this->mPotatoLists[mCurrentList].size(), mCurrentList); }

protected:
    /// Data is stored in alternating locations in 
    /// the multiple hot potato lists.
    std::vector<Gdiplus::Point> mPotatoLists[NumLists];

    /// The current list we are adding points to. Each time
    /// we add a point, we will add it to this list, then 
    /// change mCurrentList to change to the next list.
    int mCurrentList = 0;
};

