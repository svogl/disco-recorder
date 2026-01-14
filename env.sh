# shortcuts to get cross tools into the path

export PATH=$PATH:/opt/st/stm32cubeide_2.0.0/plugins/com.st.stm32cube.ide.mcu.externaltools.stlink-gdb-server.linux64_2.2.300.202509021040/tools/bin/
export PATH=$PATH:/opt/st/stm32cubeide_2.0.0/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.13.3.rel1.linux64_1.0.100.202509120712/tools/bin/

export PATH=$PATH:/opt/st/stm32cubeide_2.0.0/plugins/com.st.stm32cube.ide.mcu.externaltools.cubeprogrammer.linux64_2.2.300.202508131133/tools/bin/

# stedgeai:
# for version 1.1.3.4
export PATH=$PATH:/opt/st/STEdgeAI/3.0/Utilities/linux
# for version 1.1.1.4
export PATH=/opt/st/STEdgeAI/2.2/Utilities/linux:$PATH


export CUBEPROG=/opt/st/stm32cubeide_2.0.0/plugins/com.st.stm32cube.ide.mcu.externaltools.cubeprogrammer.linux64_2.2.300.202508131133/tools/bin/

export LOCALCP=/usr/local/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin/

export DKEL=/opt/st/stm32cubeide_2.0.0/plugins/com.st.stm32cube.ide.mcu.externaltools.cubeprogrammer.linux64_2.2.300.202508131133/tools/bin/ExternalLoader/MX66UW1G45G_STM32N6570-DK.stldr 

# while true ; do  ST-LINK_gdbserver  -p 61234 -l 1 -d -s -cp $CUBEPROG -m 1 -g ; sleep 1 ; done

