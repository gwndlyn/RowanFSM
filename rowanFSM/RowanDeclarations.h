#pragma once

#include <map>
#include <string>
#include <iostream>

namespace Rowan
{
	////helper function to find unoccupied key in a map
	//std::string FindUnoccupiedKey(const std::map<std::string, bool>& map, std::string start)
	//{
	//	//if (start < 1) start = 1; // 0 is undef state
	//	while (map.find(start) == map.cend())
	//	{
	//		start += "1";
	//	}
	//	return start;
	//}
	

	//by looping through map to find unused key number always has to be 1 or more
	template <typename TKey, typename TVal>
	inline TKey FindUnoccupiedKey(const std::map<TKey, TVal>& map, TKey start)
	{
		std::cout << __FUNCTION__ << std::endl;
		if (start < 1) start = 1; // 0 is undef state
		while (map.find(start) != map.cend()) ++start;
		return start;
	}

	//helper function to find unoccupied key in a map
	template <>
	inline std::string FindUnoccupiedKey<std::string, bool>(const std::map<std::string, bool>& map, std::string start)
	{
		//if (start < 1) start = 1; // 0 is undef state
		//std::cout << __FUNCTION__ << std::endl;
		std::string temp = start;
		unsigned int cnt = 1;
		while (map.find(temp) != map.cend())
		{
			temp = start + std::to_string(cnt++);
		}
		return temp;
	}

	//type aliases
	using stateID = size_t;
	using transID = size_t;

	// entry/undef state
	constexpr stateID undefState = 0;
	constexpr transID undefTrans = 0;
}