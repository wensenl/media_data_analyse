

#ifndef _yuv_rgb_image_h
#define _yuv_rgb_image_h


/*
*函数说明：
*		将YUV420P数据中的Y、U、V三个分量分离开来并保存成三个文件
*输入参数：
*		filename：YUV420P
*/
int yuv420_split(char *filename, int w, int h);


#endif
