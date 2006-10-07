
#ifndef WINPROPERTIES_H
#define WINPROPERTIES_H

#include <windows.h>
#include "Properties.h"
#include <map>
#include <string>

class WinProperties : public Properties
{
public:
		// es wird der Wurzelpfad in der Registry übergeben
	WinProperties(const std::string& root);
	~WinProperties();

	virtual std::string loadProperty(const std::string& nspace, const std::string& key) const;
	virtual void saveProperty(const std::string& nspace, const std::string& key, const std::string& value);
	virtual void deleteProperty(const std::string& nspace, const std::string& key);

	virtual void setSessionProperty(const std::string& nspace, const std::string& key, const std::string& value);
protected:
	std::string root;
	std::map<std::string, std::string> propMap;
};

#endif 