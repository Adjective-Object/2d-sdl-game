#include <yaml-cpp/yaml.h>
#include "playerconfig.hpp"

PlayerConfig::PlayerConfig(std::string & configPath) 
    : yamlNode(YAML::LoadFile(configPath)) {
}

double PlayerConfig::getAttribute(std::string & name) {
    return this->yamlNode["attributes"][name].as<double>();
}
