#pragma once

namespace NComputerScience
{
    inline struct SComputerScience
    {
        std::vector<std::int32_t> IInitiate(std::vector<std::int32_t> const& AArray , std::int32_t const& AIndex)
        {
            std::vector<std::int32_t> LArray{AArray};
            if(LArray.empty())
            {
                return(LArray);
            }
            for(std::int64_t LRotation{1} ; LRotation <= AIndex  ; LRotation++)
            {
                std::int32_t LBuffer{LArray[std::ssize(LArray) - 1]};
                for(std::int64_t LIndex{std::ssize(LArray) - 1} ; LIndex >= 1  ; LIndex--)
                {
                    std::swap(LArray[LIndex] , LArray[LIndex - 1]);
                }
                LArray[0] = LBuffer;
            }
            return(LArray);
        }
    }
    GComputerScience;
}

std::int32_t main()
{
    std::ranges::for_each(NComputerScience::GComputerScience.IInitiate() , [&](std::int32_t const& AValue){std::cout << AValue << " ";});
    std::cout << "\n";
    std::system("Pause");
    return(0);
}