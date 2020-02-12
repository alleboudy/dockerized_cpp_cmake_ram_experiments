// TestingMemoryLimits.cpp : Defines the entry point for the application.
//

#include "TestingMemoryLimits.h"

using namespace std;

int main()
{
	
	
	size_t  max_size_phy_mem_mb = atoll(AVAILABLE_PHY_MEM_MB) / (616.0f/1024/1024);
	std::cout << "avaialble phy memory: " << AVAILABLE_PHY_MEM_MB << " MB" << std::endl;
	std::cout << "assumed cache size: " << max_size_phy_mem_mb << std::endl;
	CustomLRUCache::LRUCache<std::string, std::vector<float>> cache{ max_size_phy_mem_mb };
	size_t ctr = 0;
	while (true) {
		ctr ++ ;
		cache.put("key: " + std::to_string(ctr), std::vector<float>(124, 0.654689));
		if (cache.size()== max_size_phy_mem_mb)
		{
			std::cout << "reached size: "<< max_size_phy_mem_mb << endl;
		}
	}



	return 0;
}
