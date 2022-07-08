#include "kmodulehelpers.h"
#include <gtest/gtest.h>

TEST(TEST_KMODHELPERS, LOAD_MODULE) {
    EXPECT_TRUE(loadKernelModule());
}

TEST(TEST_KMODHELPERS, LOAD_MODULE_WITH_CHECK) {
    loadKernelModule();
    EXPECT_TRUE(checkModuleLoaded());
}

TEST(TEST_KMODHELPERS, LOAD_REMOVE_MODULE_WITH_CHECK) {
    loadKernelModule();
    EXPECT_TRUE(removeKernelModule());
}

TEST(TEST_KMODHELPERS, LOAD_LOAD_REMOVE_MODULE_SEQUENCE) {
    removeKernelModule();

    EXPECT_TRUE(loadKernelModule());
    EXPECT_TRUE(checkModuleLoaded());
    EXPECT_TRUE(removeKernelModule());
    EXPECT_FALSE(checkModuleLoaded());

    EXPECT_TRUE(loadKernelModule());
    EXPECT_TRUE(checkModuleLoaded());
    EXPECT_TRUE(removeKernelModule());
    EXPECT_FALSE(checkModuleLoaded());
}
