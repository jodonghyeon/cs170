#include "PRNG.h"
#include "Player.h"
#include "PlayerList.h"
#include "Pyro.h"
#include "Scout.h"
#include "Soldier.h"
#include "SubscriptError.h"
#include "Team.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <typeinfo>
#include <utility>

#define xTESTSIMPLE1
#define xTESTSIMPLE2
#define xTESTLIST1
#define xTESTLIST2
#define xTESTLIST3
#define xTESTLIST4
#define xTESTLOADSAVE1
#define xTESTLOADSAVE2
#define xTESTOWNS1
#define xTESTCOPY
#define xTESTASSIGN1
#define xTESTASSIGN2
#define xTESTASSIGN3
#define xTESTEH1
#define xTESTEH2
#define xTESTFIGHT1
#define xTESTFIGHT2
#define xTESTCOMPARE1
#define xTESTCOMPARE2
#define xTESTCOMPARE3
#define xTESTALL


#if defined(TESTSIMPLE1) || defined(TESTALL)
void test_simple1()
{
    const char* fn = "TestSimple1";
    std::cout << "\n========== " << fn << " ==========\n";
    try
    {
        auto* scout   = new HLP2::Scout("Moe", 100, 1, 5);
        auto* soldier = new HLP2::Soldier("Larry", 150, 2, 10);
        auto* pyro    = new HLP2::Pyro("Curly", 200, 3, 10, 20);

        std::cout << scout->WhoAmI() << std::endl;
        std::cout << soldier->WhoAmI() << std::endl;
        std::cout << pyro->WhoAmI() << std::endl;

        delete scout;
        delete soldier;
        delete pyro;
        return;
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_simple1() { }
#endif


#if defined(TESTSIMPLE2) || defined(TESTALL)
void test_simple2()
{
    const char* fn = "TestSimple2";
    std::cout << "\n========== " << fn << " ==========\n";
    try
    {
        HLP2::IPlayer* p[3];

        p[0] = new HLP2::Scout("Moe");
        p[1] = new HLP2::Soldier("Larry");
        p[2] = new HLP2::Pyro("Curly");


        for (auto& i : p)
        {
            std::cout << i->WhoAmI() << std::endl;
            delete i;
        }

        return;
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_simple2() { }
#endif


#if defined(TESTLIST1) || defined(TESTALL)
void test_list1()
{
    const char* fn = "TestList1";
    std::cout << "\n========== " << fn << " ==========\n";
    try
    {
        HLP2::PlayerList list(true);
        int              index = 0;

        index = list.Insert(new HLP2::Pyro("Curly"));
        std::cout << "Index is " << index << std::endl;

        index = list.Insert(new HLP2::Scout("Moe"));
        std::cout << "Index is " << index << std::endl;

        index = list.Insert(new HLP2::Soldier("Larry"));
        std::cout << "Index is " << index << std::endl;

        index = list.Insert(new HLP2::Soldier("Shemp"));
        std::cout << "Index is " << index << std::endl;

        for (int i = 0; i < list.Count(); i++)
        {
            std::cout << list[i]->WhoAmI() << std::endl;
        }

        return;
    }
    catch (const HLP2::SubscriptError& e)
    {
        std::cout << "***** SubscriptError caught in TestList1: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_list1() { }
#endif


#if defined(TESTLIST2) || defined(TESTALL)
void test_list2()
{
    const char* fn = "TestList2";
    std::cout << "\n========== " << fn << " ==========\n";
    try
    {
        HLP2::PlayerList list(true);
        list.Insert(new HLP2::Scout("Moe"));
        list.Insert(new HLP2::Soldier("Larry"));
        list.Insert(new HLP2::Pyro("Curly"));

        int i = 0;
        for (i = 0; i < list.Count(); i++)
        {
            std::cout << list[i]->WhoAmI() << std::endl;
        }

        list.PopFront();
        list.PopFront();

        for (i = 0; i < list.Count(); i++)
        {
            std::cout << list[i]->WhoAmI() << std::endl;
        }

        return;
    }
    catch (const HLP2::SubscriptError& e)
    {
        std::cout << "***** SubscriptError caught in TestList2: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_list2() { }
#endif


#if defined(TESTLIST3) || defined(TESTALL)
void test_list3()
{
    const char* fn = "TestList3";
    std::cout << "\n========== " << fn << " ==========\n";
    try
    {
        HLP2::PlayerList list(true);
        list.Insert(new HLP2::Scout("Moe", 100, 1, 11));
        list.Insert(new HLP2::Soldier("Larry", 150, 2, 22));
        list.Insert(new HLP2::Pyro("Curly", 200, 3, 13, 33));

        int i = 0;
        for (i = 0; i < list.Count(); i++)
        {
            list[i]->Save(std::cout);
            std::cout << std::endl;
        }

        std::cout << std::endl;
        list.Save(std::cout);

        return;
    }
    catch (const HLP2::SubscriptError& e)
    {
        std::cout << "***** SubscriptError caught in TestList3: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_list3() { }
#endif


#if defined(TESTLIST4) || defined(TESTALL)
void test_list4()
{
    const char* fn = "TestList4";
    std::cout << "\n========== " << fn << " ==========\n";
    try
    {
        HLP2::PlayerList list(true);
        list.Insert(new HLP2::Scout("Moe"));
        list.Insert(new HLP2::Soldier("Larry"));
        list.Insert(new HLP2::Pyro("Curly"));
        list.Save(std::cout);

        return;
    }
    catch (const HLP2::SubscriptError& e)
    {
        std::cout << "***** SubscriptError caught in TestList4: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_list4() { }
#endif

void read(HLP2::IPersistable& obj, std::ifstream& in) { obj.Load(in); }

void write(const HLP2::IPersistable& obj, std::ostream& out) { obj.Save(out); }


#if defined(TESTLOADSAVE1) || defined(TESTALL)
void test_load_save1()
{
    const char* fn = "TestLoadSave1";
    std::cout << "\n========== " << fn << " ==========\n";
    try
    {
        HLP2::PlayerList pl(true);

        const char*   file = "Team1.txt";
        std::ifstream is(file);
        if (is.is_open())
        {
            read(pl, is);
        }
        else
        {
            std::cout << "Can't open file: " << file << std::endl;
            return;
        }

        for (int i = 0; i < pl.Count(); i++)
        {
            std::cout << pl[i]->GetType() << " ";
            write(*pl[i], std::cout);
            std::cout << std::endl;
        }
        return;
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_load_save1() { }
#endif


#if defined(TESTLOADSAVE2) || defined(TESTALL)
void test_load_save2()
{
    const char* fn = "TestLoadSave2";
    std::cout << "\n========== " << fn << " ==========\n";
    try
    {
        HLP2::PlayerList pl(true);
        pl.Load("Team1.txt");
        pl.Save(std::cout);
        return;
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_load_save2() { }
#endif


#if defined(TESTCOPY) || defined(TESTALL)
void test_copy()
{
    const char* fn = "TestCopy";
    std::cout << "\n========== " << fn << " ==========\n";
    try
    {
        HLP2::Team reds("Reds", true);

        reds.Load("RedTeam.txt");
        std::cout << "Red team:\n";
        std::cout << "----------------\n";
        reds.Save(std::cout);

        HLP2::Team copy(reds);
        std::cout << "\nCopy using copy ctor:\n";
        std::cout << "----------------\n";
        copy.Save(std::cout);
        return;
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_copy() { }
#endif


#if defined(TESTASSIGN1) || defined(TESTALL)
void test_assign1()
{
    const char* fn = "TestAssign1";
    std::cout << "\n========== " << fn << " ==========\n";
    try
    {
        HLP2::Team reds("Reds", true);

        reds.Load("RedTeam.txt");
        std::cout << "Red team:\n";
        std::cout << "----------------\n";
        reds.Save(std::cout);

        auto* home = new HLP2::Team("Home", true);
        *home      = reds;
        std::cout << "\nCopy via assignment:\n";
        std::cout << "----------------\n";
        home->Save(std::cout);
        delete home;
        return;
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_assign1() { }
#endif


#if defined(TESTASSIGN2) || defined(TESTALL)
void test_assign2()
{
    const char* fn = "TestAssign2";
    std::cout << "\n========== " << fn << " ==========\n";
    try
    {
        HLP2::Team reds("Reds", true);

        reds.Load("RedTeam.txt");
        std::cout << "Red team:\n";
        std::cout << "----------------\n";
        reds.Save(std::cout);

        std::cout << "\nCopy via self-assignment:\n";
        std::cout << "----------------\n";
        HLP2::Team& reds_ref = reds;
        reds                 = reds_ref;
        reds.Save(std::cout);
        return;
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_assign2() { }
#endif


#if defined(TESTASSIGN3) || defined(TESTALL)
void test_assign3()
{
    const char* fn = "TestAssign3";
    std::cout << "\n========== " << fn << " ==========\n";
    try
    {
        HLP2::Team reds("Reds", true);

        reds.Load("RedTeam.txt");
        std::cout << "Red team:\n";
        std::cout << "----------------\n";
        reds.Save(std::cout);

        auto* blue = new HLP2::Team("Blue", true);
        blue->Load("BlueTeam.txt");
        std::cout << "Blue team:\n";
        std::cout << "----------------\n";
        blue->Save(std::cout);

        std::cout << "\nCopy via assignment:\n";
        std::cout << "----------------\n";
        *blue = reds;
        blue->Save(std::cout);
        delete blue;
        return;
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_assign3() { }
#endif


#if defined(TESTOWNS1) || defined(TESTALL)
void test_owns1()
{
    const char* fn = "TestOwns1";
    std::cout << "\n========== " << fn << " ==========\n";
    try
    {
        auto* scout   = new HLP2::Scout("Moe");
        auto* soldier = new HLP2::Soldier("Larry");
        auto* pyro    = new HLP2::Pyro("Curly");


        auto* home = new HLP2::Team("Home", false);
        home->Insert(scout);
        home->Insert(soldier);
        home->Insert(pyro);

        home->Save(std::cout);


        delete scout;
        delete soldier;
        delete pyro;

        delete home;

        return;
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_owns1() { }
#endif


#if defined(TESTEH1) || defined(TESTALL)
void test_exception_handling1()
{
    const char* fn = "TestEH1";
    std::cout << "\n========== " << fn << " ==========\n";

    HLP2::PlayerList red(true);
    try
    {
        red.Load("Team1.txt");
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
        std::cout << "***** Failed " << fn << std::endl;
        return;
    }

    try
    {
        for (int i = 0; i < red.Count() + 1; i++)
        {
            red[i]->WhoAmI();
        }
    }
    catch (std::exception&)
    {
        std::cout << "std::exception caught in TestEH" << std::endl;
        return;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
        return;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_exception_handling1() { }
#endif


#if defined(TESTEH2) || defined(TESTALL)
void test_exception_handling2()
{
    const char* fn = "TestEH2";
    std::cout << "\n========== " << fn << " ==========\n";

    HLP2::PlayerList red(true);
    try
    {
        red.Load("Team1.txt");
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
        std::cout << "***** Failed " << fn << std::endl;
        return;
    }

    try
    {
        for (int i = 0; i < red.Count() + 1; i++)
        {
            red[i]->WhoAmI();
        }
    }
    catch (const HLP2::SubscriptError& e)
    {
        std::cout << "SubscriptError caught in TestEH: Bad subscript is " << e.GetSubscript() << std::endl;
        return;
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_exception_handling2() { }
#endif


#if defined(TESTFIGHT1) || defined(TESTALL)
void test_fight1()
{
    const char* fn = "TestFight1";
    std::cout << "\n========== " << fn << " ==========\n";

    try
    {
        HLP2::Scout   scout("Moe", 50, 1, 5);
        HLP2::Soldier soldier("Larry", 100, 2, 10);
        HLP2::Pyro    pyro("Curly", 150, 3, 10, 20);

        std::cout << "\nBefore:\n";
        scout.Save(std::cout);
        std::cout << std::endl;
        soldier.Save(std::cout);
        std::cout << std::endl;
        pyro.Save(std::cout);
        std::cout << std::endl;

        scout.PrimaryAttack(pyro);
        soldier.PrimaryAttack(pyro);
        pyro.PrimaryAttack(soldier);
        pyro.Burn(scout);
        soldier.SecondaryAttack(scout);
        pyro.Burn(soldier);
        scout.SecondaryAttack(soldier);
        scout.SecondaryAttack(pyro);
        soldier.SecondaryAttack(pyro);

        while (soldier.IsAlive())
        {
            soldier.SecondaryAttack(soldier);
        }

        std::cout << "\nAfter:\n";
        scout.Save(std::cout);
        std::cout << std::endl;
        soldier.Save(std::cout);
        std::cout << std::endl;
        pyro.Save(std::cout);
        std::cout << std::endl;

        return;
    }
    catch (std::exception& e)
    {
        std::cout << "std::exception caught in TestFight1: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_fight1() { }
#endif


#if defined(TESTFIGHT2) || defined(TESTALL)
void test_fight2()
{
    const char* fn = "TestFight2";
    std::cout << "\n========== " << fn << " ==========\n";

    try
    {
        HLP2::Team red("Red", true);
        HLP2::Team blue("Blue", true);

        red.Load("RedTeam.txt");
        std::cout << "Red team:\n";
        std::cout << "----------------\n";
        red.Save(std::cout);

        blue.Load("BlueTeam.txt");
        std::cout << "\nBlue team:\n";
        std::cout << "----------------\n";
        blue.Save(std::cout);

        std::cout << std::endl;

        HLP2::srand(0, 0);
        int rounds = red.Rumble(blue, 50);

        std::cout << "\n*********** Outcome ************\n";

        std::cout << "\nAfter " << rounds << " rounds, players still standing:" << std::endl;
        std::cout << "*** " << red.GetName() << " ***\n";
        int i = 0;
        for (i = 0; i < red.Count(); i++)
        {
            if (red[i]->IsAlive())
            {
                std::cout << red[i]->GetName() << " with " << red[i]->GetHealth() << " health points.\n";
            }
        }

        std::cout << "*** " << blue.GetName() << " ***\n";
        for (i = 0; i < blue.Count(); i++)
        {
            if (blue[i]->IsAlive())
            {
                std::cout << blue[i]->GetName() << " with " << blue[i]->GetHealth() << " health points.\n";
            }
        }

        return;
    }
    catch (std::exception& e)
    {
        std::cout << "std::exception caught in TestFight2: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_fight2() { }
#endif

class MyString : public HLP2::IComparable
{
public:
    explicit MyString(std::string a_string) : string(std::move(a_string)) { }

    virtual ~MyString() = default;

    int CompareTo(const HLP2::IComparable& /*other*/) const override { return 0; }

private:
    std::string string;
};


#if defined(TESTCOMPARE1) || defined(TESTALL)

void test_compare1()
{
    const char* fn = "TestCompare1";
    std::cout << "\n========== " << fn << " ==========\n";
    try
    {
        HLP2::Scout scout("Moe");
        std::cout << scout.WhoAmI() << std::endl;

        MyString s("Hello");
        scout.CompareTo(s);
        return;
    }
    catch (const std::bad_cast& e)
    {
        std::cout << "***** bad_cast caught in " << fn << ": " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_compare1() { }
#endif


#if defined(TESTCOMPARE2) || defined(TESTALL)

void test_compare2()
{
    const char* fn = "TestCompare2";
    std::cout << "\n========== " << fn << " ==========\n";
    try
    {
        auto* scout = new HLP2::Scout("Moe");
        std::cout << scout->WhoAmI() << std::endl;

        MyString s("Hello");
        scout->CompareTo(s);
        return;
    }
    catch (const std::bad_cast& e)
    {
        std::cout << "***** bad_cast caught in " << fn << ": " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_compare2() { }
#endif


#if defined(TESTCOMPARE3) || defined(TESTALL)

void test_compare3()
{
    const char* fn = "TestCompare3";
    std::cout << "\n========== " << fn << " ==========\n";
    try
    {
        std::unique_ptr<HLP2::Scout> scout(new HLP2::Scout("Moe"));
        std::cout << scout->WhoAmI() << std::endl;

        MyString s("Hello");
        scout->CompareTo(s);
        return;
    }
    catch (const std::bad_cast& e)
    {
        std::cout << "***** bad_cast caught in " << fn << ": " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "***** Something bad happened in " << fn << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "***** Something bad happened in " << fn << std::endl;
    }
    std::cout << "***** Failed " << fn << std::endl;
}
#else
void test_compare3() { }
#endif


void run_tests()
{
    try
    {
        test_simple1();
        test_simple2();
        test_list1();
        test_list2();
        test_list3();
        test_list4();
        test_load_save1();
        test_load_save2();
        test_owns1();
        test_copy();
        test_assign1();
        test_assign2();
        test_assign3();
        test_exception_handling1();
        test_exception_handling2();
        test_fight1();
        test_fight2();
        test_compare1();
        test_compare2();
        test_compare3();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Unexpected Exception caught" << std::endl;
    }
}

int main(void)
{
    run_tests();

    std::cout << "\n\nPlayers created: " << HLP2::IPlayer::PlayersCreated() << std::endl;
    std::cout << "Players active: " << HLP2::IPlayer::PlayersActive() << std::endl;

    return 0;
}
