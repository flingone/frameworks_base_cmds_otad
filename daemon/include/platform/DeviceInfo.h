#ifndef _DEVICE_INFO_H_
#define _DEVICE_INFO_H_

#include <string>
#include "PropertyManager.h"
#include "json/json.h"

#define KEY_SERIAL_NUMBER 		"serial_number"
#define KEY_PRODUCT_NAME 		"product_name"
#define KEY_MANUFACTURER 		"manufacturer"
#define KEY_HARDWARE_VERSION 	"hardware_version"
#define KEY_VERSION 			"version"
#define KEY_MAC_ADDRESS 		"mac"
#define KEY_IP_ADDRESS 			"ip"
#define KEY_PLATFORM			"platform"

class DeviceInfo {
public:
	DeviceInfo();
	virtual ~DeviceInfo();
	std::string Dump2JsonStr(); //dump the object to an json object string
	Json::Value GetJsonValue();
	bool LoadFromProperty(); //load info from system
	bool LoadFromString(std::string info);

	/*getter method*/
	std::string GetDeviceId();
	std::string GetProductName();
	std::string GetManufacturer();
	std::string GetHardwareVersion();
	std::string GetVersion();
	std::string GetMacAddress();
//	std::string GetIpAddress();
	std::string GetPlatform();

	void Log();

private:
	std::string m_szDeviceId;
	std::string m_szProductName;
	std::string m_szManufacturer;
	std::string m_szHardwareVersion;
	std::string m_szVersion;
	std::string m_szMacAddress;
//	std::string m_szIpAddress;
	std::string m_szPlatform;

	PropertyManager m_PropertyManager;
	Json::Value m_jsonInfo;
};

#endif
