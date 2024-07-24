#pragma once

#include <string>

namespace HLP2
{

    class ICloneable
    {
    public:
        virtual ICloneable* Clone() const = 0;


        ICloneable()                             = default;
        virtual ~ICloneable()                    = default;
        ICloneable(const ICloneable&)            = default;
        ICloneable& operator=(const ICloneable&) = default;
    };

    class IPersistable
    {
    public:
        virtual void Load(std::istream& is)       = 0;
        virtual void Save(std::ostream& os) const = 0;


        IPersistable()                               = default;
        virtual ~IPersistable()                      = default;
        IPersistable(const IPersistable&)            = default;
        IPersistable& operator=(const IPersistable&) = default;
    };

    class IComparable
    {
    public:
        virtual int CompareTo(const IComparable& other) const = 0;


        IComparable()                              = default;
        virtual ~IComparable()                     = default;
        IComparable(const IComparable&)            = default;
        IComparable& operator=(const IComparable&) = default;
    };

    class IPlayer : public ICloneable, public IPersistable, public IComparable
    {
    public:
        IPlayer(std::string the_name, int the_health, int primary_damage, int secondary_damage);
        IPlayer(const IPlayer& rhs);
        ~IPlayer() override;
        IPlayer& operator=(const IPlayer&) = delete;


        virtual std::string WhoAmI() const                        = 0;
        virtual void        PrimaryAttack(IPlayer& other) const   = 0;
        virtual void        SecondaryAttack(IPlayer& other) const = 0;
        virtual void        TakeDamage(int damage)                = 0;
        IPlayer*            Clone() const override                = 0;

        void Save(std::ostream& os) const override;
        void Load(std::istream& is) override;
        int  CompareTo(const IComparable& other) const override;

        virtual const char* GetType() const;
        const std::string&  GetName() const;
        int                 GetHealth() const;
        int                 GetPrimaryDamage() const;
        int                 GetSecondaryDamage() const;

        bool IsAlive() const;

        static int PlayersCreated();
        static int PlayersActive();

    protected:
        void setName(const std::string& the_name);
        void setHealth(int the_health);
        void setPrimaryDamage(int damage);
        void setSecondaryDamage(int damage);

    private:
        std::string name;
        int         health;
        int         primaryDamage;
        int         secondaryDamage;

        inline static int NumCreated = 0;
        inline static int NumActive  = 0;
    };

}
