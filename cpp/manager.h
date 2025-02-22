#ifndef MANAGER_H
#define MANAGER_H

#include <map>
#include <memory>
#include <string>
#include <iostream>
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"

/**
 * @class manager
 * @brief A class for managing multimedia objects and groups.
 *
 * This class provides functionality to create, find, display, and remove multimedia objects (photos, videos, films) and groups.
 * It uses `std::shared_ptr` to manage the lifetime of multimedia objects and groups.
 */
class manager {
private: 
    std::map<std::string, std::shared_ptr<multimedia>> multimedia_map;  ///< Map to store multimedia objects by name.
    std::map<std::string, std::shared_ptr<group>> group_map;           ///< Map to store groups by name.

public: 
    manager() = default;  ///< Default constructor.
    ~manager() = default; ///< Default destructor.

    /**
     * @brief Create a photo object and add it to the multimedia map.
     *
     * @param name The name of the photo.
     * @param filename The filename of the photo.
     * @param latitude The latitude of the photo's location.
     * @param longitude The longitude of the photo's location.
     * @return A shared pointer to the created photo.
     */
    std::shared_ptr<photo> create_photo(const std::string& name, const std::string& filename, double latitude, double longitude){
        auto p = std::make_shared<photo>(name, filename, latitude, longitude); 
        multimedia_map[name] = p; 
        return p; 
    };

    /**
     * @brief Create a video object and add it to the multimedia map.
     *
     * @param name The name of the video.
     * @param filename The filename of the video.
     * @param duration The duration of the video.
     * @return A shared pointer to the created video.
     */
    std::shared_ptr<video> create_video(const std::string& name, const std::string& filename, int duration){
        auto p = std::make_shared<video>(name, filename, duration); 
        multimedia_map[name] = p; 
        return p; 
    };

    /**
     * @brief Create a film object and add it to the multimedia map.
     *
     * @param name The name of the film.
     * @param filename The filename of the film.
     * @param duration The duration of the film.
     * @param chapters An array of chapter durations.
     * @param num_chapters The number of chapters.
     * @return A shared pointer to the created film.
     */
    std::shared_ptr<film> create_film(const std::string& name, const std::string& filename, int duration, const int* chapters, int num_chapters){
        auto p = std::make_shared<film>(name, filename, duration, chapters, num_chapters); 
        multimedia_map[name] = p; 
        return p; 
    };

    /**
     * @brief Create a group object and add it to the group map.
     *
     * @param name The name of the group.
     * @return A shared pointer to the created group.
     */
    std::shared_ptr<group> create_group(const std::string& name){
        auto p = std::make_shared<group>(name); 
        group_map[name] = p; 
        return p; 
    };

    /**
     * @brief Find and display a multimedia object by name.
     *
     * @param name The name of the multimedia object to find.
     */
    void find_multimedia(const std::string& name) const {
        auto it = multimedia_map.find(name);  // use the iterator to find the key we want 
        /*
        if the key has not been found in the dict, the return value of the iterator would be pointed to the end
        it -> second denotes that we want to access the **value** of the map
        */
        if (it != multimedia_map.end()) {
            it -> second -> display(std::cout); 
        }
        else std::cout << "Multimedia object " << name << " not found" << std::endl; 
    }; 

    /**
     * @brief Find and display a group by name.
     *
     * @param name The name of the group to find.
     */
    void find_group(const std::string& name) const {
        auto it = group_map.find(name); 
        if (it != group_map.end()){ 
            it -> second -> display(std::cout); 
        }
        else std::cout << "Group object " << name << " not found" << std::endl; 
    }; 

    /**
     * @brief Play a multimedia object by name.
     *
     * @param name The name of the multimedia object to play.
     */
    void play_multimedia(const std::string& name) const {
        auto it = multimedia_map.find(name); 
        if (it != multimedia_map.end()) {
            it -> second -> play(); 
        } 
        else std::cout << "Multimedia object " << name << " not found" << std::endl; 
    }; 

    /**
     * @brief Remove a multimedia object by name.
     *
     * @param name The name of the multimedia object to remove.
     */
    void remove_multimedia(const std::string& name) {
        auto it = multimedia_map.find(name); 
        if (it != multimedia_map.end()) {
            /*
            std::list<T> l: l.remove(T name) delete all the object named name
            auto it = l.begin(); l.erase(it); delete an object by an iterator
            */
            // remove the object from the group 
            for (auto& group: group_map){
                group.second -> remove(it -> second);  
            }
            // remove the object from the multimedia list 
            multimedia_map.erase(it); 
        }
        else std::cout << "Multimedia object " << name << " not found" << std::endl; 
    }; 

    /**
     * @brief Remove a group by name.
     *
     * @param name The name of the group to remove.
     */
    void remove_group(const std::string& name) {
        auto it = group_map.find(name); 
        if (it != group_map.end()){
            group_map.erase(it); 
        }
        else std::cout << "Group object " << name << " not found" << std::endl; 
    }; 

    /**
     * @brief Display the information of a specific multimedia object.
     *
     * @param name The name of the multimedia object.
     * @param os The output stream to display the information.
     */
    void display_multimedia(const std::string& name, std::ostream &os) {
        auto it = multimedia_map.find(name);

        if(it != multimedia_map.end()) {
            it -> second -> display(os);
        }
        else {
            os << "Multimedia " << name << " not found "<< std::endl;
        }
    }

    /**
     * @brief Display the information of a specific group.
     *
     * @param name The name of the group.
     * @param os The output stream to display the information.
     */
    void display_group(const std::string& name, std::ostream &os) {
        auto it = group_map.find(name); 

        if(it != group_map.end()) {
            it -> second -> display(os);
        }
        else {
            os << "Group Multimedia " << name << " not found " << std::endl;
        }
    }
}; 

#endif