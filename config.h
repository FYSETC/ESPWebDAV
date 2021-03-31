#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <stdio.h>
#include <string.h>

#define WIFI_SSID_LEN 32
#define WIFI_PASSWD_LEN 64
#define HOSTNAME_LEN 32

#define EEPROM_SIZE 512

typedef struct config_type
{
  unsigned char flag; // Was saved before?
  char ssid[WIFI_SSID_LEN];
  char psw[WIFI_PASSWD_LEN];
  char _hostname[HOSTNAME_LEN];
}CONFIG_TYPE;

class Config	{
public:
  int loadSD();
	unsigned char load();
  char* ssid();
  void ssid(char* ssid);
  char* password();
  void password(char* password);
  char* hostname();
  void hostname(char* hostname);
  void save(const char*ssid,const char*password, const char* hostname);
  void save();
  int save_ip(const char *ip);

protected:
  CONFIG_TYPE data;
};

extern Config config;

#endif
