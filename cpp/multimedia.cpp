#include "multimedia.h"

/**
 * @class multimedia
 * @brief A base class representing a multimedia object.
 *
 * This class provides basic properties and methods for multimedia objects, such as name and filename.
 */

/**
 * @brief Default constructor for the multimedia class.
 *
 * Initializes the name and filename to "unknown".
 */
multimedia::multimedia() {
    name = "unknown"; 
    filename = "unknown";
}

/**
 * @brief Parameterized constructor for the multimedia class.
 *
 * @param name The name of the multimedia object.
 * @param filename The filename of the multimedia object.
 */
multimedia::multimedia(const std::string &name, const std::string &filename) {
    /*
    if there is a name conflict, we should explicitly note [this->variable]
    */
    this->name = name; 
    this->filename = filename; 
}

/**
 * @brief Destructor for the multimedia class.
 *
 * Prints a message indicating the destruction of the multimedia object.
 */
multimedia::~multimedia() {
    std::cout << "Destruction of object multimedia " << name << std::endl;
}

/**
 * @brief Get the name of the multimedia object.
 *
 * @return The name of the multimedia object as a `std::string`.
 */
std::string multimedia::get_name() const {
    return name; 
}

/**
 * @brief Get the filename of the multimedia object.
 *
 * @return The filename of the multimedia object as a `std::string`.
 */
std::string multimedia::get_filename() const {
    return filename; 
}

/**
 * @brief Set the name of the multimedia object.
 *
 * @param name The new name for the multimedia object.
 */
void multimedia::set_name(const std::string &name){
    this->name = name; 
}

/**
 * @brief Set the filename of the multimedia object.
 *
 * @param filename The new filename for the multimedia object.
 */
void multimedia::set_filename(const std::string &filename){ 
    this->filename = filename; 
}

/**
 * @brief Display the information of the multimedia object.
 *
 * @param os The output stream to which the information is written.
 */
void multimedia::display(std::ostream &os) const {
    os << "Name: " << name << ", filename: " << filename << std::endl;
}