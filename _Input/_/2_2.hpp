#pragma once

namespace NComputerScience
{
    inline struct SComputerScience
    {
        std::int32_t IInitiate(std::vector<std::int32_t> const& AArray)
        {
            std::unordered_map<std::int32_t , std::int64_t> LCounters;
            for(std::int64_t LIndex{0} ; LIndex <= std::ssize(AArray) - 1 ; LIndex++)
            {
                LCounters[AArray[LIndex]]++;
            }
            return(std::ranges::find_if(LCounters , [&](std::pair<std::int32_t , std::int64_t> const& APair)->bool{return(APair.second & 1);})->first);
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