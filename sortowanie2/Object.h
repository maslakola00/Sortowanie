#pragma once
#include <string>


class Object{
private:

    std::string title;
    int ranking;

public:
    int  get_ranking(){

        return ranking;
    }

    std::string get_title() {

        return title;
    }

    void set_ranking(int number){

        ranking=number;

    }
    void set_title(const std::string &movie){

     title=movie;

    }



};

