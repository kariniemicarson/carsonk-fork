/**
 * @file PostalList.cpp
 * @ brief Implementation of the PostalList class for managing a collection of PostalCodeItem objects.
 * @ author
 *   Asfaw, Abel,
 *   Farah, Mahad,
 * 	Kariniemi, Carson,
 * 	Rogers, Mitchell
 *   Tran, Minh Quan
 * @ version 1.0
 * @ date 2025-9-23
 */

#include "PostalList.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * @brief Add a PostalCodeItem to the list.
 * @param item The PostalCodeItem to be added.
 */
void PostalList::addItem(const PostalCodeItem &item)
{
    items.push_back(item);
}

/**
 * @brief Get a PostalCodeItem by index.
 * @param index The index of the item to retrieve.
 * @return The PostalCodeItem at the specified index.
 * @throws out_of_range if the index is invalid.
 */
PostalCodeItem PostalList::getItem(int index) const
{
    if (index < items.size())
    {
        return items[index];
    }
    throw out_of_range("Index out of range in PostalList::getItem");
}

/**
 * @brief Find a PostalCodeItem by its ZIP code.
 * @param zip The ZIP code to search for.
 * @return A pointer to the PostalCodeItem if found, nullptr otherwise.
 * @note The returned pointer is valid as long as the PostalList object exists and is not modified.
 */
const PostalCodeItem *PostalList::findByZip(int zip) const
{
    for (const auto &item : items)
    {
        if (item.getZip() == zip)
        {
            return &item;
        }
    }
    return nullptr;
}

/**
 * @brief Get the number of items in the list.
 * @return The number of PostalCodeItem objects in the list.
 */
int PostalList::size() const
{
    return items.size();
}

/**
 * @brief Print all PostalCodeItems in the list.
 * Each item's information is printed followed by a separator line.
 * @note The order of items is the same as the order they were added.
 */
void PostalList::printAll() const
{
    for (int i = 0; i < items.size(); i++)
    {
        items[i].printInfo();
        cout << "-----------------------------------------------------------------------------------------------" << endl;
    }
}

/**
 * @brief Print PostalCodeItems sorted by ZIP code.
 * Each item's information is printed followed by a separator line.
 * @note Items are sorted in ascending order by ZIP code.
 */
void PostalList::printSortedByZip() const
{
    // Make a copy so original order is preserved
    vector<PostalCodeItem> sortedItems = items;

    sort(sortedItems.begin(), sortedItems.end(),
         [](const PostalCodeItem &a, const PostalCodeItem &b)
         {
             return a.getZip() < b.getZip();
         });

    for (const auto &item : sortedItems)
    {
        item.printInfo();
        cout << "-----------------------------------------------------------------------------------------------" << endl;
    }
}

/**
 * @brief Print PostalCodeItems sorted by state and then by ZIP code.
 * Each item's information is printed followed by a separator line.
 * @note Items are sorted first by state (alphabetically) and then by ZIP code (numerically) within each state.
 */
void PostalList::printSortedByState() const
{
    // Copy items so we don’t change the internal order
    vector<PostalCodeItem> sortedItems = items;

    sort(sortedItems.begin(), sortedItems.end(),
         [](const PostalCodeItem &a, const PostalCodeItem &b)
         {
             if (a.getState() == b.getState())
             {
                 return a.getZip() < b.getZip(); // secondary sort by ZIP
             }
             return a.getState() < b.getState();
         });

    for (const auto &item : sortedItems)
    {
        item.printInfo();
        cout << "-----------------------------------------------------------------------------------------------" << endl;
    }
}