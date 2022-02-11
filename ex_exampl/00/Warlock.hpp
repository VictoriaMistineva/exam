#pragma once

#include <iostream>

class Warlock
{
    private:
        std::string name;
        std::string title;

        Warlock();
        Warlock(Warlock const &other);
        Warlock &operator=(Warlock const &other);
    public:
        Warlock(std::string const &name, std::string const &title) 
		{this->name = name; this->title = title; std::cout << this->name << ": This looks like another boring day.\n";};
        ~Warlock() {std::cout << this->name << ": My job here is done!\n";};

        std::string const &getName() const { return (this->name);};
        std::string const &getTitle() const { return (this->title);};

        void setTitle(std::string const &title)  {this->title = title;};

        void introduce() const {std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";};
};