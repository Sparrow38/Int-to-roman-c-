#include <iostream>
#include <string>
#include <map>

std::string solution(int number) {

	std::map<int, std::string> m = { {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, 
		{100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5,"V"}, {4,"IV"}, {1,"I"}};
	std::string ans;
	for (std::map<int, std::string> it = m.rbegin(); it != m.rend(); it++)
	{
			if (number >= it->first)
			{
				int M = number / it->first;
				
				for (int i = 0; i < M; i++)
				{
					ans += it->second;
					number %= it->first;
				}
			}
			if (number == 0) { break; }
	}
	return ans;
}

int main(int argc, char* argv[])
{
	//cout << solution(1000);
	std::cout << solution(182) << std::endl; // "CLXXXII"));
	std::cout << solution(1990) << std::endl;// Equals("MCMXC"));
	std::cout << solution(1875);// Equals("MDCCCLXXV"));
}
