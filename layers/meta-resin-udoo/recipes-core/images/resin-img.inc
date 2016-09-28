#
# UDOO Quad
#

IMAGE_FSTYPES_append_udoo-quad = " resin-sdcard"

### TEST
# Customize resin-sdcard
RESIN_IMAGE_BOOTLOADER_udoo-quad = "u-boot"
RESIN_BOOT_PARTITION_FILES_vab820-quad = " \
    uImage-udoo-quad.bin:/uImage \
    uImage-imx6q-udoo.dtb:/imx6q-vab820.dtb \
"

### TEST
IMAGE_CMD_resin-sdcard_append_udoo-quad () {
    # udoo-quad needs uboot written at a specific location
    dd if=${DEPLOY_DIR_IMAGE}/u-boot-${MACHINE}.imx of=${RESIN_SDIMG} conv=notrunc seek=2 bs=512
}
