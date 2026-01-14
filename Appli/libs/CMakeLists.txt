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
    stm32-mw-camera/sensors/cmw_vd55g1.c
    stm32-mw-camera/sensors/cmw_vd66gy.c

    stm32-mw-camera/sensors/imx335/imx335.c
    stm32-mw-camera/sensors/imx335/imx335_reg.c
    stm32-mw-camera/sensors/vd55g1/vd55g1.c
    stm32-mw-camera/sensors/vd55g1/vd55g1_patch_cut_1.c
    stm32-mw-camera/sensors/vd55g1/vd55g1_patch_cut_2.c
    stm32-mw-camera/sensors/vd6g/vd6g.c
    stm32-mw-camera/sensors/vd6g/vd6g_patch.c
    stm32-mw-camera/sensors/vd6g/vd6g_vtpatch.c
    )

target_include_directories(camera-mw PRIVATE
    stm32-mw-isp/isp/Inc
    stm32-mw-camera
    stm32-mw-camera/sensors
    stm32-mw-camera/sensors/imx335
    stm32-mw-camera/sensors/vd55g1
    stm32-mw-camera/sensors/vd6g
    )
