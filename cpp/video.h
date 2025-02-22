#ifndef VIDEO_H
#define VIDEO_H

#include "multimedia.h"

/**
 * @class video
 * @brief A class representing a video, derived from the multimedia class.
 *
 * This class extends the multimedia class to include the duration of the video.
 */
class video: public multimedia 
{
private: 
    int duration{}; ///< The duration of the video in seconds.

public: 
    /**
     * @brief Default constructor for the video class.
     */
    video(): multimedia(), duration(0) {}; 

    /**
     * @brief Parameterized constructor for the video class.
     *
     * @param name The name of the video.
     * @param filename The filename of the video.
     * @param duration The duration of the video in seconds.
     */
    video(const std::string& name, const std::string& filename, int duration): 
        multimedia(name, filename), duration(duration) {}; 

    /**
     * @brief Display the information of the video.
     *
     * @param os The output stream to which the information is written.
     */
    void display(std::ostream &os) const override {
        os << "Video: "; 
        multimedia::display(os); 
        os << "Duration: " << duration << " seconds" << std::endl; 
    }; 

    /**
     * @brief Play the video using an external application (e.g., mpv).
     */
    void play() const override {
        std::string command = "mpv " + multimedia::get_filename() + " &"; 
        system(command.data()); 
    }

    /**
     * @brief Get the duration of the video.
     *
     * @return The duration of the video in seconds.
     */
    int get_duration() const {return duration; }

    /**
     * @brief Set the duration of the video.
     *
     * @param duration The new duration value in seconds.
     */
    void set_duration(int duration) {this->duration = duration; }
};

#endif