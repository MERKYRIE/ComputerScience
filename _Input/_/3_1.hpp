#pragma once

namespace NComputerScience
{
    inline struct SComputerScience
    {
        std::int32_t IInitiate(std::int32_t const& AA , std::int32_t const& AB , std::int32_t const& ADistance)
        {
            return(((AB - AA) / ADistance) + (((AB - AA) % ADistance) != 0));
        }
    }
    GComputerScience;
}

std::int32_t main()
{
    std::cout << NComputerScience::GComputerScience.IInitiate() << "\n";
    std::system("Pause");
    return(0);
}