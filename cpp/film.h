#ifndef FILM_H
#define FILM_H

#include "video.h"

/**
 * @class film
 * @brief A class representing a film, derived from the video class.
 *
 * This class extends the video class to include information about the chapters of a film.
 */
class film : public video 
{
private: 
    int* chapters{nullptr}; ///< Pointer to an array of chapter durations.
    int num_chapters{};     ///< Number of chapters in the film.

public: 
    /**
     * @brief Default constructor for the film class.
     */
    film(): video(), chapters(nullptr), num_chapters(0) {}; 

    /**
     * @brief Parameterized constructor for the film class.
     *
     * @param name The name of the film.
     * @param filename The filename of the film.
     * @param duration The total duration of the film.
     * @param chapters An array of chapter durations.
     * @param num_chapters The number of chapters in the film.
     */
    film(const std::string& name, const std::string& filename, int duration, const int* chapters, int num_chapters)
        : video(name, filename, duration), num_chapters(num_chapters) {
        if (num_chapters > 0){
            this -> chapters = new int[num_chapters]; 
            for (int i=0; i<num_chapters; i++){
                this -> chapters[i] = chapters[i]; 
            }
        }
        else this -> chapters = nullptr;
    }

    /**
     * @brief Copy constructor for the film class.
     *
     * @param other The film object to copy from.
     */
    film(const film& other): num_chapters(other.num_chapters)  // film f1 = f2; film f2(f1) - would call this function
    {
        chapters = new int[num_chapters]; 
        for (int i=0; i<num_chapters; i++){
            chapters[i] = other.chapters[i]; 
        }
    }

    /**
     * @brief Destructor for the film class.
     *
     * Frees the memory allocated for the chapters array.
     */
    ~film(){delete[] chapters;} 

    /**
     * @brief Assignment operator for the film class.
     *
     * @param other The film object to assign from.
     * @return A reference to the current film object.
     */
    film& operator=(const film& other){
        if (this != &other) {
            video::operator=(other); // call the operator of the base class
            delete[] chapters; 
            std::cout << "hello" << std::endl; 
            num_chapters = other.num_chapters; 
            if (num_chapters > 0){
                chapters = new int[num_chapters]; 
                for (int i=0; i<num_chapters; i++){
                    chapters[i] = other.chapters[i]; 
                }
            }
            else{
                chapters = nullptr; 
            }
        }
        return *this; 
    }

    /**
     * @brief Get the number of chapters in the film.
     *
     * @return The number of chapters.
     */
    int get_num_chapters () const {return num_chapters;}

    /**
     * @brief Get the array of chapter durations.
     *
     * @return A pointer to the array of chapter durations.
     */
    const int* get_chapters() const {return chapters;}  // use const int* to avoid modifying chapters from outside of the function

    /**
     * @brief Set the chapters of the film.
     *
     * @param chapters An array of chapter durations.
     * @param num_chapters The number of chapters.
     */
    void set_chapters(const int* chapters, int num_chapters){ 
        delete[] this->chapters;  // destroy the original chapter and create a new one
        this->num_chapters = num_chapters; 
        this->chapters = new int[num_chapters]; 
        for (int i=0; i<num_chapters; i++){
            this->chapters[i] = chapters[i]; 
        }
    }

    /**
     * @brief Display the film's information, including its filename and file source, and the duration of each chapter
     *
     * @param os The output stream to display the information.
     */
    void display(std::ostream &os) const override {
        os << "Film: "; 
        multimedia::display(os); 
        for (int i=0; i<num_chapters; i++){
            os << "Chapter" << i << " has duration:" << chapters[i] << std::endl; 
        }
    }
}; 

#endif