#include "Person.h"
#include "Tweeter.h"
#include <memory>


int main()
{
    {
        Tweeter FunBird("Fun", "Fanny", 567, "@fannybord");
    }
    {
        Person Fun("Fun", "Fanny", 456);
    }
    {
        std::unique_ptr<Person> pPerson =
            std::make_unique<Tweeter>("Bill", "Grogan", 10, "@iheartgoat");
    }

    return 0;
}