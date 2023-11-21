#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "bf.h"
#include "hash_file.h"
#define MAX_OPEN_FILES 20
#define HP_ERROR -1 

#define CALL_BF(call)       \
{                           \
  BF_ErrorCode code = call; \
  if (code != BF_OK) {         \
    BF_PrintError(code);    \
    return HP_ERROR;        \
  }                         \
}



typedef struct{
  int global_depth;
  int file_desc;
  BF_Block** hash_table;
}Index_info;


// typedef struct{
//   int size;
//   int empty[MAX_OPEN_FILES];
//   Index_info* open_files; //open files array
// }Shared_data;


HT_ErrorCode HT_Init() {
  //insert code here
  
  return HT_OK;
}

Index_info* Array[MAX_OPEN_FILES];

HT_ErrorCode HT_CreateIndex(const char *filename, int depth) {
  //insert code here
  int filedesc;
  void* data;
  BF_Block* block;
  Index_info info;
  Index_info* pinfo = &info;

  CALL_BF( BF_CreateFile(filename));
  CALL_BF( BF_OpenFile(filename , &filedesc));

  BF_Block_Init(&block);
  CALL_BF( BF_AllocateBlock(filedesc , block));
  
  data = BF_Block_GetData(block);
  pinfo = data; 
  pinfo->global_depth = depth;
  pinfo->file_desc = filedesc;

  int power = pow(2,depth);
  pinfo->hash_table = malloc(power*sizeof(BF_Block*));

  BF_Block_Destroy(&block);
  BF_CloseFile(filedesc);

  return HT_OK;
}


HT_ErrorCode HT_OpenIndex(const char *fileName, int *indexDesc){
  //insert code here
  int file_desc;
  void* data;
  BF_Block* block;
  Index_info* info;

  CALL_BF( BF_OpenFile(fileName,&file_desc));
  BF_Block_Init(&block);
  CALL_BF(BF_GetBlock(file_desc, 0, block));
  data = BF_Block_GetData(block);
  info = data;

  for( int i = 0 ; i < MAX_OPEN_FILES; i ++ ){
    
    if(Array[i] == NULL){
      Array[i] = info;
      *indexDesc = i;
      BF_Block_Destroy(&block);
      printf("array %p\n",Array[i]);
      return HT_OK;
    }

  }
  return HT_ERROR;
}

HT_ErrorCode HT_CloseFile(int indexDesc) {
  //insert code here

  Index_info* index_info;
  index_info = Array[indexDesc];
  Array[indexDesc]=NULL;

  free(index_info->hash_table);

  BF_CloseFile(index_info->file_desc);
  return HT_OK;
}

HT_ErrorCode HT_InsertEntry(int indexDesc, Record record) {
  //insert code here
  return HT_OK;
}

HT_ErrorCode HT_PrintAllEntries(int indexDesc, int *id) {
  //insert code here
  return HT_OK;
}

