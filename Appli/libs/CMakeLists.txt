add_library(isp-mw
    stm32-mw-isp/isp/Src/isp_ae_algo.c
    stm32-mw-isp/isp/Src/isp_algo.c
    stm32-mw-isp/isp/Src/isp_awb_algo.c
    stm32-mw-isp/isp/Src/isp_cmd_parser.c
    stm32-mw-isp/isp/Src/isp_conf_template.c
    stm32-mw-isp/isp/Src/isp_core.c
    stm32-mw-isp/isp/Src/isp_services.c
    stm32-mw-isp/isp/Src/isp_tool_com.c
    )

target_include_directories(isp-mw PRIVATE
    stm32-mw-isp/isp/Inc
    )

add_library(camera-mw
    stm32-mw-camera/cmw_camera.c
    stm32-mw-camera/cmw_utils.c

    stm32-mw-camera/sensors/cmw_imx335.c
#    stm32-mw-camera/sensors/cmw_vd55g1.c
#    stm32-mw-camera/sensors/cmw_vd66gy.c

    stm32-mw-camera/sensors/imx335/imx335.c
    stm32-mw-camera/sensors/imx335/imx335_reg.c
    # stm32-mw-camera/sensors/vd55g1/vd55g1.c
    # stm32-mw-camera/sensors/vd55g1/vd55g1_patch_cut_1.c
    # stm32-mw-camera/sensors/vd55g1/vd55g1_patch_cut_2.c
    # stm32-mw-camera/sensors/vd6g/vd6g.c
    # stm32-mw-camera/sensors/vd6g/vd6g_patch.c
    # stm32-mw-camera/sensors/vd6g/vd6g_vtpatch.c
    )

target_include_directories(camera-mw PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32-mw-isp/isp/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32-mw-camera
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32-mw-camera/sensors
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32-mw-camera/sensors/imx335
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32-mw-camera/sensors/vd55g1
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32-mw-camera/sensors/vd6g
    )

add_library(venc
    stm32-mw-venc-ewl/ewl_impl.c
    VideoEncoder/source/h264/H264SequenceParameterSet.c
    VideoEncoder/source/h264/H264PictureBuffer.c
    VideoEncoder/source/h264/H264CodeFrame.c
    VideoEncoder/source/h264/H264Mad.c
    VideoEncoder/source/h264/H264Sei.c
    VideoEncoder/source/h264/H264NalUnit.c
    VideoEncoder/source/h264/H264PutBits.c
    VideoEncoder/source/h264/H264EncApi.c
    VideoEncoder/source/h264/H264Slice.c
    VideoEncoder/source/h264/H264TestId.c
    VideoEncoder/source/h264/H264RateControl.c
    VideoEncoder/source/h264/h264encapi_ext.c
    VideoEncoder/source/h264/H264Init.c
    VideoEncoder/source/h264/H264Denoise.c
    VideoEncoder/source/h264/H264PictureParameterSet.c
    VideoEncoder/source/h264/H264Cabac.c
    VideoEncoder/source/common/encasiccontroller_v2.c
    VideoEncoder/source/common/encswhwregisters.c
    VideoEncoder/source/common/encpreprocess.c
    VideoEncoder/source/common/encasiccontroller.c
    VideoEncoder/source/common/encInputLineBuffer.c
    )

target_include_directories(venc PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32-mw-venc-ewl
    ${CMAKE_CURRENT_SOURCE_DIR}/VideoEncoder/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/VideoEncoder/source/h264
    ${CMAKE_CURRENT_SOURCE_DIR}/VideoEncoder/source/common
    )

add_library(fatfs
    stm32-mw-fatfs/source/ff.c
    stm32-mw-fatfs/source/ffunicode.c
    stm32-mw-fatfs/source/ff_gen_drv.c
    stm32-mw-fatfs/source/ffsystem_template.c

    stm32-mw-fatfs/source/ffsystem_baremetal.c
#    stm32-mw-fatfs/source/drivers/usb_host/usbh_diskio.c
#    stm32-mw-fatfs/source/drivers/sram/sram_diskio.c
#    stm32-mw-fatfs/source/drivers/template/user_diskio.c
    stm32-mw-fatfs/source/drivers/sd/sd_diskio.c
#    stm32-mw-fatfs/source/drivers/sd/sd_diskio_dma_rtos.c
    stm32-mw-fatfs/source/drivers/sd/sd_diskio_dma_standalone.c
    stm32-mw-fatfs/source/ffsystem_cmsis_os.c
    stm32-mw-fatfs/source/diskio.c
    )

target_include_directories(fatfs PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../Core/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32-mw-fatfs/source
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32-mw-fatfs/source/drivers
    )