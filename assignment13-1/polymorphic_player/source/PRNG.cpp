namespace HLP2
{

    static unsigned int SeedX = 521288629;
    static unsigned int SeedY = 362436069;

    unsigned rand()
    {
        constexpr unsigned int XSCALE = 18000;
        constexpr unsigned int YSCALE = 30903;

        SeedX = XSCALE * (SeedX & 65535U) + (SeedX >> 16U);
        SeedY = YSCALE * (SeedY & 65535U) + (SeedY >> 16U);

        return ((SeedX << 16U) + (SeedY & 65535U));
    }

    void srand(unsigned seed1, unsigned seed2)
    {
        if (seed1 != 0U)
        {
            SeedX = seed1;
        }
        if (seed2 != 0U)
        {
            SeedY = seed2;
        }
    }

    int random(int low, int high)
    {
        int r1 = static_cast<int>(HLP2::rand() / 2 - 1);
        return r1 % (high - low + 1) + low;
    }

}
