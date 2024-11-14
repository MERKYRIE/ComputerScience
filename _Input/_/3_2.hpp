#pragma once

namespace NComputerScience
{
    inline struct SComputerScience
    {
        std::int32_t IInitiate(std::vector<std::int32_t> const& AArray)
        {
            std::vector<bool> LValues;
            LValues.resize(std::ssize(AArray) + 1);
            for(std::int32_t const& LValue : AArray)
            {
                LValues[LValue - 1] = true;   
            }
            return(std::ranges::find(LValues , false) - LValues.begin() + 1);
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