#ifndef ELF_HEADER_H
#define ELF_HEADER_H

#include <ArchClass.h>
#include <ObjectFileType.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string.h>

namespace ElfDump {

class ElfHeader {

public:
  ElfHeader(){};
  ElfHeader(std::ifstream &f);

  bool is32Bit() const;
  bool is64Bit() const;
  ArchClass archClass() const;

  ObjectFileType type() const;

private:
  // Structure to hold the ELF initial bytes for identification.
  static const unsigned short EI_NIDENT = 16;
  unsigned char e_ident[EI_NIDENT];

  // Object file type.
  unsigned short int e_type;

  // Identification table indexes
  const int EI_CLASS = 4;
};
}; // namespace ElfDump

#endif // ELF_HEADER_H
