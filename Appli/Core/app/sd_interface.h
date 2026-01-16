#ifndef _SD_INTERFACE_H_
#define _SD_INTERFACE_H_

#define USE_FATFS 1

/**
 * Save a stream of data, buffer by buffer
 */
extern int save_stream(uint32_t * buf, size_t size);



#endif  /* _SD_INTERFACE_H_ */
