#ifndef PHOTO_H
#define PHOTO_H

#include "multimedia.h"

/**
 * @class photo
 * @brief A class representing a photo, derived from the multimedia class.
 *
 * This class extends the multimedia class to include geographical coordinates (latitude and longitude) for the photo.
 */
class photo : public multimedia
{
private: 
    double longitude{}; ///< The longitude of the photo's location.
    double latitude{};  ///< The latitude of the photo's location.

public: 
    /**
     * @brief Default constructor for the photo class.
     */
    photo(){}; 

    /**
     * @brief Parameterized constructor for the photo class.
     *
     * @param name The name of the photo.
     * @param filename The filename of the photo.
     * @param latitude The latitude of the photo's location.
     * @param longitude The longitude of the photo's location.
     */
    photo(const std::string &name, const std::string &filename, double latitude, double longitude):
        multimedia(name, filename), longitude(longitude), latitude(latitude) {}

    /**
     * @brief Display the information of the photo.
     *
     * @param os The output stream to which the information is written.
     */
    void display(std::ostream &os) const override {
        os << "Photo: "; 
        multimedia::display(os); 
        os << "Latitude: " << latitude << ", longitude: " << longitude << std::endl; 
    }

    /**
     * @brief Play the photo using an external application (e.g., ImageJ).
     */
    void play() const override {
        std::string command = "imagej " + multimedia::get_filename() + " &"; 
        // .data() method converts string to char* (the type of argument in system())
        system(command.data()); 
    }

    /**
     * @brief Get the longitude of the photo's location.
     *
     * @return The longitude as a double.
     */
    double get_longitude() const {return longitude; }

    /**
     * @brief Get the latitude of the photo's location.
     *
     * @return The latitude as a double.
     */
    double get_latitude() const {return latitude; }

    /**
     * @brief Set the longitude of the photo's location.
     *
     * @param longitude The new longitude value.
     */
    void set_longitude(double longitude) {this -> longitude = longitude; }

    /**
     * @brief Set the latitude of the photo's location.
     *
     * @param latitude The new latitude value.
     */
    void set_latitude(double latitude) {this -> latitude = latitude; }
};

#endif