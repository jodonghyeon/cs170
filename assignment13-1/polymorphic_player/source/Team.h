#pragma once

#include "PlayerList.h"
#include <string>

namespace HLP2
{

    class Team : public PlayerList
    {
    public:
        explicit Team(std::string the_name, bool owns_data = false);

        const std::string& GetName() const;
        void               SetName(const std::string& the_name);

        int  Rumble(Team& others, int duration);
        bool IsAlive() const;

    private:
        IPlayer* get_random_alive_player() const;

    private:
        std::string name;
    };

}
