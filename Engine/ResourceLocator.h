#pragma once
#include <string>

std::string GetResource(std::string resourceName) {
	return "Resource Files\\" + resourceName;
}