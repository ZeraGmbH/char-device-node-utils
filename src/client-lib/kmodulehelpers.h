#ifndef KMODULEHELPERS_H
#define KMODULEHELPERS_H

namespace KModuleHelpers {

bool loadKernelModule();
bool removeKernelModule();
bool checkModuleLoaded();
bool checkCharDeviceInProcFiles();

}

#endif // KMODULEHELPERS_H
