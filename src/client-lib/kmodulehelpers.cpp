#include "kmodulehelpers.h"
#include "kmodulelocation.h"
#include <stdio.h>
#include <string>

bool loadKernelModule()
{
    std::string cmd = std::string("insmod ") + std::string(CNC_KMOD) + std::string(" 2>&1");
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
    std::string cmd = std::string("rmmod ") + std::string(CNC_KMOD) + std::string(" 2>&1");
    FILE *fd = popen(cmd.c_str(), "r");
    char buf[256];
    return fread(buf, 1, sizeof(buf), fd) == 0;
}
