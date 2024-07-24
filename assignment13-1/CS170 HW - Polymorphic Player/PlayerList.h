#pragma once

#include "Player.h"
#include <istream>
#include <ostream>

namespace HLP2
{

    class PlayerList : public IPersistable
    {
    public:
        explicit PlayerList(bool owns_data = false);
        PlayerList(const PlayerList& sa);
        PlayerList& operator=(const PlayerList& rhs);
        ~PlayerList() override;
        int      Insert(IPlayer* entry);
        void     PopFront();
        int      Count() const;
        void     Save(std::ostream& os) const override;
        void     Load(std::istream& is) override;
        void     Load(const char* filename);
        IPlayer* operator[](int index) const;

    private:

        struct PLNode
        {
            explicit PLNode(IPlayer* player) : Player(player) { }

            PLNode*  Next{ nullptr };
            IPlayer* Player{ nullptr };
        };

        void copy_list(const PLNode* source_ptr);
        void free_list();


        PLNode* head{ nullptr };
        int     count{ 0 };
        bool    ownsData{ true };
    };

}