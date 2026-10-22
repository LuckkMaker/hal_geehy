# Geehy G32 HAL/DAL 驱动库。
#
# 只编译 g32f463xx/drivers/src 下的源文件；设备头文件、DAL 配置
# （g32f463_dal_cfg.h）由板级提供（omni::hal_conf）。
#
# 结构同 hal_stm32：OBJECT 编源文件，INTERFACE 带 include 并导出对象。

add_library(omni_hal_geehy INTERFACE)

add_library(omni_hal_g32f463xx_objs OBJECT)
file(GLOB _sources CONFIGURE_DEPENDS
    "${OMNI_HAL_GEEHY_ROOT}/g32/g32f463xx/drivers/src/*.c")
list(FILTER _sources EXCLUDE REGEX "_template\\.c$")
target_sources(omni_hal_g32f463xx_objs PRIVATE ${_sources})

target_include_directories(omni_hal_g32f463xx_objs PRIVATE
    "${OMNI_HAL_GEEHY_ROOT}/g32/common/include"
    "${OMNI_HAL_GEEHY_ROOT}/g32/g32f463xx"
    "${OMNI_HAL_GEEHY_ROOT}/g32/g32f463xx/device/include"
    "${OMNI_HAL_GEEHY_ROOT}/g32/g32f463xx/drivers/include"
    "${OMNI_HAL_GEEHY_ROOT}/g32/g32f463xx/drivers/include/Legacy")
target_compile_definitions(omni_hal_g32f463xx_objs PRIVATE
    USE_DAL_DRIVER
    USE_FULL_DDL_DRIVER)
target_link_libraries(omni_hal_g32f463xx_objs PRIVATE
    omni::config omni::cmsis omni::hal_conf)
omni_apply_arch(omni_hal_g32f463xx_objs)
omni_apply_warnings(omni_hal_g32f463xx_objs)
# 厂商代码的告警不作为本项目的质量门槛。
target_compile_options(omni_hal_g32f463xx_objs PRIVATE
    -Wno-unused-but-set-variable
    -Wno-sometimes-uninitialized)

target_include_directories(omni_hal_geehy INTERFACE
    "${OMNI_HAL_GEEHY_ROOT}/g32/common/include"
    "${OMNI_HAL_GEEHY_ROOT}/g32/g32f463xx"
    "${OMNI_HAL_GEEHY_ROOT}/g32/g32f463xx/device/include"
    "${OMNI_HAL_GEEHY_ROOT}/g32/g32f463xx/drivers/include"
    "${OMNI_HAL_GEEHY_ROOT}/g32/g32f463xx/drivers/include/Legacy")
target_compile_definitions(omni_hal_geehy INTERFACE
    USE_DAL_DRIVER
    USE_FULL_DDL_DRIVER)
target_link_libraries(omni_hal_geehy INTERFACE
    omni::config omni::cmsis omni::hal_conf)
target_sources(omni_hal_geehy INTERFACE
    $<TARGET_OBJECTS:omni_hal_g32f463xx_objs>)
