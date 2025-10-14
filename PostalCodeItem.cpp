/**
 * @file PostalCodeItem.cpp
 * @brief Implementation of the PostalCodeItem class representing a postal code entry.
 * * @author
 *  Asfaw, Abel,
 *  Farah, Mahad,
 *  Kariniemi, Carson,
 *  Rogers, Mitchell
 *  Tran, Minh Quan
 * @version 1.0
 * @date 2025-9-23
 */

/**
 * @brief Implementation of the PostalCodeItem class.
 * This class encapsulates information about a postal code, including its ZIP code, place name, state, county, latitude, and longitude.
 * It provides methods to access and modify these details, as well as a method to print the information in a readable format.
 * @note This class is designed to be used in conjunction with a PostalList class for managing collections of postal code entries.
 * @see PostalList
 * @see PostalCodeItem.h
 */

#include "PostalCodeItem.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/**
 * @brief Default constructor initializing member variables to default values.
 * zip is set to 0, place, state, and county are set to empty strings,
 * and latitude and longitude are set to 0.0.
 * This ensures that a PostalCodeItem object starts with a known state.
 * @note This constructor can be used to create an empty PostalCodeItem object,
 * which can later be populated with actual data using the setter methods.
 * @see PostalCodeItem(int, const string&, const string&, const string&, double, double)
 * @see setZip(int)
 * @see setPlace(const string&)
 * @see setState(const string&)
 * @see setCounty(const string&)
 * @see setLatitude(double)
 * @see setLongitude(double)
 * @see printInfo() const
 */
PostalCodeItem::PostalCodeItem()
{
    zip = 0;
    place = "";
    state = "";
    county = "";
    latitude = 0;
    longitude = 0;
}

/**
 * @brief Parameterized constructor to initialize a PostalCodeItem with specific values.
 * @param z The ZIP code (integer).
 * @param p The place name (string).
 * @param s The state name (string).
 * @param c The county name (string).
 * @param lat The latitude (double).
 * @param lon The longitude (double).
 * This constructor allows for the creation of a fully initialized PostalCodeItem object.
 * @note Ensure that the provided values are valid and meaningful for the postal code entry.
 */
PostalCodeItem::PostalCodeItem(int z, const string &p, const string &s, const string &c, double lat, double lon)
{
    zip = z;
    place = p;
    state = s;
    county = c;
    latitude = lat;
    longitude = lon;
}

/**
 * @brief Get the ZIP code of the postal code item.
 * @return The ZIP code as an integer.
 */
int PostalCodeItem::getZip() const
{
    return zip;
}

/**
 * @brief Get the place name of the postal code item.
 * @return The place name as a string.
 */
string PostalCodeItem::getPlace() const
{
    return place;
}

/**
 * @brief Get the state name of the postal code item.
 * @return The state name as a string.
 */
string PostalCodeItem::getState() const
{
    return state;
}

/**
 * @brief Get the county name of the postal code item.
 * @return The county name as a string.
 * @note County names may vary in format and length depending on the region.
 * Ensure that the county name is correctly formatted for display or processing.
 */
string PostalCodeItem::getCounty() const
{
    return county;
}

/**
 * @brief Get the latitude of the postal code item.
 * @return The latitude as a double.
 * @note Latitude values are typically in the range of -90 to 90 degrees.
 */
double PostalCodeItem::getLatitude() const
{
    return latitude;
}

/**
 * @brief Get the longitude of the postal code item.
 * @return The longitude as a double.
 * @note Longitude values are typically in the range of -180 to 180 degrees.
 */
double PostalCodeItem::getLongitude() const
{
    return longitude;
}

/**
 * @brief Set the ZIP code of the postal code item.
 * @param newZip The new ZIP code to be set (integer).
 * @note Ensure that the new ZIP code is a valid integer value.
 */
void PostalCodeItem::setZip(int newZip)
{
    zip = newZip;
}

/**
 * @brief Set the place name of the postal code item.
 * @param newPlace The new place name to be set (string).
 * @note Ensure that the new place name is a valid string value.
 */
void PostalCodeItem::setPlace(const string &newPlace)
{
    place = newPlace;
}

/**
 * @brief Set the state name of the postal code item.
 * @param newState The new state name to be set (string).
 * @note Ensure that the new state name is a valid string value.
 */
void PostalCodeItem::setState(const string &newState)
{
    state = newState;
}

/**
 * @brief Set the county name of the postal code item.
 * @param newCounty The new county name to be set (string).
 * @note Ensure that the new county name is a valid string value.
 */
void PostalCodeItem::setCounty(const string &newCounty)
{
    county = newCounty;
}

/**
 * @brief Set the latitude of the postal code item.
 * @param newLat The new latitude to be set (double).
 * @note Ensure that the new latitude is within the valid range of -90 to 90 degrees.
 * Invalid latitude values may lead to incorrect geographical representations.
 */
void PostalCodeItem::setLatitude(double newLat)
{
    latitude = newLat;
}

/**
 * @brief Set the longitude of the postal code item.
 * @param newLon The new longitude to be set (double).
 * @note Ensure that the new longitude is within the valid range of -180 to 180 degrees.
 * Invalid longitude values may lead to incorrect geographical representations.
 */
void PostalCodeItem::setLongitude(double newLon)
{
    longitude = newLon;
}

/**
 * @brief Print the postal code item's information in a formatted manner.
 * The information includes ZIP code, place name, state, county, latitude, and longitude.
 * The output is aligned in columns for better readability.
 * @note This method uses standard output (cout) to display the information.
 */
void PostalCodeItem::printInfo() const
{
    cout << left << setw(10) << zip
         << setw(20) << place
         << setw(10) << state
         << setw(30) << county
         << setw(12) << latitude
         << setw(12) << longitude
         << endl;
}