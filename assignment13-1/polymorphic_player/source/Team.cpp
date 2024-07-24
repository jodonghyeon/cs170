#include "Team.h"

#include "PRNG.h"
#include <iostream>

namespace
{
    void do_primary_attack(HLP2::IPlayer* attacker, HLP2::IPlayer* victim);
    void do_secondary_attack(HLP2::IPlayer* attacker, HLP2::IPlayer* victim);
}

namespace HLP2
{

    Team::Team(std::string the_name, bool owns_data) : PlayerList(owns_data), name(std::move(the_name)) { }

    const std::string& Team::GetName() const { return name; }

    void Team::SetName(const std::string& the_name) { name = the_name; }

    bool Team::IsAlive() const
    {
        const int team_count = Count();
        for (int i = 0; i < team_count; i++)
        {
            if (operator[](i)->IsAlive())
            {
                return true;
            }
        }

        return false;
    }

    int Team::Rumble(Team& others, int duration)
    {
        int turn_count = 0;
        for (turn_count = 0; turn_count < duration; turn_count++)
        {
            if (!IsAlive() || !others.IsAlive())
            {
                break;
            }

            const bool     we_attack_others    = (random(0, 1) != 0); // if 1 then we attack them
            IPlayer* const us                  = this->get_random_alive_player();
            IPlayer* const them                = others.get_random_alive_player();
            const bool     attack_with_primary = (random(0, 1) != 0); // If 1, it's a primary attack
            IPlayer* const attacker            = (we_attack_others) ? us : them;
            IPlayer* const victim              = (we_attack_others) ? them : us;
            if (attack_with_primary)
                do_primary_attack(attacker, victim);
            else
                do_secondary_attack(attacker, victim);
        }
        return turn_count;
    }

    IPlayer* Team::get_random_alive_player() const
    {
        IPlayer* alive_player = nullptr;
        do
        {
            const int            player_index = random(0, Count() - 1);
            alive_player                      = this->operator[](player_index);
        } while (!alive_player->IsAlive());
        return alive_player;
    }
}

namespace
{
    void print_if_victim_killed(HLP2::IPlayer* attacker, HLP2::IPlayer* victim)
    {
        if (!victim->IsAlive())
        {
            std::cout << victim->GetName() << " was killed by " << attacker->GetName() << std::endl;
        }
    }

    void do_primary_attack(HLP2::IPlayer* attacker, HLP2::IPlayer* victim)
    {
        std::cout << attacker->GetName() << " (power1=" << attacker->GetPrimaryDamage() << ") is attacking "
                  << victim->GetName() << " (health=" << victim->GetHealth() << ")" << std::endl;
        attacker->PrimaryAttack(*victim);
        print_if_victim_killed(attacker, victim);
    }

    void do_secondary_attack(HLP2::IPlayer* attacker, HLP2::IPlayer* victim)
    {
        std::cout << attacker->GetName() << " (power2=" << attacker->GetSecondaryDamage() << ") is attacking "
                  << victim->GetName() << " (health=" << victim->GetHealth() << ")" << std::endl;
        attacker->SecondaryAttack(*victim);
        print_if_victim_killed(attacker, victim);
    }
}
