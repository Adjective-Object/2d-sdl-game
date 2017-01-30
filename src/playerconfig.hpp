#ifndef __PLAYER_CONFIG
#define __PLAYER_CONFIG

#include <yaml-cpp/yaml.h>

class PlayerConfig {
    YAML::Node yamlNode;
public:
    PlayerConfig(std::string & configPath);
    double getAttribute(std::string & name);
};

#endif
