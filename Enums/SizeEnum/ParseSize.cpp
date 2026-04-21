#include "SizeEnum.h"
#include "../../Exceptions/SizeExeption/SizeException.h"

inline Size ParseSize(const std::string& size) {
	if (size == "small") return Size::SMALL;
	if (size == "medium") return Size::MEDIUM;
	if (size == "large") return Size::LARGE;
	throw SizeException(size);

}