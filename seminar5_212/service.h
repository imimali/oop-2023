//
// Created by Mali Imre Gergely on 08.05.2023.
//

#ifndef SEMINAR5_212_SERVICE_H
#define SEMINAR5_212_SERVICE_H

#include <algorithm>
#include "post.h"
#include "repository.h"

class Service {
    Repository<Post> &repository;
    int next_id;
public:
    Service(Repository<Post> &r) : repository{r} {
        auto elements = r.get_all();
        std::vector<int> ids;
        std::transform(elements.begin(), elements.end(), std::back_inserter(ids),
                       [](const Post &p) {
                           return p.get_id();
                       });
        if (elements.empty()) {
            this->next_id = 0;
            return;
        }
        auto max = std::max(ids.begin(), ids.end());
        this->next_id = *max;

    }

    void add(const string &title, const string &author, const string &content) {
        auto id = ++this->next_id;
        this->repository.add({id, title, author, content});
    }

    void update(int id, const string &title, const string &author, const string &content) {
        this->repository.update({id, title, author, content});
    }

    vector<Post> get_all() {
        return this->repository.get_all();
    }

    vector<Post> filter_by_author(const std::string &author) {
        vector<Post> filtered;
        auto elements = this->repository.get_all();
        std::copy_if(elements.begin(), elements.end(), std::back_inserter(filtered),
                     [author](const Post &p) {
                         return p.get_author() == author;
                     });
        return filtered;
    }


};

#endif //SEMINAR5_212_SERVICE_H
