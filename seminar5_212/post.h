//
// Created by Mali Imre Gergely on 08.05.2023.
//

#ifndef SEMINAR5_212_POST_H
#define SEMINAR5_212_POST_H

#include <string>

using std::string;

class Post {
    int id;
    string title;
    string author;
    string content;
public:
    Post(int id, const string &title, const string &author, const string &content) :
            id{id},
            title{title},
            author{author},
            content{content} {}

    int get_id() const { return this->id; }

    string get_title() const { return this->title; }

    string get_author() const { return this->author; }

    string get_content() const { return this->content; }

    bool operator==(const Post &elem) {
        return this->id == elem.id;
    }

};

#endif //SEMINAR5_212_POST_H
