//
// Created by work on 23.09.2024.
//

#ifndef CPP_SCHEME_ENVIRONMENT_H
#define CPP_SCHEME_ENVIRONMENT_H


#include <list>
#include <memory>
#include "Frame.h"

class Environment {
public:
    static std::shared_ptr<Environment> global_root;
private:
    std::list<std::shared_ptr<Frame>> _frames;
public:
    Environment();
    Environment(const std::shared_ptr<Frame>& addition_frame,
                std::list<std::shared_ptr<Frame>>::iterator begin,
                std::list<std::shared_ptr<Frame>>::iterator end);

    bool has(LispObjectRef symbol);
    LispObjectRef get(LispObjectRef symbol);
    void set(LispObjectRef symbol, LispObjectRef obj);
    std::shared_ptr<Environment> extend();
};


#endif //CPP_SCHEME_ENVIRONMENT_H
