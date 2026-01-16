#include <stdio.h>
#include <stddef.h>
#include <stdint.h> 

#include "sd_interface.h"

#if USE_FS == USE_FATFS
#include "ff.h"

// file saving code:
int fileCounter=1234;
FIL vid;
int nextFileId() {
	// todo: count # files in directory&set
	fileCounter++;
	return fileCounter;
}

int openFile(int id) {
	char name[40];
	sprintf(name, "test-%d.mp4",id);
	int res = f_open(&vid, name, FA_WRITE | FA_CREATE_ALWAYS);
	return res;
}
int closeFile() {
	f_close(&vid);
}

// save function as called from the venc block
int save_stream( uint32_t * buf, size_t size)
{
	size_t written;
    int res = f_write(&vid, buf, size, &written);
    if (res)
    	return res;
    printf("wrote %d\r\n", written);
    return (written == size) ? 0 : FR_INT_ERR;
}
#elif USE_FS == USE_FILEX

#error TODO: FileX save_stream not implemented

#else

int save_stream( uint32_t * buf, size_t size)
{ 
    // never fail, return number of bytes "saved"
    printf("save %d\r\n", size);
    return size;
}

#endif
