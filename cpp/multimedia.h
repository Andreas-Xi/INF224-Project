#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
/*
ifndef: avoid defining (including) MULTIMEDIA_H multiple times
*/

#include <string>
#include <iostream>

class multimedia
{
private:
    std::string name; 
    std::string filename; 

public:
    multimedia();   
    multimedia(const std::string &name, const std::string &filename);  
    virtual ~multimedia(); 

    /*
    const means that the function will NOT modify the variable inside the instance,
    const function could be used by a const instance, since it would not modify the instance
    */
    std::string get_name() const;   
    std::string get_filename() const;  

    /*
    &: pass value by reference. const std::string& : pass litteral string like "video"
    */
    void set_name(const std::string &name); 
    void set_filename(const std::string &filename); 

    virtual void display(std::ostream &os) const;

    /*
    the virtual function has a default implementation, and the sub-classes can choose whether or not implement it
    however the pure virtual (abstract) function does not have implemantation, and the sub-classes must implement it 
    the abstract class cannot be instantiated anymore 
    */
    virtual void play() const = 0;  
};


#endif