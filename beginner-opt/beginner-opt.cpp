// This file is the entry point for the compiler.
#include <iostream>

#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Error.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/raw_ostream.h"

#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/Parser/Parser.h"
#include "mlir/InitAllDialects.h"

//Self define Dialect
#include "beginner_mlir/Dialect/Helloworld/IR/HelloworldDialect.h"

namespace cl = llvm::cl;
static cl::opt<std::string> inputFileName(cl::Positional,
                                          cl::desc("<input .mlir file>"),
                                          cl::init("-"),
                                          cl::value_desc("filename"));

int dumpMLIR() {
  // Show MLIR info.
  llvm::ErrorOr<std::unique_ptr<llvm::MemoryBuffer>> fileOrErr =
      llvm::MemoryBuffer::getFileOrSTDIN(inputFileName);
  if (std::error_code ec = fileOrErr.getError()) {
    llvm::errs() << "Can not open input file: " << ec.message() << "\n";
    return -1;
  }
  llvm::SourceMgr sourceMgr;
  mlir::MLIRContext context;
  context.getOrLoadDialect<beginner_mlir::helloworld::HelloworldDialect>();
  context.getOrLoadDialect<mlir::func::FuncDialect>();
  sourceMgr.AddNewSourceBuffer(std::move(*fileOrErr), llvm::SMLoc());
  mlir::OwningOpRef<mlir::ModuleOp> module =
      mlir::parseSourceFile<mlir::ModuleOp>(sourceMgr, &context);
  if (!module) {
    llvm::errs() << "Error can't load file " << inputFileName << "\n";
    return -1;
  }
  module->dump();
  return 0;
}

int main(int argc, char **argv) {
  // Register command line options

  mlir::registerAsmPrinterCLOptions();
  mlir::registerMLIRContextCLOptions();
  cl::ParseCommandLineOptions(argc, argv, "Beginner Compiler\n");
  return dumpMLIR();
}
