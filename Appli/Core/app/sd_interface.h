#ifndef _SD_INTERFACE_H_
#define _SD_INTERFACE_H_


#define USE_FATFS 1
#define USE_FILEX 2

// choose filesystem here
#define USE_FS USE_FATFS

/**
 * Save a stream of data, buffer by buffer
 */
extern int save_stream(uint32_t * buf, size_t size);



#endif  /* _SD_INTERFACE_H_ */
