#include <yaml-cpp/yaml.h>
#include "playerconfig.hpp"

PlayerConfig::PlayerConfig(const std::string & configPath) 
    : yamlNode(YAML::LoadFile(configPath)) {
}

double PlayerConfig::getAttribute(const std::string & name) {
    return this->yamlNode["attributes"][name].as<double>();
}
