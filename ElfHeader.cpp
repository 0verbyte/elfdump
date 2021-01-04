#include <ElfHeader.h>
#include <stdexcept>

using namespace ElfDump;

ElfHeader::ElfHeader(std::ifstream &f) {
  // Identification.
  f.read(reinterpret_cast<char *>(e_ident), sizeof(e_ident));

  if (e_ident[0] != 0x7f || memcmp(e_ident + 1, "ELF", 3) != 0) {
    throw std::runtime_error("Magic numbers were not set or correct");
  }

  // Class architecture.
  if (e_ident[EI_CLASS] == 0 ||
      (e_ident[EI_CLASS] != 1 && e_ident[EI_CLASS] != 2)) {
    throw std::runtime_error("Invalid class architecture");
  }

  // Object file type.
  f.read(reinterpret_cast<char *>(&e_type), sizeof(e_type));
}

bool ElfHeader::is32Bit() const { return e_ident[EI_CLASS] == 1; }

bool ElfHeader::is64Bit() const {
  // Assume 64-bit if not 32-bit since other class architectures are already
  // handled
  return !is32Bit();
}

unsigned short int ElfHeader::type() const { return e_type; }