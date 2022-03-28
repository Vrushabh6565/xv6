//mmap struct
struct mmapinfo {
  int used;			//check in use or not
  char* addr;       //address of page after mapping(start addr) 
  int length;		//size from offset
  int fd;			//to read from this file
  int offset;		//read or write to this offset in file
};

