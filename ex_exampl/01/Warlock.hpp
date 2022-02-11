#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class Warlock
{
    private:
        std::string name;
        std::string title;

        Warlock();
        Warlock(Warlock const &other);
        Warlock &operator=(Warlock const &other);

        std::map<std::string, ASpell *> arr;
        
    public:

        Warlock(std::string const &name, std::string const &title) 
		{this->name = name; this->title = title; std::cout << this->name << ": This looks like another boring day.\n";};

        ~Warlock()
        {
            std::cout << this->name << ": My job here is done!\n";
            std::map<std::string, ASpell *>::iterator it_begin = this->arr.begin();
            std::map<std::string, ASpell *>::iterator it_end = this->arr.end();
            while (it_begin != it_end)
            {
                delete it_begin->second;
                ++it_begin;
            }
            this->arr.clear();
        };

        std::string const &getName() const { return (this->name);};
        std::string const &getTitle() const { return (this->title);};

        void setTitle(std::string const &title)  {this->title = title;};

        void introduce() const {std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";};

        void learnSpell(ASpell *spell_ptr)
        {
            if (spell_ptr)
		    arr.insert(std::pair<std::string, ASpell *>(spell_ptr->getName(), spell_ptr->clone()));
        };

        void forgetSpell(std::string spell_name) 
        {
            std::map<std::string, ASpell *>::iterator it = arr.find(spell_name);
	        if (it != arr.end())
		        delete it->second;
	        arr.erase(spell_name);
        };

        void launchSpell(std::string spell_name, ATarget const &target_ref)
        {
            ASpell* spell = arr[spell_name];
	        if (spell)
		        spell->launch(target_ref);
        };
};
