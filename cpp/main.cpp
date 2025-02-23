//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include <vector>
#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "manager.h"

#include <sstream>
#include "tcpserver.h"
#include <algorithm>

const int PORT = 3331;

/**
 * Enumeration of available commands
 */
enum command {play, search_obj, search_grp, no_such_command};

/**
 * @brief get and proces the command input by users, return the legal command or error signal
 * 
 * @param cmd input command by users
 * @return processed command
*/
command get_command(const std::string &cmd){
    if (cmd == "play") return play; 
    if (cmd == "search_obj") return search_obj;
    if (cmd == "search_grp") return search_grp;
    return no_such_command;
}


int main(int argc, const char* argv[])
{
    // create a manager for photos 
    manager *my_manager = new manager(); 

    auto p1 = my_manager -> create_photo("photo_ski", "src/ski.jpg", 45.08, 6.07);
    auto v1 = my_manager -> create_video("video_train", "src/train.mp4", 5);
    int chapters[] = {1, 3, 5}; 
    auto f1 = my_manager -> create_film("film_disney", "src/disney.mp4", 5, chapters, 3);

    auto g1 = my_manager -> create_group("my_group");
    g1->push_back(p1);
    g1->push_back(v1);
    g1->push_back(f1); 

    auto* server = new TCPServer([&](std::string const& request, std::string& response) {
        std::string command{};
        std::string file_name{};
        std::istringstream input_stream(request);
        input_stream >> command; // get command input by user

        std::stringstream res_stream = std::stringstream();

        switch (get_command(command))
        {
        case play:
            input_stream >> file_name;
            res_stream.str("");  
            res_stream.clear();
            my_manager -> play_multimedia(file_name);  
            // res_stream << file_name << " is playing...\n";   
            response = res_stream.str();
            break;
        
        case search_obj:
            input_stream >> file_name;
            res_stream.str("");
            res_stream.clear();
            my_manager -> display_multimedia(file_name, res_stream);
            response = res_stream.str();
            std::replace(response.begin(), response.end(), '\n', ';');
            std::cout << response << std::endl;
            break;

        case search_grp:
            input_stream >> file_name;
            res_stream.str("");
            res_stream.clear();
            my_manager -> display_group(file_name, res_stream);
            response = "Searching the multimedia group" + file_name;
            response = res_stream.str();
            std::replace(response.begin(), response.end(), '\n', ';');
            std::cout << response << std::endl;
            break;

        case no_such_command:
            response = "Error, command not found";
            break;
        }

        return true;
    });
        
    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        std::cerr << "Could not start server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}
