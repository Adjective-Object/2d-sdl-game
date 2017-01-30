#ifndef __PLAYER_CONFIG
#define __PLAYER_CONFIG

#include <yaml-cpp/yaml.h>

class PlayerConfig {
    YAML::Node yamlNode;
public:
    PlayerConfig(const std::string & configPath);
    double getAttribute(const std::string & name);
};

#endif
