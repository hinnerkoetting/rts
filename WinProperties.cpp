
#include "WinProperties.h"
#include "Util.h"
#include "exception.h"
WinProperties::WinProperties(const std::string & rootparam) : root(rootparam)
{
}

WinProperties::~WinProperties()
{
}

std::string
WinProperties::loadProperty(const std::string& nspace, const std::string &key) const
{
		// erst Session Keys prüfen
	std::string newKey = nspace + "/" + key;
	
	std::map<std::string, std::string> ::const_iterator iter = propMap.find(newKey);

	if (propMap.end() != iter)
		return iter->second;

		// in Session nicht vorhanden -> aus Registry laden
	std::string completeKey = root;
	completeKey.append(nspace);

	HKEY hRegKey;
	LONG OpenRet = RegOpenKeyEx(HKEY_CURRENT_USER, completeKey.c_str(), 0, KEY_QUERY_VALUE, &hRegKey);

	if (OpenRet != ERROR_SUCCESS)
	{
		std::string ErrorMessage("WinProperties:loadProperty: Unknown root or namespace (\"");
		ErrorMessage = ErrorMessage + completeKey;
		ErrorMessage = ErrorMessage +  "\"). Win32ErrorCode: ";
		
		ErrorMessage = ErrorMessage + IntegerToString(OpenRet);
		throw GeneralGameException(ErrorMessage);
	}

		// Zunächst nur die Länge des String herausfinden
	DWORD KeyLen;
	LONG QueryRet = RegQueryValueEx(hRegKey, key.c_str(), NULL, NULL, NULL, &KeyLen);

	if (QueryRet != ERROR_SUCCESS)
	{
		std::string ErrorMessage("WinProperties::loadProperty: Failed to open key '");
		
		ErrorMessage = ErrorMessage + key + "'. Win32ErrorCode: "  + IntegerToString(QueryRet);
		RegCloseKey(hRegKey);
		throw GeneralGameException(ErrorMessage);
	}

	KeyLen += sizeof(TCHAR);	// für ein Nullzeichen

	TCHAR* buffer = new TCHAR[KeyLen / sizeof(TCHAR)];

	if (!buffer)
	{
		RegCloseKey(hRegKey);
		throw GeneralGameException("WinProperties::loadProperty: Not enough memory to get value.");
	}

	QueryRet = RegQueryValueEx(hRegKey, key.c_str(), NULL, NULL, (LPBYTE)buffer, &KeyLen);

	RegCloseKey(hRegKey);

	if (QueryRet != ERROR_SUCCESS)
	{
		std::string ErrorMessage("WinProperties::loadProperty: Failed to get value. Win32ErrorCode: ");
		ErrorMessage = ErrorMessage + IntegerToString(QueryRet);
		throw GeneralGameException(ErrorMessage);
	}

	std::string value(buffer);
	delete [] buffer;

	return value;
}

void
WinProperties::saveProperty(const std::string& nspace, const std::string& key, const std::string& value)
{
	std::string completeKey = root;
	completeKey.append(nspace);

	HKEY hRegKey;
	LONG OpenRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE, completeKey.c_str(), 0, KEY_SET_VALUE, &hRegKey);

	if (OpenRet != ERROR_SUCCESS)
	{
		std::string ErrorMessage("WinProperties:saveProperty: Unknown root or namespace. Win32ErrorCode: ");
		ErrorMessage = ErrorMessage + IntegerToString(OpenRet);
		throw GeneralGameException(ErrorMessage);
	}

	LONG SetRet = RegSetValueEx(hRegKey, key.c_str(), 0, REG_SZ, (CONST BYTE*)value.c_str(), (DWORD)(value.size() + 1) * sizeof(wchar_t));

	RegCloseKey(hRegKey);

	if (SetRet != ERROR_SUCCESS)
	{
		std::string ErrorMessage("WinProperties:saveProperty: Cannot write value. Win32ErrorCode: ");
		ErrorMessage = ErrorMessage + IntegerToString(SetRet);
		throw GeneralGameException(ErrorMessage);
	}
}

void
WinProperties::setSessionProperty(const std::string& nspace, const std::string& key, const std::string& value)
{
	std::string newKey = nspace + "/" + key;

	propMap[newKey] = value;
}

void
WinProperties::deleteProperty(const std::string& nspace, const std::string& key)
{
	std::string completeKey = root;
	completeKey.append(nspace);

	HKEY hRegKey;
	LONG OpenRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE, completeKey.c_str(), 0, KEY_SET_VALUE, &hRegKey);

	if (OpenRet != ERROR_SUCCESS)
	{
		throw GeneralGameException("WinProperties:deleteProperty: Unknown root or namespace.");
	}

		// Fehler interessieren nicht
	RegDeleteValue(hRegKey, key.c_str());

	RegCloseKey(hRegKey);
}
