#pragma once

namespace NComputerScience
{
    inline struct SComputerScience
    {
        struct SNode
        {
            SNode* FParent;
            std::string FCity;
            std::vector<std::unique_ptr<SNode>> FChildren;
        };

        std::unordered_map<std::string , std::unordered_map<std::string , std::int64_t>> FMap;
        std::string FCity;
        
        void IInitiate(std::string const& ACity)
        {
            FMap["A"]["B"] = 2;
            FMap["A"]["C"] = 2;
            FMap["B"]["A"] = 2;
            FMap["B"]["C"] = 3;
            FMap["B"]["D"] = 3;
            FMap["B"]["E"] = 1;
            FMap["C"]["A"] = 2;
            FMap["C"]["B"] = 3;
            FMap["C"]["D"] = 1;
            FMap["C"]["E"] = 3;
            FMap["D"]["B"] = 3;
            FMap["D"]["C"] = 1;
            FMap["D"]["E"] = 3;
            FMap["E"]["B"] = 1;
            FMap["E"]["C"] = 3;
            FMap["E"]["D"] = 3;
            FCity = ACity;
            ITravel(std::make_unique<SNode>(nullptr , FCity).get());
        }

        void ITravel(SNode *const& ANode)
        {
            std::int64_t LDepth{0};
            for(SNode * LNode{ANode} ; LNode ; LNode = LNode->FParent)
            {
                LDepth++;
            }
            if(LDepth == 5)
            {
                if(std::ranges::any_of(FMap[ANode->FCity] , [&](std::pair<std::string , std::int64_t> const& ARoad)->bool{return(ARoad.first == FCity);}))
                {
                    std::int64_t LDistance{0};
                    std::vector<std::string> LPath;
                    for(SNode * LNode{ANode} ; LNode ; LNode = LNode->FParent)
                    {
                        LDistance += FMap[LNode->FParent ? LNode->FParent->FCity : FCity][LNode->FCity];
                        LPath.emplace_back(LNode->FCity);
                    }
                    std::ranges::for_each(LPath.rbegin() , LPath.rend() , [&](std::string const& ACity)->void{std::cout << ACity << " ";});
                    std::cout << FCity << " " << LDistance + FMap[FCity][ANode->FCity] << "\n";
                }
                return;
            }
            for(auto const& [LCity , LDistance] : FMap[ANode->FCity])
            {
                bool LVisit{false};
                for(SNode * LNode{ANode} ; LNode ; LNode = LNode->FParent)
                {
                    if(LNode->FCity == LCity)
                    {
                        LVisit = true;
                    }
                }
                if(!LVisit)
                {
                    ANode->FChildren.push_back(std::make_unique<SNode>(ANode , LCity));
                    ITravel(ANode->FChildren.back().get());
                }
            }
        }
    }
    GComputerScience;
}

std::int32_t main()
{
    NComputerScience::GComputerScience.IInitiate();
    std::system("Pause");
    return(0);
}