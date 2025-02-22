#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include <iostream>
#include "multimedia.h"
#include <memory>

/**
 * @class group
 * @brief A class representing a group of multimedia objects.
 *
 * This class is derived from `std::list<std::shared_ptr<multimedia>>` and manages a collection of multimedia objects.
 * It uses smart pointers (`std::shared_ptr`) to avoid ownership issues, as multimedia objects may belong to multiple groups.
 */
class group: public std::list<std::shared_ptr<multimedia>> {  
private: 
    std::string name; ///< The name of the group.

public: 
    /**
     * @brief Constructor for the group class.
     *
     * @param name The name of the group.
     */
    group(const std::string &name): name(name) {}

    /**
     * @brief Get the name of the group.
     *
     * @return The name of the group as a `std::string`.
     */
    std::string get_name() const {return name;}

    /**
     * @brief Display information about the group and its multimedia objects.
     *
     * This method outputs the group's name, the number of multimedia objects it contains,
     * and detailed information about each multimedia object.
     *
     * @param os The output stream to which the information is written.
     */
    void display(std::ostream& os) const { 
        os << "Group: " << name << " has " << this->size() << " objects." << std::endl; 
        for (const auto& obj: *this) {
            if (obj) obj -> display(os); 
        }
        os << std::endl; 
    }

    /**
     * @brief Destructor for the group class.
     *
     * The destructor is defaulted since the smart pointers (`std::shared_ptr`) automatically manage memory.
     */
    ~group() {}
}; 

#endif