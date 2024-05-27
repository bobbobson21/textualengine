#pragma once

#include <String>
#include <Vector>

namespace strp
{
	static inline std::string FindReplace( std::string ReplaceIn, std::string Find, std::string ReplaceString) //makes replacment a lot easier as it can replace by sub string not posistion
	{
		int FindLen = Find.length();
		while (ReplaceIn.find( Find ) != std::string::npos)
		{
			ReplaceIn = ReplaceIn.replace(ReplaceIn.find(Find), FindLen, ReplaceString);
		}
		return ReplaceIn;
	}

	static inline std::string StringToLower(std::string string)
	{
		for (int i = 0; i < string.length(); i++) { string[i] = tolower(string[i]); }
		return string;
	}

	static inline std::string StringToUpper(std::string string)
	{
		for (int i = 0; i < string.length(); i++) { string[i] = toupper(string[i]); }
		return string;
	}

	static std::vector<std::string> SplitString( std::string ToSplit, std::string SplitBy = "|") //this dose not serve a puopuse anymore but I keep it just incase
	{
		ToSplit = ToSplit + SplitBy;  //it splits a string up by a charter btw
		std::vector<std::string> Output;
		while (ToSplit.find(SplitBy) != std::string::npos)
		{
			Output.push_back(ToSplit.substr(0, ToSplit.find(SplitBy)));
			ToSplit = ToSplit.substr(ToSplit.find(SplitBy) +1, ToSplit.length());
		}
		return Output;
	}
}
