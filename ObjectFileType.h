#ifndef OBJECT_FILE_TYPE
#define OBJECT_FILE_TYPE

namespace ElfDump {

// Object file types. TODO: add processor specific fields for:
// 0xff00 - ET_LOPROC
// 0xffff - ET_HIPROC
enum ObjectFileType {
  None,
  Relocatable,
  Executable,
  Shared,
  Core,
};
} // namespace ElfDump

#endif // OBJECT_FILE_TYPE
