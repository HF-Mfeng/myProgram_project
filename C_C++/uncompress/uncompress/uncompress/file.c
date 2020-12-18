#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "zlib.h"
#pragma comment(lib,"./zlibwapi.lib")


// Demonstration of zlib utility functions
unsigned long file_size(char* filename)
{
    FILE* pFile = NULL;
    fopen_s(&pFile, filename, "rb");
    fseek(pFile, 0, SEEK_END);
    unsigned long size = ftell(pFile);
    fclose(pFile);
    return size;
}


int decompress_one_file(char* infilename, char* outfilename)
{

    int num_read = 0;
    char buffer[128] = { 0 };
    uLong destlen;
    char *dest;

    FILE *infile = NULL;
    fopen_s(&infile, infilename, "rb");
    FILE* outfile = NULL;
    fopen_s(&outfile, outfilename, "wb");

    if (!infile || !outfile) {
        return -1;
    }

    while ((num_read = fread(buffer, sizeof(char), 128, infile)) > 0) {
        destlen = 1280 * sizeof(char);
        dest = (char*)malloc(1280*sizeof(char));
        uncompress(dest ,&destlen, buffer, sizeof(buffer));
        fwrite(dest, 1, destlen, outfile);
        memset(buffer, 0, 128);
    }
    gzclose(infile);
    fclose(outfile);
    return 0;
}


int compress_one_file(char* infilename, char* outfilename)
{
    int num_read = 0;
    char inbuffer[128] = { 0 };
    char *destbuff;
    uLong destnum;
    unsigned long total_read = 0, total_wrote = 0;
    FILE* infile = NULL;
    fopen_s(&infile, infilename, "rb");
 //   gzFile outfile = gzopen(outfilename, "wb");
    FILE* outfile = NULL;
    fopen_s(&outfile, outfilename, "wb");
    if (!infile || !outfile) {
        return -1;
    }

    while ((num_read = fread(inbuffer, 1, sizeof(inbuffer), infile)) > 0) {
        destnum = compressBound(sizeof(inbuffer));
        destbuff = (char*)malloc(destnum);
        total_read += num_read;
        compress(destbuff, &destnum, inbuffer, num_read);
      //  gzwrite(outfile, destbuff, destnum);
        fwrite(destbuff, sizeof(char), destnum, outfile);
        memset(inbuffer, 0, 128);
        free(destbuff);
    }
    fclose(infile);
    gzclose(outfile);
    //printf("Read %ld bytes, Wrote %ld bytes,"
    //    "Compression factor %4.2f%%\n",
    //    total_read, file_size(outfilename),
    //    (1.0 - file_size(outfilename) * 1.0 / total_read) * 100.0);
    return 0;
}

void compressMyfile(char* infileName, char* outfileName) {
    
    FILE* infile = NULL;
    FILE* outfile = NULL;
    fopen_s(&infile, infileName, "rb");
    fopen_s(&outfile, outfileName, "wb");
    uLong infileSize = file_size(infileName);
    Byte* infileByte = (Byte*)malloc(infileSize);
    fread(infileByte, 1, infileSize, infile);
    uLong outfileSize = compressBound(infileSize);
    Byte* outfileByte = (Byte*)malloc(outfileSize);
    compress(outfileByte, &outfileSize, infileByte, infileSize);
    fwrite(outfileByte, 1, outfileSize, outfile);
    fclose(infile);
    fclose(outfile);

}

void uncompressMyfile(char* infileName, char* outfileName) {

    FILE* infile = NULL;
    FILE* outfile = NULL;
    fopen_s(&infile, infileName, "rb");
    fopen_s(&outfile, outfileName, "wb");
    uLong infileSize = file_size(infileName);
    Byte* infileByte = (Byte*)malloc(infileSize);
    fread(infileByte, 1, infileSize, infile);

    uLong outfileSize = 11*infileSize;
    Byte* outfileByte = (Byte*)malloc(outfileSize);
    uncompress(outfileByte, &outfileSize, infileByte, infileSize);
    fwrite(outfileByte, 1, outfileSize, outfile);
    fclose(infile);
    fclose(outfile);

}

int main(int argc, char** argv)
{
    //compress_one_file(argv[1], argv[2]);
  // decompress_one_file(argv[1],argv[2]);
//    compressMyfile(argv[1], argv[2]);
//    uncompressMyfile(argv[1], argv[2]);
    uLong num = 0;
    memset(&num, 255, sizeof(uLong));
    printf("%x", num-1);
    return 0;
}