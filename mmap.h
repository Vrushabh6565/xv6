//mmap struct
struct mmapinfo {
  int valid;		//check in use or not
  int length;		//size from offset
  int fd;			//to read from this file
  int offset;		//read or write to this offset in file
};
