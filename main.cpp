#include <ElfHeader.h>
#include <ObjectFileType.h>
#include <fstream>

void print_elf_header(const ElfDump::ElfHeader &header) {
  if (header.is32Bit()) {
    std::cout << "32-bit ";
  } else {
    std::cout << "64-bit ";
  }

  switch (header.type()) {
  case ElfDump::ObjectFileType::Relocatable:
    std::cout << "Relocatable";
    break;

  case ElfDump::ObjectFileType::Executable:
    std::cout << "Executable";
    break;

  case ElfDump::ObjectFileType::Shared:
    std::cout << "Shared";
    break;

  case ElfDump::ObjectFileType::Core:
    std::cout << "Core";
    break;

  default:
    std::cout << "Type is not currently supported: " << header.type();
  }

  std::cout << "\n";
}

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Missing path to ELF file\n";
    return 1;
  }

  std::ifstream f(argv[1], std::ios::binary);
  if (!f.is_open()) {
    std::cout << "Unable to open file " << argv[1] << "\n";
    return 1;
  }

  try {
    ElfDump::ElfHeader header(f);
    print_elf_header(header);
  } catch (std::runtime_error e) {
    std::cout << e.what() << "\n";
  }

  return 0;
}
