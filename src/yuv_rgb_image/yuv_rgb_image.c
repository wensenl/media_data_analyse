
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "global_macro.h"
#include "yuv_rgb_image.h"


int yuv420_split(char *filename, int w, int h)
{
	FILE *inFile = NULL;
	unsigned char *inImage = NULL;
	
	FILE *outFileY = NULL;
	char outFileYName[128] = {0};

	FILE *outFileU = NULL;
	char outFileUName[128] = {0};

	FILE *outFileV = NULL;
	char outFileVName[128] = {0};

	if(!filename){
		EOUT("input filename is null\n");
		return -1;
	}

	memset(outFileYName, 0, sizeof(outFileYName));
	strcpy(outFileYName, filename);
	strcat(outFileYName, "_y.y");

	memset(outFileUName, 0, sizeof(outFileUName));
	strcpy(outFileUName, filename);
	strcat(outFileUName, "_u.u");

	memset(outFileVName, 0, sizeof(outFileVName));
	strcpy(outFileVName, filename);
	strcat(outFileVName, "_v.v");

	DOUT("infile:%s, y:%s, u:%s, v:%s\n", filename, outFileYName, outFileUName, outFileVName);

	inImage = (unsigned char *)malloc(w*h*3/2);
	if(!inImage){
		EOUT("malloc buffer error\n");
		return -1;
	}
	inFile = fopen(filename, "rb+");
	if(!inFile) {
		EOUT("open file %s error\n", filename);
		goto err;
	}
	fread(inImage, 1, w*h*3/2, inFile);
	fclose(inFile);

	outFileY = fopen(outFileYName, "wb+");
	if(!outFileY) {
		EOUT("open file %s error\n", outFileYName);
		goto err;
	}
	outFileU = fopen(outFileUName, "wb+");
	if(!outFileU) {
		EOUT("open file %s error\n", outFileUName);
		goto err;
	}
	outFileV = fopen(outFileVName, "wb+");
	if(!outFileV) {
		EOUT("open file %s error\n", outFileVName);
		goto err;
	}

	
	if(inImage){
		free(inImage);
		inImage = NULL;
	}

	if(outFileY){
		fclose(outFileY);
		outFileY = NULL;
	}

	if(outFileU){
		fclose(outFileU);
		outFileU = NULL;
	}

	if(outFileV){
		fclose(outFileV);
		outFileV = NULL;
	}

	return 0;

err:
	if(inImage){
		free(inImage);
		inImage = NULL;
	}

	if(outFileY){
		fclose(outFileY);
		outFileY = NULL;
	}

	if(outFileU){
		fclose(outFileU);
		outFileU = NULL;
	}

	if(outFileV){
		fclose(outFileV);
		outFileV = NULL;
	}

	return -1;
}
