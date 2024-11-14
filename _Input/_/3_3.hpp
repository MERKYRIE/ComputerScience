#pragma once

namespace NComputerScience
{
    inline struct SComputerScience
    {
        std::int32_t IInitiate(std::vector<std::int32_t> const& AArray)
        {
            std::int32_t LBest{std::numeric_limits<std::int32_t>::max()};
            std::int32_t LLeft{0};
            std::int32_t LRight{std::accumulate(AArray.begin() , AArray.end() , 0)};
            for(std::int64_t LIndex{0} ; LIndex < std::ssize(AArray) - 1 ; LIndex++)
            {
                LLeft += AArray[LIndex];
                LRight -= AArray[LIndex];
                LBest = std::min(LBest , std::abs(LLeft - LRight));
            }
            return(LBest);
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