
```
__        ___ _     _  ____                               
\ \      / (_) | __| |/ ___|__ _ _ __ ___   ___ _ __ __ _ 
 \ \ /\ / /| | |/ _` | |   / _` | '_ ` _ \ / _ \ '__/ _` |
  \ V  V / | | | (_| | |__| (_| | | | | | |  __/ | | (_| |
   \_/\_/  |_|_|\__,_|\____\__,_|_| |_| |_|\___|_|  \__,_|
```


```
 ____  _                 ____  _____ ____ 
|  _ \(_)___  ___ ___   |  _ \| ____/ ___|
| | | | / __|/ __/ _ \  | |_) |  _|| |    
| |_| | \__ \ (_| (_) | |  _ <| |__| |___ 
|____/|_|___/\___\___/  |_| \_\_____\____|
```
compiled file sizes 


* empty project, default settings:

```
arm-none-eabi-objcopy  -O binary disco-rec_Appli.elf  "disco-rec_Appli.bin"
   text	   data	    bss	    dec	    hex	filename
   3252	     20	   2604	   5876	   16f4	disco-rec_Appli.elf
```

* + csi, dcmipp, venc (h264 mode) enabled
```
arm-none-eabi-objcopy  -O binary disco-rec_Appli.elf  "disco-rec_Appli.bin"
   text	   data	    bss	    dec	    hex	filename
  21624	     20	   2620	  24264	   5ec8	disco-rec_Appli.elf
```

* + ai core support + xspi
```
arm-none-eabi-objcopy  -O binary disco-rec_Appli.elf  "disco-rec_Appli.bin"
   text	   data	    bss	    dec	    hex	filename
  50920	     20	   2972	  53912	   d298	disco-rec_Appli.elf
```


