#include "kmodulehelpers.h"
#include "kmodulelocation.h"
#include "globals.h"
#include <stdio.h>
#include <string>

namespace KModuleHelpers {

bool loadKernelModule()
{
    std::string cmd = std::string("insmod ") + std::string(CNC_KMODULE_PATH) + std::string(" 2>&1");
    FILE *fd = popen(cmd.c_str(), "r");
    char buf[256];
    return fread(buf, 1, sizeof(buf), fd) == 0;
}

bool checkModuleLoaded()
{
    FILE *fd = popen("lsmod | grep char_node_creator", "r");
    char buf[256];
    return fread(buf, 1, sizeof(buf), fd) > 0;
}

bool removeKernelModule()
{
    std::string cmd = std::string("rmmod ") + std::string(CNC_KMODULE_PATH) + std::string(" 2>&1");
    FILE *fd = popen(cmd.c_str(), "r");
    char buf[256];
    return fread(buf, 1, sizeof(buf), fd) == 0;
}

bool checkCharDeviceInProcFiles()
{
    std::string cmd = std::string("cat /proc/devices | grep ") + std::string(CNC_NAME) + std::string(" 2>&1");
    FILE *fd = popen(cmd.c_str(), "r");
    char buf[256];
    return fread(buf, 1, sizeof(buf), fd) > 0;
}

}
