
#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <string>


class Properties
{
public:
	virtual std::string loadProperty(const std::string& nspace, const std::string& key) const = 0;
	virtual void saveProperty(const std::string& nspace, const std::string& key, const std::string& value) = 0;
	virtual void deleteProperty(const std::string& nspace, const std::string& key) = 0;

		// Session Properties sind nur für die Session gültig, dafür überdecken sie normale Properties
	virtual void setSessionProperty(const std::string& nspace, const std::string& key, const std::string& value) = 0;
};

#endif