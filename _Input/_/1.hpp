#pragma once

namespace NComputerScience
{
    inline struct SComputerScience
    {
        std::int32_t IInitiate(std::int32_t const& AValue)
        {
            bool LOne{false};
            std::int32_t LGap{0};
            std::int32_t LMaximum{0};
            for(std::int32_t LBit{0} ; LBit <= 31 ; LBit++)
            {
                if(AValue & (1 << LBit))
                {
                    if(!LOne)
                    {
                        LOne = true;
                    }
                    else
                    {
                        if(LGap > LMaximum)
                        {
                            LMaximum = LGap;
                        }
                        LGap = 0;
                    }
                }
                else
                {
                    if(LOne)
                    {
                        LGap++;
                    }
                }
            }
            return(LMaximum);
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