#pragma once

#include <map>
#include <string>

namespace Rowan
{
	//helper function to find unoccupied key in a map
	std::string FindUnoccupiedKey(const std::map<std::string, bool>& map, std::string start)
	{
		//if (start < 1) start = 1; // 0 is undef state
		while (map.find(start) == map.cend())
		{
			start += "1";
		}
		return start;
	}
	//by looping through map to find unused key number always has to be 1 or more
	template <typename TKey, typename TVal>
	TKey FindUnoccupiedKey(const std::map<TKey, TVal>& map, TKey start)
	{
		if (start < 1) start = 1; // 0 is undef state
		while (map.find(start) != map.cend()) ++start;
		return start;
	}

	//type aliases
	using stateID = size_t;
	using transID = size_t;

	// entry/undef state
	constexpr stateID undefState = 0;
	constexpr transID undefTrans = 0;
}