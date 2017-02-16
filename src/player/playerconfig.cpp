#include "playerconfig.hpp"
#include <yaml-cpp/yaml.h>

PlayerConfig::PlayerConfig(const std::string& configPath)
    : yamlNode(YAML::LoadFile(configPath)) {}

double PlayerConfig::getAttribute(const std::string& name) {
    return this->yamlNode["attributes"][name].as<double>();
}
