//
// Created by Oskar.Norberg on 2025-03-21.
//

#ifndef UPDATEABLE_H
#define UPDATEABLE_H

namespace Components
{
    struct Updateable
    {
        virtual void Update() = 0;
    };
}

#endif //UPDATEABLE_H
