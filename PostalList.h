/**
 * @file PostalList.h
 * @brief Defines the PostalList class for managing collections of postal codes.
 * @author
 *  Asfaw, Abel,
 *  Farah, Mahad,
 *  Kariniemi, Carson,
 *  Rogers, Mitchell
 *  Tran, Minh Quan
 * The PostalList class provides storage and utility functions for handling
 * multiple PostalCodeItem objects, including adding, searching, and printing
 * data in sorted order.
 */

#ifndef POSTAL_LIST_H
#define POSTAL_LIST_H

#include "PostalCodeItem.h"
#include <vector>

using namespace std;

class PostalList
{
private:
    vector<PostalCodeItem> items; /**< Internal storage for postal code entries */

public:
    // Constructors
    PostalList() = default;

    /**
     * @brief Add a PostalCodeItem to the list.
     * @param item The PostalCodeItem to be added.
     */
    void addItem(const PostalCodeItem &item);

    /**
     * @brief Get a PostalCodeItem by index.
     * @param index The index of the item to retrieve.
     * @return The PostalCodeItem at the specified index.
     * @throws out_of_range if the index is invalid.
     */
    PostalCodeItem getItem(int index) const;

    /**
     * @brief Find a PostalCodeItem by its ZIP code.
     * @param zip The ZIP code to search for.
     * @return A pointer to the PostalCodeItem if found, nullptr otherwise.
     * @note The returned pointer is valid as long as the PostalList object exists and is not modified.
     */
    const PostalCodeItem *findByZip(int zip) const;

    /**
     * @brief Get the number of items in the list.
     * @return The number of PostalCodeItem objects in the list.
     */
    int size() const;

    /**
     * @brief Print all PostalCodeItems in the list.
     * Each item's information is printed followed by a separator line.
     * @note The order of items is the same as the order they were added.
     */
    void printAll() const;

    /**
     * @brief Print PostalCodeItems sorted by ZIP code.
     * Each item's information is printed followed by a separator line.
     * @note Items are sorted in ascending order by ZIP code.
     */
    void printSortedByZip() const;

    /**
     * @brief Print PostalCodeItems sorted by state and then by ZIP code.
     * Each item's information is printed followed by a separator line.
     * @note Items are sorted first by state (alphabetically) and then by ZIP code (numerically) within each state.
     */
    void printSortedByState() const;
};

#include "PostalList.cpp"
#endif